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

    while (!glfwWindowShouldClose(window.m_window))
    {
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        glClear(GL_COLOR_BUFFER_BIT);

        ui.render();

        glfwSwapBuffers(window.m_window);

        glfwPollEvents();
    }

    return 0;
}
