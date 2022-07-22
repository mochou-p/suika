// suika

#pragma once

#include "shader.hpp"

class Program
{
    public:
        Program(int count, Shader shaders[]);
        ~Program();

        void render(GLuint VBO);

        unsigned int m_program;
};
