#include "../Headers/Camera.h"

Camera::Camera(int width, int height, glm::vec3 position)
{
    Camera::width = width;
    Camera::height = height;
    eye = position;
}

void Camera::Matrix(float FOVdeg, float clipNear, float clipFar, Shader& shader, const char* uniformName)
{
    glm::mat4 model = glm::mat4(1.0f);
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 proj = glm::mat4(1.0f);

    view = glm::lookAt(eye,center,up);
    proj = glm::perspective(glm::radians(FOVdeg), (float)width/height, clipNear, clipFar);


    glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniformName), 1 , GL_FALSE, glm::value_ptr(proj*view*model));
}

void Camera::input_callback(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        eye+=speed*center;
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        eye+=speed*center;
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        eye+=speed*-center;
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        glm::vec3 right = glm::normalize(glm::cross(center, up));
        eye += -speed * right;

    }

}
