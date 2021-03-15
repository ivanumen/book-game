#include "player_views.h"
#include"app/views/console_editor/console_editor.h"

void NPlayerView::WritePlayer(const TPlayer& Player) {
    std::cout << "����: " << Player.GetStrength() << " " << "��������: " << Player.GetAgility() << " " << "�������: " << Player.GetCharisma() << std::endl;
    std::cout << "������� �����";
    Player.WriteLuck();
    std::cout << "������: " << Player.GetGold() << " " << "�����: " << Player.GetFlask() << std::endl;
    std::cout << "������� Backspace(<-) ����� �����" << std::endl;
    NConsoleEditor::WaitForBackspace();
}