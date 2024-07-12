#ifndef EBO_Class_H
#define EBO_Class_H

#include "glad.h"

class EBO
{
    public:
         GLuint ID;
         EBO(GLuint* vertices, GLsizeiptr size);

         void Bind();
         void Unbind();
         void Delete();

};
#endif