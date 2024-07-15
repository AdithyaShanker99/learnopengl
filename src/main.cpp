#include <glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <random>
#include <math.h>
#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


#include "../Headers/EBO.h"
#include "../Headers/VBO.h"
#include "../Headers/VAO.h"
#include "../Headers/shaderClass.h"
#include "../Headers/Textures.h"
#include "../Headers/Camera.h"



int main()
{
    
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    int width = 3840;
    int height = 2160;

    // Vertices coordinates
    GLfloat vertices[] =
    { //     COORDINATES     /        COLORS      /   TexCoord  //
        -0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
        -0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
        0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	    0.0f, 0.0f,
        0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	    5.0f, 0.0f,
        0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	    2.5f, 5.0f
    };

    // Indices for vertices order
    GLuint indices[] =
    {
        0, 1, 2,
        0, 2, 3,
        0, 1, 4,
        1, 2, 4,
        2, 3, 4,
        3, 0, 4
    };



    GLFWwindow* window = glfwCreateWindow(width, height, "I made this", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "FAILED TO CREATE WINDOW" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0, 0, width, height);

    Shader shaderProgram("../Resources/Shaders/default.vert", "../Resources/Shaders/default.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    VBO1.Bind();
    EBO1.Bind();


    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8*sizeof(float), (void *)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8*sizeof(float), (void *)(3*sizeof(float)));
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8*sizeof(float), (void *)(6*sizeof(float)));


    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");
    //GLuint vId = glGetUniformLocation(shaderProgram.ID, "velocity");



    Texture tex("../Resources/Textures/brick.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE );

    tex.Unbind();
    
    tex.texUnit(shaderProgram, "tex0", 0);


    glClearColor(0.75f, 0.5f, 0.75f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);

   
    double prev_time = glfwGetTime();
    float angle = 0.0;
    glEnable(GL_DEPTH_TEST);


    

    Camera camera(width, height, glm::vec3(0.0f, 1.0f, 2.0f));
    // glfwSetKeyCallback();

    while (!glfwWindowShouldClose(window))
    {
        
        
        glClearColor(0.75f, 0.5f, 0.75f, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.Activate();

        // double currentTime = glfwGetTime();
        // if(currentTime - prev_time>=1/144)
        // {
        //     angle+=0.5f;
        //     prev_time = currentTime;
        // }
        camera.input_callback(window);
        camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camera");

        glUniform1f(uniID, 0.0);
        tex.Bind();

        
        VAO1.Bind();
        
        glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);


        glfwSwapBuffers(window);


        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    tex.Delete();
    shaderProgram.Delete();
   

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}




