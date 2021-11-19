cmake_minimum_required(VERSION 3.0)
project(WebServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(WebServer main.cpp)


include_directories(D:\\homework\\electroniccommerce\\WebServer\\WS2_32.LIB)

link_directories(D:\\homework\\electroniccommerce\\WebServer\\WS2_32.LIB)
link_libraries(ws2_32)

target_link_libraries(WebServer ws2_32)