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
        Shader(GL_VERTEX_SHADER,   "color.vert"),
        Shader(GL_FRAGMENT_SHADER, "color.frag")
    };

    int shader_count = sizeof(shaders) / sizeof(Shader);

    Program program(shader_count, shaders);

    Ui ui(window.m_window);

    Layer layer;

    const float screen_quad_vertices[] =
    {
        -1.0, -1.0, 0.0,
         1.0, -1.0, 0.0,
         1.0,  1.0, 0.0,
        -1.0,  1.0, 0.0
    };

    const unsigned int screen_quad_indices[] =
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(screen_quad_vertices), screen_quad_vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

    unsigned int ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(screen_quad_indices), screen_quad_indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    int u_frag_color = glGetUniformLocation(program.m_program, "u_frag_color");
    glProgramUniform4f(program.m_program, u_frag_color, 0.70588, 0.35294, 0.82353, 1.0);

    int indices_count = sizeof(screen_quad_indices) / sizeof(unsigned int);

    while (!glfwWindowShouldClose(window.m_window))
    {
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
