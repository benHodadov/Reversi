cmake_minimum_required(VERSION 3.8)
project(ReversiTest)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


set(CLIENT_FILES src/Client/main.cpp src/Client/Board.cpp src/Client/Board.h src/Client/HumanPlayer.cpp src/Client/HumanPlayer.h
        src/Client/GameLogic.cpp src/Client/GameLogic.h src/Client/Position.cpp src/Client/Position.h
        src/Client/Game.cpp src/Client/Game.h src/Client/Player.h src/Client/Player.cpp
        src/Client/AIPlayer.cpp src/Client/AIPlayer.h src/Client/Client.cpp src/Client/Client.h
        src/Client/RemotePlayer.cpp src/Client/RemotePlayer.h src/Client/LocalPlayer.cpp src/Client/LocalPlayer.h)

set(TEST_FILES test/BoardTest.cpp test/GameTest.cpp test/HumanPlayerTest.cpp test/AIPlayerTest.cpp)

set(SERVER_FILES src/Server/main.cpp src/Server/Server.cpp src/Server/Server.h
        src/Server/CommandsManager.cpp src/Server/CommandsManager.h src/Server/Command.h
        src/Server/TestCommand.cpp src/Server/TestCommand.h src/Server/StartCommand.cpp src/Server/StartCommand.h
        src/Server/JoinCommand.cpp src/Server/JoinCommand.h src/Server/PlayCommand.cpp src/Server/PlayCommand.h
        src/Server/CloseCommand.cpp src/Server/CloseCommand.h src/Server/ListGamesCommand.cpp src/Server/ListGamesCommand.h)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(CLIENT ${CLIENT_FILES} src/Client/main.cpp)
add_executable(SERVER ${SERVER_FILES} src/Server/main.cpp)
add_executable(ReversiTest ${TEST_FILES} ${CLIENT_FILES} ${SERVER_FILES} test/MainTest.cpp)

target_link_libraries(ReversiTest gtest gtest_main)
