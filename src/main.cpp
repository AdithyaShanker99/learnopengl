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

float fov = 45.0;

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    fov+=yoffset;
}

int main()
{
    
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    int width = 3840;
    int height = 2160;

    // pyramidVertices coordinates
    GLfloat pyramidVertices[] =
    { //     COORDINATES     /        COLORS      /   TexCoord  //
        -0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
        -0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
        0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	    0.0f, 0.0f,
        0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	    5.0f, 0.0f,
        0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	    2.5f, 5.0f,
        //cube
        

    };

    // pyramidIndices for pyramidVertices order
    GLuint pyramidIndices[] =
    {
        0, 1, 2,
        0, 2, 3,
        0, 1, 4,
        1, 2, 4,
        2, 3, 4,
        3, 0, 4
    };


    GLfloat lightVertices[] =
    { //     COORDINATES     //
        -0.1f, -0.1f,  0.1f,  // Vertex 0
        -0.1f, -0.1f, -0.1f,  // Vertex 1
        0.1f, -0.1f, -0.1f,   // Vertex 2
        0.1f, -0.1f,  0.1f,   // Vertex 3
        -0.1f,  0.1f,  0.1f,  // Vertex 4
        -0.1f,  0.1f, -0.1f,  // Vertex 5
        0.1f,  0.1f, -0.1f,   // Vertex 6
        0.1f,  0.1f,  0.1f    // Vertex 7
    };

    GLuint lightIndices[] =
    {
        // Bottom face
        0, 1, 2,
        0, 2, 3,
        // Front face
        0, 4, 7,
        0, 7, 3,
        // Right face
        3, 7, 6,
        3, 6, 2,
        // Back face
        2, 6, 5,
        2, 5, 1,
        // Left face
        1, 5, 4,
        1, 4, 0,
        // Top face
        4, 5, 6,
        4, 6, 7
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

    VBO VBO1(pyramidVertices, sizeof(pyramidVertices));
    EBO EBO1(pyramidIndices, sizeof(pyramidIndices));

    VBO1.Bind();
    EBO1.Bind();


    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8*sizeof(float), (void *)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8*sizeof(float), (void *)(3*sizeof(float)));
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8*sizeof(float), (void *)(6*sizeof(float)));


    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();



    Shader shaderLight("../Resources/Shaders/light.vert", "../Resources/Shaders/light.frag");

    VAO VAO2;
    VAO2.Bind();

    VBO VBO2(lightVertices, sizeof(lightVertices));
    EBO EBO2(lightIndices, sizeof(lightIndices));

    VBO2.Bind();
    EBO2.Bind();


    VAO2.LinkAttrib(VBO2, 0, 3, GL_FLOAT, 3*sizeof(float), (void *)0);

    VAO2.Unbind();
    VBO2.Unbind();
    EBO2.Unbind();

    glm::vec4 lightColor = glm::vec4(1.0f, 1.0f,1.0f)

    glm::vec3 lightPos = glm::vec3(0.5f,0.5f,0.5f);
    glm::mat4 lightModel = glm::mat4(1.0f);
    lightModel = glm::translate(lightModel, lightPos);

    glm::vec3 pyramidPos = glm::vec3(0.0f,0.0f,0.0f);
    glm::mat4 pyramidModel = glm::mat4(1.0f);
    pyramidModel = glm::translate(lightModel, lightPos);

    shaderProgram.Activate();
    glUniformMatrix4fv(glGetUniformLocation(shaderLight.ID, "model"), 1, GL_FALSE, glm::value_ptr(pyramidModel));
    shaderLight.Activate();
    glUniformMatrix4fv(glGetUniformLocation(shaderLight.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));








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


    

    Camera camera(width, height, glm::vec3(0.0f, 0.0f, 3.0f));
    glfwSetScrollCallback(window, scroll_callback);
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
        camera.Inputs(window);
        camera.updateMatrix(fov, 0.1f, 100.0f);


        camera.Matrix(shaderProgram, "camera");

        glUniform1f(uniID, 0.0);
        tex.Bind();

        VAO1.Bind();
        
        glDrawElements(GL_TRIANGLES, sizeof(pyramidIndices)/sizeof(int), GL_UNSIGNED_INT, 0);

        shaderLight.Activate();
        camera.Matrix(shaderLight, "camera");
        VAO2.Bind();
        glDrawElements(GL_TRIANGLES, sizeof(lightIndices)/sizeof(int), GL_UNSIGNED_INT, 0);


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




