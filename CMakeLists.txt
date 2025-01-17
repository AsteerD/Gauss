cmake_minimum_required(VERSION 3.28)

project(
        App
        VERSION 1.0
        LANGUAGES C)

add_executable(App gauss.c  gauss.h  main.c  matrix.c  matrix.h  test.c)