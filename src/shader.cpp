// suika

#include "shader.hpp"

Shader::Shader
(int type, const std::string& filename)
{
    m_id = glCreateShader(type);

    std::string _code = read_file(filename);
    const char*  code = _code.c_str();

    glShaderSource(m_id, 1, &code, nullptr);

    int success;

    glCompileShader(m_id);
    glGetShaderiv(m_id, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        char log[512];
        glGetShaderInfoLog(m_id, 512, nullptr, log);
        std::cout << log << std::endl;
    }
}
