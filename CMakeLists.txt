cmake_minimum_required(VERSION 3.5)

project(komaru-the-game LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER "clang")  

find_package(raylib REQUIRED)
 
option(DEBUG "Debug version?" OFF)
if(DEBUG)
    # Set Debug - for debug
    # Set Release - for release
    set(CMAKE_BUILD_TYPE Debug)
    add_compile_definitions(DEBUG)
else()
    set(CMAKE_BUILD_TYPE Release)
endif()

set(SOURCE 
    src/main.c
    )
add_executable(komaru-the-game ${SOURCE})

target_link_libraries(komaru-the-game PRIVATE raylib)

target_include_directories(komaru-the-game PRIVATE ${RAYLIB_INCLUDE_DIRS})

if(UNIX AND NOT APPLE)
    target_link_libraries(komaru-the-game PRIVATE m pthread dl rt X11)
endif()

# For Windows idk...
# if(WIN32)
#     target_link_libraries(komaru-the-game PRIVATE gdi32 winmm)
# endif()
