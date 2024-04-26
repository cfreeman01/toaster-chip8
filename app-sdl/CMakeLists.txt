#executable application using SDL2 for rendering and input

find_package(SDL2 REQUIRED)

file(GLOB_RECURSE APP_SRC
            ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(CHIP8 
            ${APP_SRC})

target_link_libraries(
            CHIP8 
            CHIP8coreLib 
            ${SDL2_LIBRARIES})

include_directories(CHIP8 
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/../emulator/include
            ${SDL2_INCLUDE_DIRS})