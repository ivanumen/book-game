#include "game.h"
#include <cstdio>
#include <windows.h>

#include "app/views/console_editor/console_editor.h"
#include "app/views/menu/menu.h"
#include "app/util/dice/dice.h"
#include "app/util/json/json.h"
#include "app/util/decoder/decoder.h"
#include "app/util/file_editor/file_editor.h"
#include "app/models/level/level.h"

void TGame::Start() {
    ReadConfig();
    TMenu mainMenu({ "Новая игра", "Загрузка" ,"Настройки", "Эксит" });
    int value = mainMenu.Show();
    if (value == 0) {
        New();
    }
}

void TGame::ReadConfig() {
    std::string configStr = NFileEditor::ReadFile("../config.json");
    NJson::TJsonValue config = NJson::TJsonValue::parse(NDecoder::ToUtf8(configStr));
    for (auto levelInfo : config) {
        std::vector<std::pair<int, std::string>> options;
        for (auto to : levelInfo["options"]) {
            options.emplace_back(to["to"], NDecoder::FromUtf8(to["text"]));
        }
        TLevel level(NDecoder::FromUtf8(levelInfo["text"]), options);
        Levels[levelInfo["id"]] = level;
    }
}

void TGame::InitPlayer() {
    std::string name;
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
    std::cout << "Имя игрока: " << Player.GetName() << std::endl;
    std::cout << "Характеристики игрока" << std::endl;
    std::cout << "Сила: " << Player.GetStrength() << " Ловкость: " << Player.GetAgility() << " Харизма: " << Player.GetCharisma() << std::endl;
    std::cout << "Таблица удачи";
    Player.WriteLuck();
    Player.SetGold(15);
    Player.SetFlask(2);
    InitSpells();
}

void TGame::WritePlayer() const {
    std::cout << "Сила: " << Player.GetStrength() << "Ловкость: " << Player.GetAgility() << "Харизма: " << Player.GetCharisma();
    std::cout << "Таблица удачи";
    Player.WriteLuck();
    std::cout << "Золото:" << Player.GetGold() << "Фляга: " << Player.GetFlask() << std::endl;
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
            }
        }
    }
}

void TGame::Run() {
    while (1) {
        NConsoleEditor::Clear();
        WritePlayer();
        auto level = Levels[CurrentLevel];
        std::vector<std::string> options;
        for (const auto& option : level.GetOptions()) {
            options.push_back(option.second);
        }
        TMenu menu(options, level.GetText());
        int key = menu.Show();
        CurrentLevel = level.GetOptions()[key].first;
    }
}
