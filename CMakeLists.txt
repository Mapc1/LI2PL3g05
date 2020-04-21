cmake_minimum_required(VERSION 3.15)
project(LI2 C)

set(CMAKE_C_STANDARD 99)

add_executable(LI2 main.c interface.c interface.h logica.c logica.h dados.c dados.h bot.c bot.h listas.h listas.c)

target_link_libraries(LI2 m)