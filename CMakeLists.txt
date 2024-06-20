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

# Источники и заголовочные файлы для библиотеки
set(SOURCE_FILES
    src/about.c
)

set(HEADER_FILES
    include/about.h
)

# Создание библиотеки core
add_library(core STATIC ${SOURCE_FILES} ${HEADER_FILES})

# Указание директорий с заголовочными файлами
target_include_directories(core PRIVATE include)

# Основной исполняемый файл
add_executable(komaru-the-game src/main.c)

# Линковка основной программы с библиотекой core и raylib
target_link_libraries(komaru-the-game PRIVATE core raylib)

# Линковка с дополнительными библиотеками для UNIX-платформ, кроме macOS
if(UNIX AND NOT APPLE)
    target_link_libraries(komaru-the-game PRIVATE m pthread dl rt X11)
endif()

# For Windows (если требуется)
# if(WIN32)
#     target_link_libraries(komaru-the-game PRIVATE gdi32 winmm)
# endif()