add_library(std_str_funcs SHARED pointers.c)

install(TARGETS std_str_funcs
	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)

add_executable(main_app main.c quick_sort.c)
target_link_libraries(main_app PUBLIC std_str_funcs PRIVATE m) 
