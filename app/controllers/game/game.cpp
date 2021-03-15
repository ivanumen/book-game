#include "game.h"
#include <cstdio>
#include <windows.h>
#include <memory>

#include "app/views/console_editor/console_editor.h"
#include "app/views/menu/menu.h"
#include "app/views/player/player_views.h"
#include "app/views/spells/spell_views.h"
#include "app/util/dice/dice.h"
#include "app/util/json/json.h"
#include "app/util/decoder/decoder.h"
#include "app/util/file_editor/file_editor.h"
#include "app/models/level/level.h"
#include "app/models/items/item.h"
#include "app/models/items/food.h"
#include "app/controllers/option/option_control.h"
#include "app/controllers/actions/action.h"
#include "app/controllers/actions/add_strength.h"


void TGame::Start() {
    ReadConfig();
    TMenu mainMenu({ "Новая игра", "Загрузка" ,"Настройки", "Эксит" }, TPoint(0, 0), TPoint(100, 10), { });
    int value = mainMenu.Show();
    if (value == 0) {
        New();
    }
}

void TGame::ReadConfig() {
    std::string configStr = NFileEditor::ReadFile("../config.json");
    NJson::TJsonValue config = NJson::TJsonValue::parse(NDecoder::ToUtf8(configStr));
    for (auto levelInfo : config) {
        std::vector<TOption> options;
        std::vector<std::shared_ptr<TAction>> actions;
        for (const auto& option : levelInfo["options"]) {
            std::vector<std::pair<std::string, std::string>> prices;
            if (option.find("price") != option.end()) {
                for (const auto& price : option["price"]) {
                    prices.emplace_back(NDecoder::FromUtf8(price["type"]), NDecoder::FromUtf8(price["value"]));
                }
            }
            options.emplace_back(option["to"], NDecoder::FromUtf8(option["text"]), prices);
        }
        if (levelInfo.find("actions") != levelInfo.end()) {
            for (const auto& action : levelInfo["actions"]) {
                std::shared_ptr<TAction> actionPtr;
                if (action["name"] == "add_strength") {
                    actionPtr = std::make_shared<TAddStrengthAction>(action["amount"]); //  new TAddStrengthAction(action["amount"]);
                }
                actions.emplace_back(actionPtr);
            }
        }
        TLevel level(NDecoder::FromUtf8(levelInfo["text"]), options, actions);
        Levels[levelInfo["id"]] = level;
    }
}

void TGame::InitPlayer() {
    std::string name;
    TItem* foodX3 = new TFood("food", "Еда", 3);
    std::cout << "Введите имя" << std::endl;
    std::cin >> name;
    Player.SetName(name);
    auto characteristics = Player.GetRandomCharacteristics();
    Player.SetStrength(std::get<0>(characteristics));
    Player.SetAgility(std::get<1>(characteristics));
    Player.SetMaxStrength(std::get<0>(characteristics));
    Player.SetMaxAgility(std::get<1>(characteristics));
    Player.SetCharisma(std::get<2>(characteristics));
    const auto resultDice1 = NDice::usingD6();
    const auto resultDice2 = NDice::usingD6();
    Player.LockLuck(resultDice1);
    Player.LockLuck(resultDice2);
    Player.SetGold(15);
    Player.SetFlask(2);
    Player.ResizeItems(7);
    Player.AddItem(0, foodX3);
    NPlayerView::WritePlayer(Player);
    InitSpells();
}


void TGame::New() {
    NConsoleEditor::Clear();
    InitPlayer();
    CurrentLevel = 1;
    Run();
}

int TGame::InitSpells() {
    std::vector<std::pair<std::string, int>> spells = {
        { "Заклятие левитации", 0},
        { "Заклятие Огня", 0 },
        { "Заклятие Иллюзии" , 0},
        { "Заклятие Ловкости", 0},
        { "Заклятие Слабости", 0},
        { "Заклятие Копии", 0},
        { "Заклятие Исцеления", 0},
        { "Заклятие Плавания",  0}
    };
    int chosenOption = 0;
    const int MaxCountSpells = 10;
    int countSpells = 0;
    while (1) {
        NConsoleEditor::Clear();
        std::cout << "Текущие количество заклинаний " << countSpells << std::endl;
        for (size_t i = 0; i < spells.size(); i++) {
            if (i == chosenOption) {
                NConsoleEditor::SetColor(NConsoleEditor::LightBlue);
                std::cout << spells[i].first << " " << spells[i].second << std::endl;
                NConsoleEditor::SetColor(NConsoleEditor::Yellow);
            }
            else {
                std::cout << spells[i].first << " " << spells[i].second << std::endl;
            }
        }
        int key = NConsoleEditor::Getch();
        if (spells[chosenOption].second > 0 && NConsoleEditor::IsLeft(key)) {
            countSpells--;
            spells[chosenOption].second--;
        }
        if (countSpells < MaxCountSpells && NConsoleEditor::IsRight(key)) {
            countSpells++;
            spells[chosenOption].second++;
        }
        if (chosenOption > 0 && NConsoleEditor::IsUp(key)) {
            chosenOption--;
        }
        if (chosenOption < static_cast<int>(spells.size()) - 1 && NConsoleEditor::IsDown(key)) {
            chosenOption++;
        }
        if (NConsoleEditor::IsEnter(key)) {
            if (countSpells == MaxCountSpells) {
                Player.SetSpells(spells);
                return chosenOption;
            }
            else {
                std::cout << "Наберите 10 заклинаний" << std::endl;
                NConsoleEditor::Getch();
            }
        }
    }
}

void TGame::Run() {
    while (1) {
        NConsoleEditor::Clear();
        auto level = Levels[CurrentLevel];
        std::vector<std::string> options;
        const auto& levelOptions = level.GetOptions();
        for (const auto& option : levelOptions) {
            if (option.CanBeChoosen(Player)) {
                options.push_back(option.Text);
            }
            else {
                options.push_back("<?????>");
            }
        }
        for (const auto& action : level.GetActions()) {
            action->Do(Player);
        }

        int option = -1;
        while (option == -1 || !levelOptions[option].CanBeChoosen(Player)) {
            NConsoleEditor::Clear();
            std::cout << "Нажмите I(ш) для вызова инвентаря" << " " << "Нажмите O(щ) для вызова окна характеристик" << " " << "Нажмите P(з) для вызова книги заклинаний" << std::endl;
            std::cout << std::endl;

            std::cout << level.GetText() << std::endl;
            TMenu menu(options, { 0, NConsoleEditor::GetCursorPosition().Y }, { 100, static_cast<int>(options.size()) }, { NConsoleEditor::IKey, NConsoleEditor::OKey, NConsoleEditor::PKey, NConsoleEditor::BackspaceKey });
            int key;
            option = menu.Show(key);
            if (option == -1) {
                if (NConsoleEditor::IsO(key)) {
                    NConsoleEditor::Clear();
                    NPlayerView::WritePlayer(Player);
                }
                if (NConsoleEditor::IsP(key)) {
                    NConsoleEditor::Clear();
                    NSpellView::WriteSpells(Player);
                }
            }
        }
        levelOptions[option].Pay(Player);
        CurrentLevel = levelOptions[option].To;
    }
}
