//

#pragma once

#ifndef __app_hpp_
#define __app_hpp_

#include "window.hpp"

class App
{
public:
    App();
    ~App();

    void run();

private:
    Window m_window;
};

#endif  // __app_hpp_
