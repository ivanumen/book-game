add_library(spell_views STATIC
	spell_views.cpp
)

target_link_libraries(spell_views PUBLIC
	player
)