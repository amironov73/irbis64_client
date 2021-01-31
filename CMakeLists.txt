###########################################################
# irbis64_client.dll wrapper
# Alexey Mironov, 2021
###########################################################

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(irbis64_test C)
set(CMAKE_C_STANDARD 90)

if(MSVC)

    # add_compile_options(/UTF-8 /Wall)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)

endif(MSVC)

add_executable(${PROJECT_NAME}
    irbis64_test.c
    ${PROJECT_SOURCE_DIR}/include/irbis64_client.h
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
        "${PROJECT_SOURCE_DIR}/libs/irbis64_client.lib")
