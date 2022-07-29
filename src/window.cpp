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

    glfwSetFramebufferSizeCallback(m_window, _framebuffer_size_callback);
    glfwSetCursorPosCallback(m_window, _cursor_position_callback);
    glfwSetMouseButtonCallback(m_window, _mouse_button_callback);

    if (windows == nullptr)
    {
        windows = (Window**) malloc(1 + window_count * sizeof(Window));
    }
    else
    {
        windows = (Window**) realloc(windows, 1 + window_count * sizeof(Window));
    }

    windows[window_count++] = this;
}

Window::~Window
()
{
    glfwDestroyWindow(m_window);

    glfwTerminate();
}

void Window::framebuffer_size_callback
(int width, int height)
{
    glfwMakeContextCurrent(m_window);

    glViewport(0, 0, width, height);
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
            Layer::_draw(CONTINUE, x_position, y_position);
        }

        m_mouse_x_position = x_position;
        m_mouse_y_position = y_position;
    }
}

void Window::mouse_button_callback
(int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        Layer::_draw(action, m_mouse_x_position, m_mouse_y_position);

        m_mouse_left_down = (bool) action;
    }
}

void Window::_framebuffer_size_callback
(GLFWwindow* window, int width, int height)
{
    for (int i = 0; i <= window_count; i++)
    {
        if (window == Window::windows[i]->m_window)
        {
            windows[i]->framebuffer_size_callback(width, height);
        }
    }
}

void Window::_cursor_position_callback
(GLFWwindow* window, double x_position, double y_position)
{
    for (int i = 0; i <= window_count; i++)
    {
        if (window == windows[i]->m_window)
        {
            windows[i]->cursor_position_callback(x_position, y_position);
        }
    }
}

void Window::_mouse_button_callback
(GLFWwindow* window, int button, int action, int mods)
{
    for (int i = 0; i <= window_count; i++)
    {
        if (window == windows[i]->m_window)
        {
            windows[i]->mouse_button_callback(button, action, mods);
        }
    }
}
