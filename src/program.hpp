// suika

#include "shader.hpp"

class Program
{
    public:
        Program(int count, Shader shaders[]);
        ~Program();

        unsigned int m_program;
};
