// suika

#include "shader.hpp"

#include "utils.hpp"

Shader::Shader
(int type, std::string filename)
{
    m_shader = glCreateShader(type);

    const char* code = read_file(filename);

    glShaderSource(m_shader, 1, &code, nullptr);

    int success;

    glCompileShader(m_shader);
    glGetShaderiv(m_shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        char log[512];
        glGetShaderInfoLog(m_shader, 512, nullptr, log);
        std::cout << log << std::endl;
    }
}
