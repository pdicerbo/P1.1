cmake_minimum_required (VERSION 2.6)

project(matrix_mult)

enable_language(Fortran)

add_executable(first_task.x first_task.c msub.f90)
target_link_libraries(first_task.x cblas)

add_executable(second_task.x second_task.f90 cfunc.c)
target_link_libraries(second_task.x blas)
