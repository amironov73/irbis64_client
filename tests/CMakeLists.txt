cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(irbis64_client C)

add_library(${PROJECT_NAME}
  SHARED
  irbis64_client.c
  irbis64_client.def
)

set (ARTIFACTS ${PROJECT_SOURCE_DIR}/ready)
install (FILES ${CMAKE_CURRENT_BINARY_DIR}/irbis64_client.exp  DESTINATION ${ARTIFACTS})
install (FILES ${CMAKE_CURRENT_BINARY_DIR}/irbis64_client.lib  DESTINATION ${ARTIFACTS})
