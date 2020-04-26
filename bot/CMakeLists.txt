cmake_minimum_required(VERSION 3.16)
project(bot C)

set(CMAKE_C_STANDARD 99)

add_executable(bot main.c dados.c dados.h logica.c logica.h tree.c tree.h listas.c listas.h)

target_link_libraries(bot m)