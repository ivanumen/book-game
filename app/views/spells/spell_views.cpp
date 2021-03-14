#include "spell_views.h"

void NSpellView::WriteSpells(const TPlayer& player){
	for (const auto& spell : player.GetSpells()) {
		std::cout << spell.first << ": " << spell.second << std::endl;
	}
	std::cout << "������� Backspace(<-) ����� �����" << std::endl;
};