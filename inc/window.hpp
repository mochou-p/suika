//

#pragma once

#ifndef __window_hpp_
#define __window_hpp_

#include "GLFW/glfw3.h"

class Window
{
public:
    Window();
    ~Window();

    GLFWwindow* m_handle;

private:
    inline static bool glfw_initialised;
};

#endif  // __window_hpp_
