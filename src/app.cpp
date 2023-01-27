//

#include "app.hpp"

#include <iostream>

App::App()
{
    glfwInit();

    m_window = glfwCreateWindow(800, 600, "suika", nullptr, nullptr);
}

App::~App()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void App::run()
{
    while (!glfwWindowShouldClose(m_window))
    {
        glfwPollEvents();
        glfwSwapBuffers(m_window);
    }
}
