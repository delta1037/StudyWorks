cmake_minimum_required(VERSION 3.8)
project(sqlite_c)

set(CMAKE_C_STANDARD 99)

include_directories(/usr/include)
find_library(SQLITELIB sqlite3 /usr/lib)

set(SOURCE_FILES main.c)
add_executable(sqlite_c ${SOURCE_FILES})
target_link_libraries(sqlite_c ${SQLITELIB})
