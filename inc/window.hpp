//

#pragma once

#ifndef __window_hpp_
#define __window_hpp_

#include "GLFW/glfw3.h"

#include <string>

class Window
{
public:
    Window(std::string);
    ~Window();

    GLFWwindow* m_handle;
};

#endif  // __window_hpp_
