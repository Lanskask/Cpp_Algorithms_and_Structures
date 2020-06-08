cmake_minimum_required(VERSION 3.15)
project(CustomArray)


#set(CMAKE_CXX_COMPILER "/usr/bin/g++" )

set(CMAKE_CXX_STANDARD 14)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v")

#add_subdirectory(lib/Catch2)
#target_link_libraries(tests Catch2::Catch2)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -c")

#add_executable(CUSTOM_ARRAY Structures/main.cpp Structures/SIMPLE_ARRAY_STACK.h Structures/SIMPLE_ARRAY_STACK.cpp)

#add_executable(Tests FirstCatchTest.cpp)

add_executable(CustomArray CustomArray.h CustomArray.cpp main.cpp)
add_executable(Array Array/Array.cpp Array/Array.h Array/main2.cpp)
add_executable(Stack Stack/StackMain.cpp Stack/Stack.cpp Stack/Stack.h)
add_executable(Simple Simple/SimpleMain.cpp Simple/Simple.cpp Simple/Simple.h)
