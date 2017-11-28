cmake_minimum_required(VERSION 3.8)
project(ReversiTest)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


set(SOURCE_FILES src/Board.cpp src/Board.h
        src/HumanPlayer.cpp src/HumanPlayer.h src/GameLogic.cpp src/GameLogic.h
        src/Position.cpp src/Position.h src/Game.cpp src/Game.h src/Player.h src/Player.cpp
        src/AIPlayer.cpp src/AIPlayer.h)

set(TEST_FILES test/BoardTest.cpp test/GameTest.cpp test/HumanPlayerTest.cpp test/AIPlayerTest.cpp)

add_executable(Reversi ${SOURCE_FILES} src/main.cpp)
add_executable(ReversiTest ${TEST_FILES} ${SOURCE_FILES} test/MainTest.cpp)

target_link_libraries(ReversiTest gtest gtest_main)
