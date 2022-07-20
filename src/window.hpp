// suika

#include "GLFW/glfw3.h"

class Window
{
    public:
        Window();
        ~Window();

        GLFWwindow* m_window;

    private:
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

        const unsigned short int m_width  = 800;
        const unsigned short int m_height = 600;
};
