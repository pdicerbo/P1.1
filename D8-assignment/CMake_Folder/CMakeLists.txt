cmake_minimum_required (VERSION 2.6)

project(matrix_mult)

enable_language(Fortran)

find_package(BLAS)

if(BLAS_FOUND)

add_definitions(-DCBLASFOUND)
add_executable(first_task.x first_task.c)# msub.f90)
target_link_libraries(first_task.x cblas)

add_executable(second_task.x second_task.F90)
target_link_libraries(second_task.x blas)

else(NOT BLAS_FOUND)

add_executable(first_task.x first_task.c msub.f90)
add_executable(second_task.x second_task.F90 cfunc.c)

endif(BLAS_FOUND)

