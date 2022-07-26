// suika

#include "program.hpp"
#include "ui.hpp"

int main
(int argc, char** argv)
{
    Window window;

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    Shader shaders[] =
    {
        Shader(GL_VERTEX_SHADER,   "shader.vert"),
        Shader(GL_FRAGMENT_SHADER, "shader.frag")
    };

    int shader_count = sizeof(shaders) / sizeof(Shader);

    Program program(shader_count, shaders);

    Ui ui(&window);

    const float vertices[] =
    {
        -1.0, -1.0, 0.0,
         1.0, -1.0, 0.0,
         1.0,  1.0, 0.0,
        -1.0,  1.0, 0.0
    };

    const unsigned int indices[] =
    {
        0, 1, 2,
        2, 3, 0
    };

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

    unsigned int ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    int window_width, window_height;
    int u_screen = glGetUniformLocation(program.m_program, "u_screen");

    int indices_count = sizeof(indices) / sizeof(unsigned int);

    while (!glfwWindowShouldClose(window.m_window))
    {
        glfwGetFramebufferSize(window.m_window, &window_width, &window_height);
        glProgramUniform2f(program.m_program, u_screen, window_width, window_height);

        program.render(indices_count, vao);

        ui.render();

        glfwSwapBuffers(window.m_window);

        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ibo);

    return 0;
}
