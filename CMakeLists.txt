cmake_minimum_required(VERSION 3.15)
project(hash)

set(CMAKE_CXX_STANDARD 14)

add_executable(hash src/hash_table.c src/hash_table.h src/prime.c src/prime.h test/ht_test.c src/xmalloc.c src/xmalloc.h)