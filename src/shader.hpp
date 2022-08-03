// suika

#pragma once

#include "glad/glad.h"
#include "glad/glad_wgl.h"

#include "utils.hpp"

class Shader
{
    public:
        Shader(int type, const std::string& filename);

        unsigned int m_shader = 0;
};
