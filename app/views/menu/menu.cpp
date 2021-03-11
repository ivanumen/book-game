#include "menu.h"
#include <cstdio>
#include <windows.h>

#include "app/views/console_editor/console_editor.h"

TMenu::TMenu() : Buttons() {}
TMenu::TMenu(const std::vector<std::string>& options) : Options(options) {}
TMenu::TMenu(const std::vector<std::string>& options, const TPoint& pointLeft, const TPoint& pointRight, const std::vector<int> buttons) : Options(options), PointLeft(pointLeft), PointRight(pointRight), Buttons(buttons) {}

int TMenu::Show() {
    int key;
    return Show(key);
}

int TMenu::Show(int& pressedKey) {
    int chosenOption = 0;
    while (1) {
        NConsoleEditor::Clear(PointLeft, PointRight);
        for (size_t i = 0; i < Options.size(); i++) {
            NConsoleEditor::GoToXY(PointLeft.X, PointLeft.Y + i);
            if (i == chosenOption) {
                NConsoleEditor::SetColor(NConsoleEditor::LightBlue);
                std::cout << Options[i];
                NConsoleEditor::SetColor(NConsoleEditor::Yellow);
            }
            else {
                std::cout << Options[i];
            }
        }
        int key = NConsoleEditor::Getch();

        if (chosenOption > 0 && NConsoleEditor::IsUp(key)) {
            chosenOption--;
        }

        if (chosenOption < static_cast<int>(Options.size()) - 1 && NConsoleEditor::IsDown(key)) {
            chosenOption++;
        }


        if (NConsoleEditor::IsEnter(key)) {
            return chosenOption;
        }

        if (find(Buttons.begin(), Buttons.end(), key) != Buttons.end()) {
            pressedKey = key;
            return -1;
        }
    }
}
