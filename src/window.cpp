// suika

#include "window.hpp"

Window::Window
()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_MAXIMIZED, true);

    m_window = glfwCreateWindow(m_width, m_height, "suika", nullptr, nullptr);

    glfwMakeContextCurrent(m_window);

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
