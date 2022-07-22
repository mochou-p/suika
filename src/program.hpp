// suika

#pragma once

#include "shader.hpp"

class Program
{
    public:
        Program(int count, Shader shaders[]);
        ~Program();

        void render(int count, GLuint VAO);

        unsigned int m_program;
};
