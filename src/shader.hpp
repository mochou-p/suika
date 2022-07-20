// suika

#include "glad/glad.h"
#include "glad/glad_wgl.h"

#include <iostream>

class Shader
{
    public:
        Shader(int type, const char* code);
        ~Shader() {};

        unsigned int m_shader;
};
