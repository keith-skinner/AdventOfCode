cmake_minimum_required(VERSION 3.25.1)

cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME ProjectName)   
string(REPLACE " " "_" ProjectId ${ProjectName})
project(${ProjectName})

add_executable(${PROJECT_NAME})

target_compile_features(
    ${PROJECT_NAME}
    PRIVATE
    cxx_std_20
)

target_compile_options(
    ${PROJECT_NAME}
    PRIVATE
    $<$<CONFIG:DEBUG>:-Wall>
    $<$<CONFIG:DEBUG>:-Wextra>
    $<$<CONFIG:DEBUG>:-Wpedantic>
    $<$<CONFIG:DEBUG>:-fsanitize=address,undefined>
)

target_link_options(
    ${PROJECT_NAME}
    PRIVATE
    $<$<CONFIG:DEBUG>:-fsanitize=address,undefined>
)

target_sources(
    ${PROJECT_NAME}
    PRIVATE
    main.cpp
)

file(
    COPY 
        ${CMAKE_SOURCE_DIR}/input.txt
    DESTINATION
        ${CMAKE_CURRENT_BINARY_DIR}
)