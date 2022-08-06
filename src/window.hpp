// suika

#pragma once

#include "GLFW/glfw3.h"

class Window
{
    public:
        Window();
        ~Window();

        inline bool opened()       { return !glfwWindowShouldClose(m_object); }
        inline void swap_buffers() {         glfwSwapBuffers(m_object);       }
        inline void poll_events()  {         glfwPollEvents();                }

        GLFWwindow* m_object = nullptr;

        int m_width  = 0;
        int m_height = 0;

    private:
        void framebuffer_size_callback(int    width,  int    height);
        void  cursor_position_callback(double xpos,   double ypos);
        void     mouse_button_callback(int    button, int    action, int mods);

        double m_mouse_x_position = 0.0;
        double m_mouse_y_position = 0.0;
        bool   m_mouse_left_down  = false;

    public:
        inline static Window* s_windows[2] = {nullptr, nullptr};

    private:
        inline static void _framebuffer_size_callback(GLFWwindow* window, int    width,  int    height);
        inline static void  _cursor_position_callback(GLFWwindow* window, double xpos,   double ypos);
        inline static void     _mouse_button_callback(GLFWwindow* window, int    button, int    action, int mods);

        inline static int s_window_count  = 0;
        inline static int s_active_window = 0;
};
