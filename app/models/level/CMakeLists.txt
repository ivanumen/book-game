add_library(level STATIC 
	level.cpp
)

target_link_libraries(level STATIC
	actions
	option_control
)