cmake_minimum_required(VERSION 3.20)
project(absorb VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(
${CMAKE_PROJECT_NAME}
"src/main.cpp"
"src/SM2Card.cpp"
"src/SM2Deck.cpp"
"src/SM2.cpp"
)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "include")
