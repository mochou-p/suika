// suika

#pragma once

#include "GLFW/glfw3.h"

#include <iostream>

class Window
{
    public:
        Window();
        ~Window();

        GLFWwindow* m_window;

    private:
        void framebuffer_size_callback(int width, int height);
        void cursor_position_callback(double xpos, double ypos);
        void mouse_button_callback(int button, int action, int mods);

        double m_mouse_x_position, m_mouse_y_position;
        bool   m_mouse_left_down;

        static void _framebuffer_size_callback(GLFWwindow* window, int width, int height);
        static void _cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
        static void _mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

        inline static Window** windows = nullptr;
        inline static int window_count = 0;
};
