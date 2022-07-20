// suika

#include "window.hpp"

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

class Ui
{
    public:
        Ui(Window window);
        ~Ui();

        void render();
};
