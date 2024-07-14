#include <glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <random>
#include <math.h>
#include <stb_image.h>


#include "../Headers/EBO.h"
#include "../Headers/VBO.h"
#include "../Headers/VAO.h"
#include "../Headers/shaderClass.h"
#include "../Headers/Textures.h"





int main()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



    GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3,     0.0f,          1.0f, 0.0f, 0.0f,      -1.0f, -1.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3,      0.0f,          1.0f, 0.0f, 0.0f,      0.5f, 2.0f,
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3,   0.0f,          0.0f, 1.0f, 0.0f,      2.0f, -1.0f,

	};

    GLuint indices[] =
    {
        0,2,1
    };


    GLFWwindow* window = glfwCreateWindow(1000, 1000, "I made this", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "FAILED TO CREATE WINDOW" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0, 0, 1000, 1000);

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



    Texture tex("../Resources/Textures/dog.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE );

    tex.Unbind();
    
    tex.texUnit(shaderProgram, "tex0", 0);





    glClearColor(0.75f, 0.5f, 0.75f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);

   
    double prev_time = glfwGetTime();
    float angle = 0.0;

    while (!glfwWindowShouldClose(window))
    {
        
        glClearColor(0.75f, 0.5f, 0.75f, 1.0f);

        glClear(GL_COLOR_BUFFER_BIT);

        // float prev_velocity = 0.01f;

        // if(glfwGetTime() - prev_time >= 0.0) {
        
        //     glUniform1f(vId, 0.5f*sin(prev_time));
        //     prev_time = glfwGetTime();
        // }

        glUniform1f(uniID, 0.0);
        tex.Bind();

        
        VAO1.Bind();
        
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

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
