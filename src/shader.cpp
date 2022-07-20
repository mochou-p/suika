// suika

#include "shader.hpp"

Shader::Shader
(int type, const char* code)
{
    int success;

    m_shader = glCreateShader(type);

    glShaderSource(m_shader, 1, &code, NULL);
    glCompileShader(m_shader);
    glGetShaderiv(m_shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        char log[512];
        glGetShaderInfoLog(m_shader, 512, NULL, log);
        std::cout << log << std::endl;
    }
}
