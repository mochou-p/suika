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

    float vertices[] =
    {
        -1.0,  1.0, 0.0,
        -1.0, -1.0, 0.0,
         1.0, -1.0, 0.0
    };

    Shader shaders[] =
    {
        Shader(GL_VERTEX_SHADER,   "shader.vert"),
        Shader(GL_FRAGMENT_SHADER, "shader.frag")
    };

    Program program(2, shaders);

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);

    Ui ui(&window);

    while (!glfwWindowShouldClose(window.m_window))
    {
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program.m_program);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //program.render(VBO);
        ui.render();

        glfwSwapBuffers(window.m_window);

        glfwPollEvents();
    }

    return 0;
}
