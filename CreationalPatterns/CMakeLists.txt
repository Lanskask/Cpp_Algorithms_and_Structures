cmake_minimum_required(VERSION 3.15)
project(CreationalPatterns)

set(CMAKE_CXX_STANDARD 17)

#file(GLOB oop_classes
#        "oop_classes/*.cpp"
#        "oop_classes/*.h"
#        )
add_executable(CreationalPatterns main.cpp common.h)

add_executable(Premilinaries main.cpp SingleResponsibility.cpp OpenClosedPrinciple.cpp common.h)

add_executable(OpenClosedPrinciple main.cpp OpenClosedPrinciple.cpp common.h)

