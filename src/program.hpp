// suika

#pragma once

#include "shader.hpp"

class Program
{
    public:
        Program(int count, Shader* shaders);
        ~Program();

        void render(int count, unsigned int texture, unsigned int VAO);

        unsigned int m_id = 0;
};
