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
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
};
