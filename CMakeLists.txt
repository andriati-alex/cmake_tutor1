# Also start with this line
cmake_minimum_required(VERSION 3.20)


# Project name and description
project(Example VERSION 1.0
        DESCRIPTION "A good starting point to master cmake"
        LANGUAGES C
)


# simple library that have only one source file `displaymsg.c`
# It is a good practice to also pass the specific header file
# although it is not required (no errors and no warnings case
# `include/displaymsg.h` is not given)
add_library(dummylib STATIC src/displaymsg.c include/displaymsg.h)
target_include_directories(dummylib PUBLIC include)


# The executable which uses functions of `dummylib` generated
# above. Even the exe file also include the header `displaymsg.h`
# we do not need to explicit use target_include_directories
# because it as already mentioned in library generation
add_executable(dummyexe apps/hello_world.c)
target_link_libraries(dummyexe PUBLIC dummylib)
