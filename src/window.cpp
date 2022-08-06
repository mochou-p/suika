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

    m_object = glfwCreateWindow(800, 600, "suika", nullptr, nullptr);

    glfwMakeContextCurrent(m_object);

    glfwSwapInterval(1);

    glfwSetFramebufferSizeCallback(m_object, _framebuffer_size_callback);
    glfwSetCursorPosCallback(m_object, _cursor_position_callback);
    glfwSetMouseButtonCallback(m_object, _mouse_button_callback);

    s_windows[s_window_count++] = this;
}

Window::~Window
()
{
    glfwDestroyWindow(m_object);

    glfwTerminate();
}

void Window::framebuffer_size_callback
(int width, int height)
{
    glViewport(0, 0, width, height);

    m_width  = width;
    m_height = height;
}

void Window::cursor_position_callback
(double x_position, double y_position)
{
    if
    (
        x_position != m_mouse_x_position ||
        y_position != m_mouse_y_position
    )
    {
        if (m_mouse_left_down)
        {
            // draw
        }

        m_mouse_x_position = x_position;
        m_mouse_y_position = y_position;
    }
}

void Window::mouse_button_callback
(int button, int action, int mods)
{
    // draw

    m_mouse_left_down = static_cast<bool>(action);
}

void Window::_framebuffer_size_callback
(GLFWwindow* window, int width, int height)
{
    s_windows[s_active_window]->framebuffer_size_callback(width, height);
}

void Window::_cursor_position_callback
(GLFWwindow* window, double x_position, double y_position)
{
    s_windows[s_active_window]->cursor_position_callback(x_position, y_position);
}

void Window::_mouse_button_callback
(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        s_windows[s_active_window]->mouse_button_callback(button, action, mods);
    }
}
