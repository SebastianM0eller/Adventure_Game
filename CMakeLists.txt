cmake_minimum_required(VERSION 3.20)
project(Game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Add the subdirectory ---
add_subdirectory(GameLogic)

# --- Create Executable ---
add_executable(${PROJECT_NAME} main.cpp)

# --- Link our library ---
target_link_libraries(${PROJECT_NAME} PRIVATE GameLogic)

# --- Compile Options ---
target_compile_options(${PROJECT_NAME} PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall -Wextra -Wpedantic
        >
        $<$<CXX_COMPILER_ID:MSVC>:
        /W4 /permissive-
        >
)