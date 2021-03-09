#include "menu.h"
#include <cstdio>
#include <windows.h>

#include "app/views/console_editor/console_editor.h"

TMenu::TMenu(const std::vector<std::string>& options) : Options(options) {}
TMenu::TMenu(const std::vector<std::string>& options, const std::string& header) : Options(options), Header(header) {}

int TMenu::Show() {
    int chosenOption = 0;
    while (1) {
        NConsoleEditor::Clear();
        if (Header != "") {
            std::cout << Header << std::endl;
        }
        for (size_t i = 0; i < Options.size(); i++) {
            if (i == chosenOption) {
                NConsoleEditor::SetColor(NConsoleEditor::LightBlue);
                std::cout << Options[i] << std::endl;
                NConsoleEditor::SetColor(NConsoleEditor::Yellow);
            }
            else {
                std::cout << Options[i] << std::endl;
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
    }
}
