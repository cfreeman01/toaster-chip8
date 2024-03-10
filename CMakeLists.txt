cmake_minimum_required(VERSION 3.2)
project(toaster-chip8)

set(APP_DIR     src/app)
set(EMU_DIR     src/emulator)
set(TEST_DIR    test)
set(INCLUDE_DIR include) 

#CppUTest
add_subdirectory(cpputest)

#Core emulator lib
file(GLOB_RECURSE EMU_SRC
            ${EMU_DIR}/*.cpp 
            ${EMU_DIR}/*.h)
            
add_library(CHIP8-Emu ${EMU_SRC})
include_directories(CHIP8-Emu ${INCLUDE_DIR})

#Emulator app
file(GLOB_RECURSE APP_SRC
            ${APP_DIR}/*.cpp 
            ${APP_DIR}/*.h)

add_executable(CHIP8-App ${APP_SRC})
target_link_libraries(CHIP8-App CHIP8-Emu)
include_directories(CHIP8-App ${INCLUDE_DIR})

#Test app
file(GLOB_RECURSE TEST_SRC
            ${TEST_DIR}/*.cpp 
            ${TEST_DIR}/*.h)
add_executable(CHIP8-Test ${TEST_SRC})

target_link_libraries(CHIP8-Test 
                      CHIP8-Emu
                      CppUTest)

include_directories(CHIP8-Test 
                    ${INCLUDE_DIR}
                    cpputest/include)