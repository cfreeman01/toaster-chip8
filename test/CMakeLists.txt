#Test application utilizing CppUTest

include(FetchContent)

#fetch CppUTest
FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cfreeman01/cpputest.git
    GIT_TAG        a261c48ca48f1ff69f5ca00602192605b78c9eab
)
FetchContent_Populate(CppUTest)
add_subdirectory(${cpputest_SOURCE_DIR} ${cpputest_BINARY_DIR})

#build app
file(GLOB_RECURSE TEST_SRC
            ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(CHIP8test 
            ${TEST_SRC})

target_link_libraries(CHIP8test 
                      CHIP8coreLib
                      CppUTest)

include_directories(CHIP8test 
                    ${CMAKE_CURRENT_SOURCE_DIR}/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/../emulator/include
                    ${cpputest_SOURCE_DIR}/include)