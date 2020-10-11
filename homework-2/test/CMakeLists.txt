project(test_solve_square)

add_executable(TestSolver main.cpp test_solver.cpp)

target_link_libraries(TestSolver gtest_main square_solver) 