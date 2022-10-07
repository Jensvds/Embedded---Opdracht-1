cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(Opdracht1)

add_executable(Opdracht1 main.c)

target_link_libraries(Opdracht1 PJ_RPI mariadb)
include_directories(/usr/include/mariadb /usr/include/mariadb/mysql)
