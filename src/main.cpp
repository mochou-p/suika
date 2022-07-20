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

    Shader vertex
    (
        GL_VERTEX_SHADER,
        "#version 330\n"
        "layout (location = 0) in vec3 pos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(pos, 1.0);\n"
        "}\0"
    );

    Shader fragment
    (
        GL_FRAGMENT_SHADER,
        "#version 330\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(0.0, 1.0, 0.0, 1.0);\n"
        "}\0"
    );

    Shader shaders[2] = { vertex, fragment };

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
