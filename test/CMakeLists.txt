cmake_minimum_required(VERSION 3.11)

project(HuffmanTranscoderTest)

file(GLOB_RECURSE H_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE C_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
set(SOURCES ${H_FILES} ${C_FILES})
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} HuffmanTranscoder)