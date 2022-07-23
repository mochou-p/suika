// suika

#include "program.hpp"
#include "ui.hpp"

#include <math.h>

int main
(int argc, char** argv)
{
    Window window;

    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    ((BOOL (WINAPI*)(int)) wglGetProcAddress("wglSwapIntervalEXT"))(1);


    Shader shaders[2] =
    {
        Shader(GL_VERTEX_SHADER,   "shader.vert"),
        Shader(GL_FRAGMENT_SHADER, "shader.frag")
    };

    Program program(2, shaders);

    Ui ui(&window);

    const float vertices[12] =
    {
         1.0,  1.0, 0.0,
         1.0, -1.0, 0.0,
        -1.0, -1.0, 0.0,
        -1.0,  1.0, 0.0
    };

    const unsigned int indices[6] =
    {
        0, 1, 3,
        1, 2, 3
    };

    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (const void*) 0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    int u_screen = glGetUniformLocation(program.m_program, "u_screen");
    int x, y;

    while (!glfwWindowShouldClose(window.m_window))
    {
        glfwGetFramebufferSize(window.m_window, &x, &y);
        glProgramUniform2f(program.m_program, u_screen, x, y);

        program.render(6, VAO);

        ui.render();

        glfwSwapBuffers(window.m_window);

        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    return 0;
}
