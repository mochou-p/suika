//

#define APP_NAME "suika"

#include "window.hpp"

#include <iostream>

Window::Window()
{
    if (!Window::glfw_initialised)
    {
        if (!glfwInit())
        {
            std::cerr << "failed to initialise glfw" << std::endl;
            exit(EXIT_FAILURE); 
        }

        Window::glfw_initialised ^= 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    m_handle = glfwCreateWindow(800, 600, APP_NAME, nullptr, nullptr);

    glfwMakeContextCurrent(m_handle);
    glfwSwapInterval(1);
}

Window::~Window()
{
    glfwDestroyWindow(m_handle);
}
