cmake_minimum_required(VERSION 3.5)

project(trabalho LANGUAGES C)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR} ../include)

add_executable(
    trabalho main.c
    improved-bubble-sort.c
    quick-sort.c
    merge-sort.c
    selection-sort.c
    util.c
    run-sorter.c
    window.c
)

target_link_libraries(trabalho ${CURSES_LIBRARIES})
