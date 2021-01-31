cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(irbis64_client C)

add_library(${PROJECT_NAME}
  SHARED
  irbis64_client.c
  irbis64_client.def
)

