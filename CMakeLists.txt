cmake_minimum_required(VERSION 3.16)

project(LeosAdventure)

find_package(SFML 2 COMPONENTS graphics window system REQUIRED)

add_executable(LeosAdventure
    src/aboutPage.cpp
    src/background.cpp
    src/botton.cpp
    src/game.cpp
    src/gameOver.cpp
    src/ground.cpp
    src/main.cpp
    src/menu.cpp
    src/nextLevel.cpp
    src/obstacles.cpp
    src/player.cpp
    src/sprites.cpp
    src/tutorial.cpp
)

target_include_directories(LeosAdventure PRIVATE include)
target_link_libraries(LeosAdventure PRIVATE sfml-graphics sfml-window sfml-system)

add_custom_command(TARGET LeosAdventure POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/assets/images"
        "$<TARGET_FILE_DIR:LeosAdventure>"
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/assets/fonts"
        "$<TARGET_FILE_DIR:LeosAdventure>"
)
