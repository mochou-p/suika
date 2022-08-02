// suika

#include "program.hpp"

Program::Program
(int count, Shader* shaders)
{
    m_program = glCreateProgram();

    for (int i = count - 1; i >= 0; --i)
    {
        glAttachShader(m_program, shaders[i].m_shader);
    }

    int success;

    glLinkProgram(m_program);
    glGetProgramiv(m_program, GL_LINK_STATUS, &success);

    if (!success)
    {
        char log[512];
        glGetProgramInfoLog(m_program, 512, nullptr, log);

        std::cout << log << std::endl;
    }

    for (int i = count - 1; i >= 0; --i)
    {
        glDeleteShader(shaders[i].m_shader);
    }
}

Program::~Program
()
{
    glDeleteProgram(m_program);
}

void Program::render
(int count, unsigned int VAO) const
{
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(m_program);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
}
