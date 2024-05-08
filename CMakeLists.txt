cmake_minimum_required(VERSION 3.25)
project(nigamiga C)

set(CMAKE_C_STANDARD 17)

add_executable(nigamiga main.c hashtable/hashtable.h hashtable/hashtable.c cmdLine/cmdLine_Buffer.c cmdLine/cmdLine_Buffer.h statement.c statement.h meta_cmd.c meta_cmd.h)
