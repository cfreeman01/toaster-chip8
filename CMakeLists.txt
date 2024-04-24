cmake_minimum_required(VERSION 3.2)
project(toaster-chip8)

include(FetchContent)

set(APP_DIR     src/app-desktop-sdl)
set(EMU_DIR     src/emulator)
set(TEST_DIR    test)
set(INCLUDE_DIR include) 

#SDL2
find_package(SDL2 REQUIRED)

#CppUTest
FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG        v4.0
)
FetchContent_Populate(CppUTest)

#Core emulator lib
file(GLOB_RECURSE EMU_SRC
            ${EMU_DIR}/*.cpp 
            ${EMU_DIR}/*.h)
            
add_library(CHIP8lib ${EMU_SRC})
target_link_libraries(CHIP8lib ${SDL2_LIBRARIES})
include_directories(CHIP8lib ${INCLUDE_DIR} ${SDL2_INCLUDE_DIRS})

#Emulator app
file(GLOB_RECURSE APP_SRC
            ${APP_DIR}/*.cpp 
            ${APP_DIR}/*.h)

add_executable(CHIP8 ${APP_SRC})
target_link_libraries(CHIP8 CHIP8lib)
include_directories(CHIP8 ${INCLUDE_DIR})

#Test
file(GLOB_RECURSE TEST_SRC
            ${TEST_DIR}/*.cpp 
            ${TEST_DIR}/*.h)
add_executable(CHIP8test ${TEST_SRC})

target_link_libraries(CHIP8test 
                      CHIP8lib
                      CppUTest)

include_directories(CHIP8test 
                    ${INCLUDE_DIR}
                    cpputest/include)