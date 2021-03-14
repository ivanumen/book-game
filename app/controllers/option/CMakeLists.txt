add_library(option_control STATIC
	option_control.cpp
)

target_link_libraries(option_control PUBLIC 
	player
)