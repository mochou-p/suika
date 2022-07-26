// suika

#include "window.hpp"

Window::Window
()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);

    m_window = glfwCreateWindow(800, 600, "suika", nullptr, nullptr);

    glfwMakeContextCurrent(m_window);

    glfwSwapInterval(1);

    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
}

Window::~Window
()
{
    glfwDestroyWindow(m_window);

    glfwTerminate();
}

void Window::framebuffer_size_callback
(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
