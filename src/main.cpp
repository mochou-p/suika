// suika

#include "program.hpp"
#include "window.hpp"

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

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

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplGlfw_InitForOpenGL(window.m_window, true);
    ImGui_ImplOpenGL3_Init();

    while (!glfwWindowShouldClose(window.m_window))
    {
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        glClear(GL_COLOR_BUFFER_BIT);


        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("fps");
        ImGui::Text("%d", (int) ImGui::GetIO().Framerate);
        ImGui::End();

        ImGui::EndFrame();
        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window.m_window);

        glfwPollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    return 0;
}
