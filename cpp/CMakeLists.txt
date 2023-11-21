cmake_minimum_required(VERSION 3.12)

project(algorithms VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

set(HEADERS 
    include/sorting.h
)
set(SOURCES 
    src/sorting.cpp
)

add_library(${PROJECT_NAME} SHARED
    ${SOURCES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES 
    PUBLIC_HEADER ${HEADERS}
)

install(TARGETS ${PROJECT_NAME} 
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
