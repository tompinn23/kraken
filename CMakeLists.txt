cmake_minimum_required(VERSION 3.15)

project(kraken2)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)

add_subdirectory(third_party/spdlog)
add_subdirectory(third_party/lua-5.3.5)

add_subdirectory(third_party/libtcod-1.16.0-alpha.12/src)

add_library(sol2 INTERFACE)
target_include_directories(sol2 INTERFACE third_party/sol)

add_library(lodepng STATIC third_party/lodepng/lodepng.cpp)
target_include_directories(lodepng PUBLIC third_party/lodepng)


add_executable(kraken src/main.cxx src/data/lua.cxx src/graphics/ui/box.cxx)
target_link_libraries(kraken spdlog lua_static sol2 LIBTCOD)
target_include_directories(kraken PRIVATE third_party/libtcod-1.16.0-alpha.12/src)
