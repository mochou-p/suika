// suika

#include "shader.hpp"

const char* read_file
(std::string filename)
{
    std::string code;
    std::ifstream shader("res/shaders/" + filename);

    std::getline(shader, code, '\0');

    return code.c_str();
};

Shader::Shader
(int type, const char* filename)
{
    int success;

    const char* code = read_file(filename);

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
