// suika

#pragma once

#include "window.hpp"

class Ui
{
    public:
        Ui(Window* window);
        ~Ui();

        void render() const;
};
