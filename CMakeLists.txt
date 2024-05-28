cmake_minimum_required(VERSION 3.5.0)
project(proj VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(proj main.cpp api.cpp parser.cpp)

target_link_libraries(proj curl)
target_include_directories(proj PUBLIC "${CMAKE_SOURCE_DIR}/include")


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
