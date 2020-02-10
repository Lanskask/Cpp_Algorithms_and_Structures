cmake_minimum_required(VERSION 3.15)
project(Algorithms)

set(CMAKE_CXX_STANDARD 17)

#add_subdirectory(lib/Catch2)
#target_link_libraries(tests Catch2::Catch2)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -c")

#add_executable(Algorithms Structures/main.cpp Structures/CustomArray.h Structures/CustomArray.cpp)

#add_executable(Tests FirstCatchTest.cpp)

add_executable(Structures
        Structures/main.cpp Structures/CustomArray.cpp Structures/CustomArray.h)