cmake_minimum_required(VERSION 3.12)

project(algorithms VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

set(SOURCES 
    src/sorting.cpp
    src/bin.cpp
)

add_library(${PROJECT_NAME} SHARED
    ${SOURCES}
) 

set_target_properties(${PROJECT_NAME} PROPERTIES 
    PUBLIC_HEADER include/sorting.h
    PUBLIC_HEADER include/bin.h
)

install(TARGETS ${PROJECT_NAME} 
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION include
)
