cmake_minimum_required(VERSION 3.23)
project(userLogin C)
set(CMAKE_C_STANDARD 99)
add_executable(userLogin main.c src/createul/createul.c src/checkuser/check_user_exists.c src/encrtext/encrypttext.c src/decrtext/decrypttext.c src/decrtext/decrypttext.h)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
#
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
#
add_definitions(${GTK3_CFLAGS_OTHER})
target_link_libraries(userLogin ${GTK3_LIBRARIES})