// suika

#pragma once

#include "window.hpp"

class Ui
{
    public:
        explicit Ui(GLFWwindow* window);
        ~Ui();

        void render() const;
};
