add_library(game STATIC
	game.cpp
)

target_link_libraries(game PUBLIC
	console_editor
	menu
	dice
	file_editor
	decoder
	level
	player
	json
	items
	spell_views
	player_views
	actions
	option_control
)