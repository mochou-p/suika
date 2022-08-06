// suika

#include "program.hpp"

Program::Program
(int count, Shader* shaders)
{
    m_id = glCreateProgram();

    for (int i = count - 1; i >= 0; --i)
    {
        glAttachShader(m_id, shaders[i].m_id);
    }

    int success;

    glLinkProgram(m_id);
    glGetProgramiv(m_id, GL_LINK_STATUS, &success);

    if (!success)
    {
        char log[512];
        glGetProgramInfoLog(m_id, 512, nullptr, log);

        std::cout << log << std::endl;
    }

    for (int i = count - 1; i >= 0; --i)
    {
        glDeleteShader(shaders[i].m_id);
    }
}

Program::~Program
()
{
    glDeleteProgram(m_id);
}

void Program::render
(int count, unsigned int texture, unsigned int VAO)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glUseProgram(m_id);

    int u_texture = glGetUniformLocation(m_id, "u_texture");
    glUniform1i(u_texture, 0);


    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
}
