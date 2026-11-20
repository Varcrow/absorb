cmake_minimum_required(VERSION 3.20)
project(absorb VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BUILD_TESTS ON)

# Build Absorb
add_executable(
  ${CMAKE_PROJECT_NAME}
  "src/main.cpp"
  "src/SM2Card.cpp"
  "src/SM2Deck.cpp"
  "src/Absorb.cpp"
)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "include")
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE "-lstdc++exp")

# Build test
if (BUILD_TESTS)
  add_executable(test "test/main.cpp")
  target_include_directories(test PRIVATE "include")
  target_link_libraries(test PRIVATE "-lstdc++exp")
endif()
