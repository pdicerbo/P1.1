cmake_minimum_required (VERSION 2.6)
project(first_task.x)

enable_language(Fortran)

# add_library(msub.h msub.f90)

add_executable(first_task.x first_task.c msub.f90)
# target_link_libraries (first_task.x msub.h)
target_link_libraries (first_task.x cblas)

# project(second_task.x)

# enable_language(Fortran)

# add_library(cfunc.h cfunc.c)

# add_executable(second_task.x second_task.f90)
# target_link_libraries (second_task.x cfunc.h)
