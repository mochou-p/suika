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
(int count, unsigned int texture, unsigned int VAO)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glUseProgram(m_program);

    int u_texture = glGetUniformLocation(m_program, "u_texture");
    glUniform1i(u_texture, 0);


    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
}
