cmake_minimum_required(VERSION 3.14)
project(Bowling)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)


add_library(game_lib STATIC
    sources/game.cpp
)
target_include_directories(game_lib PUBLIC headers)


add_executable(bowling_tests
    tests/test_game.cpp
)
target_link_libraries(bowling_tests game_lib gtest_main)

enable_testing()
add_test(NAME BowlingGameTests COMMAND bowling_tests)