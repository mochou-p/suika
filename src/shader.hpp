// suika

#pragma once

#include "glad/glad.h"
#include "glad/glad_wgl.h"

#include <iostream>
#include <fstream>

class Shader
{
    public:
        Shader(int type, std::string filename);

        unsigned int m_shader;
};
