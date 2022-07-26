// suika

#pragma once

#include "shader.hpp"

class Program
{
    public:
        Program(int count, Shader* shaders);
        ~Program();

        void render(int count, unsigned int VAO) const;

        unsigned int m_program;
};
