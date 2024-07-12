cmake_minimum_required(VERSION 3.0.0)
project(learn_open_gl VERSION 0.0.1)

add_executable(learn_open_gl 
    Headers/glad.h 
    Headers/EBO.h 
    Headers/VBO.h 
    Headers/VAO.h 
    Headers/shaderClass.h 
    src/glad.c
    src/main.cpp
    src/EBO.cpp
    src/VBO.cpp 
    src/VAO.cpp
    src/shaderClass.cpp  
)

target_link_libraries(learn_open_gl glfw)