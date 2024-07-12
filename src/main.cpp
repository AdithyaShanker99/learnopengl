#include "../Headers/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <random>
#include "../Headers/EBO.h"
#include "../Headers/VBO.h"
#include "../Headers/VAO.h"
#include "../Headers/shaderClass.h"





int main()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



    GLfloat vertices[] =
	{
		-0.5f, -0.5f, 0.0f, 
		-0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f

	};

    GLuint indices[] =
    {
        0,1,2,
        0,3,2
    };


    GLFWwindow* window = glfwCreateWindow(400, 400, "I made this", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "FAILED TO CREATE WINDOW" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0, 0, 400, 400);

    Shader shaderProgram("../Resource Files/Shaders/default.vert", "../Resource Files/Shaders/default.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    VBO1.Bind();
    EBO1.Bind();


    VAO1.LinkVBO(VBO1, 0);

    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    glClearColor(0.44f, 165.0f/255.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);

   
    double prev_time = glfwGetTime();
    float angle = 0.0;

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.44f, 165.0f / 255.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Activate();

        VAO1.Bind();
        
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);


        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();
   

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
