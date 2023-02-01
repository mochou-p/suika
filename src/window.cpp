//

#include "window.hpp"

#include <iostream>

Window::Window(std::string t_title)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    m_handle = glfwCreateWindow(800, 600, t_title.c_str(), nullptr, nullptr);

    glfwMakeContextCurrent(m_handle);
    glfwSwapInterval(1);
}

Window::~Window()
{
    glfwDestroyWindow(m_handle);
}
