// suika

#include "shader.hpp"

std::string read_file
(std::string filename)
{
    std::string code;
    std::ifstream shader("res/shaders/" + filename);

    std::getline(shader, code, '\0');

    return code.c_str();
};

Shader::Shader
(int type, std::string filename)
{
    int success;

    std::string code = read_file(filename);
    const GLchar* cstr = code.c_str();

    m_shader = glCreateShader(type);

    glShaderSource(m_shader, 1, &cstr, NULL);
    glCompileShader(m_shader);
    glGetShaderiv(m_shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        char log[512];
        glGetShaderInfoLog(m_shader, 512, NULL, log);
        std::cout << log << std::endl;
    }
}
