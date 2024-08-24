cmake_minimum_required(VERSION 3.20)
project(philo VERSION 1.0 LANGUAGES C)

# Set the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Set the compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Werror -Wextra")

# Include directories
include_directories(includes)

# Define the source files
set(SRC_FILES
        includes/philosophers.h
        srcs/main.c
        srcs/actions.c
        srcs/checks.c
        srcs/init.c
        srcs/mutex.c
        srcs/threads.c
        srcs/utils.c
)

# Define the executable
add_executable(philo ${SRC_FILES})
