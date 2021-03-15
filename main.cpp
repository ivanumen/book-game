#include "app/controllers/game/game.h"
#include "app/views/console_editor/console_editor.h"

#include <time.h>
#include <Windows.h>

int main()
{   
    //setlocale(LC_ALL, "Russian");
    NConsoleEditor::SetColor(NConsoleEditor::Yellow);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
<<<<<<< HEAD
    srand(static_cast<unsigned int>(time(nullptr)));
=======
    srand(time(nullptr));
>>>>>>> master
    TGame game;
    game.Start();
    return 0;
}
