cmake_minimum_required(VERSION 3.12) # version can be different
set(CMAKE_CXX_STANDARD 20)

project(my_cpp_project) #name of your project

add_subdirectory(googletest) # add googletest subdirectory

include_directories(googletest/include      # this is so we can #include <gtest/gtest.h>

                    ../main/doublylinkedlist
                    ../main/stack
                    ../main/queue
                    
                    doublylinkedlist
                    stack
                    queue) 

add_executable(mytests mytests.cpp) # add this executable

target_link_libraries(mytests PRIVATE gtest) # link google test to this executable