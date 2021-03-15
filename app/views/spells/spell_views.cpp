#include "spell_views.h"
#include"app/views/console_editor/console_editor.h"

void NSpellView::WriteSpells(const TPlayer& player){
	for (const auto& spell : player.GetSpells()) {
		std::cout << spell.first << ": " << spell.second << std::endl;
	}
	std::cout << "Нажмите Backspace(<-) чтобы выйти" << std::endl;
	NConsoleEditor::WaitForBackspace();
};