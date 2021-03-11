#include "player_views.h"

void NPlayerView::WritePlayer(const TPlayer& Player) {
    std::cout << "Сила: " << Player.GetStrength() << " " << "Ловкость: " << Player.GetAgility() << " " << "Харизма: " << Player.GetCharisma() << std::endl;
    std::cout << "Таблица удачи";
    Player.WriteLuck();
    std::cout << "Золото: " << Player.GetGold() << " " << "Фляга: " << Player.GetFlask() << std::endl;
    std::cout << "Нажмите Backspace(<-) чтобы выйти" << std::endl;
}