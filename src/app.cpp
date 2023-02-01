//

#include "app.hpp"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <iostream>

#define APP_NAME   "suika"
#define OPENGL_VER "#version 130"

void glfw_on   ();
void glfw_off  ();
void imgui_on  (GLFWwindow*);
void imgui_off ();

App::App()
{
    glfw_on();

    m_window = new Window(APP_NAME);

    imgui_on(m_window->m_handle);
}

App::~App()
{
    delete m_window;

    imgui_off();
    glfw_off();
}

void App::run()
{
    while (!glfwWindowShouldClose(m_window->m_handle))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("hello");
        ImGui::End();

        glClear(GL_COLOR_BUFFER_BIT);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(m_window->m_handle);
    }
}

void glfw_on()
{
    if (!glfwInit())
    {
        std::cerr << "failed to initialise glfw" << std::endl;
        exit(EXIT_FAILURE); 
    }
}

void glfw_off()
{
    glfwTerminate();
}

void imgui_on(GLFWwindow* t_window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(t_window, true);
    ImGui_ImplOpenGL3_Init(OPENGL_VER);
}

void imgui_off()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}
