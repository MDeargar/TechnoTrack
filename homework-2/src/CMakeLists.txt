add_library(square_solver SHARED square_equation.c)

install(TARGETS square_solver
	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)

add_executable(main_app main.c)
target_link_libraries(main_app PUBLIC square_solver PRIVATE m) 
