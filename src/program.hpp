// suika

#pragma once

#include "shader.hpp"

class Program
{
    public:
        Program(int count, Shader shaders[]);
        ~Program();

        void render(int count, unsigned int VAO);

        unsigned int m_program;
};
