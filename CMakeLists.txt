cmake_minimum_required(VERSION 3.7)
project(ZhiFangTu)

set(CMAKE_CXX_STANDARD 11)
link_directories(/usr/local/lib)
set(SOURCE_FILES main.cpp)
add_executable(ZhiFangTu ${SOURCE_FILES})
target_link_libraries(ZhiFangTu mxml)
