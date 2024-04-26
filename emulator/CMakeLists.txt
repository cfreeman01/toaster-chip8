#Library containing core emulator code

file(GLOB_RECURSE EMU_SRC
            ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
            
add_library(CHIP8coreLib 
            ${EMU_SRC})

include_directories(CHIP8coreLib
            ${CMAKE_CURRENT_SOURCE_DIR}/include)