// suika

#include "glad/glad.h"
#include "glad/glad_wgl.h"

#include <iostream>
#include <fstream>

class Shader
{
    public:
        Shader(int type, const char* filename);
        ~Shader() {};

        unsigned int m_shader;
};
