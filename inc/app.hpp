//

#pragma once

#ifndef __app_hpp_
#define __app_hpp_

#include "GLFW/glfw3.h"

class App
{
public:
    App();
    ~App();

    void run();

private:
    GLFWwindow* m_window;
};

#endif  // __app_hpp_
