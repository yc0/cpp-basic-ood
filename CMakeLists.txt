cmake_minimum_required(VERSION 3.15)
project(cpp_ood)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_ood main.cpp ocp.cpp dip.cpp isp.cpp lsp.cpp)
