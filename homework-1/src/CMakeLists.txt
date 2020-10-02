add_library(square_solver SHARED square_equation.c)
install(TARGETS square_solver
	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)