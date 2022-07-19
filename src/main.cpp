// suika

#include "glad/glad.h"
#include "glad/glad_wgl.h"

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

#include "window.hpp"

#include <iostream>
#include <math.h>

int main
(int argc, char** argv)
{
    Window window;

    ((BOOL (WINAPI*)(int)) wglGetProcAddress("wglSwapIntervalEXT"))(1);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::cout << "failed to initialize GLAD" << std::endl;
        return -1;
    }

    int success;

    const char* vertex_shader_source =
        "#version 330\n"
        "const vec2 quad[4] ="
            "vec2[4]"
            "("
                "vec2(-1.0, -1.0),"
                "vec2( 1.0, -1.0),"
                "vec2(-1.0,  1.0),"
                "vec2( 1.0,  1.0)"
            ");\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(quad[gl_VertexID], 1.0);\n"
        "}\0";
    
    unsigned int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        char info_log[512];
        glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);
        std::cout << "vertex shader compilation failed\n" << info_log << std::endl;
    }

    const char* fragment_shader_source =
        "#version 330\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "    FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
        "}\0";
    
    unsigned int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        char info_log[512];
        glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
        std::cout << "fragment shader compilation failed\n" << info_log << std::endl;
    }

    unsigned int shader_program = glCreateProgram();
    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);
    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);

    if (!success)
    {
        char info_log[512];
        glGetProgramInfoLog(shader_program, 512, NULL, info_log);
        std::cout << "program link failed\n" << info_log << std::endl;
    }

    glUseProgram(shader_program);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

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

    glDeleteProgram(shader_program);

    return 0;
}
