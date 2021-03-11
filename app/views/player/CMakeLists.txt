add_library(player_views STATIC 
	player_views.cpp
)

target_link_libraries(player_views PUBLIC 
	player
)