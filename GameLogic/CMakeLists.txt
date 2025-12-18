# --- Define our library ---
add_library(GameLogic
        source/Scene.cpp
        source/Tiles/Tile.cpp
        source/Tiles/PathTile.cpp
        source/Tiles/EmptyTile.cpp
        source/Game.cpp
)

# --- Include files ---
target_include_directories(GameLogic PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

# --- Compile Options ---
target_compile_options(GameLogic PRIVATE
        $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:
        -Wall -Wextra -Wpedantic
        >
        $<$<CXX_COMPILER_ID:MSVC>:
        /W4 /permissive-
        >
)