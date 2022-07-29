// suika

#pragma once

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include "glm/glm.hpp"

#include <iostream>

class Stroke
{
    public:
        Stroke(glm::vec2 xy, glm::vec4 color, float thickness);
        ~Stroke() {};

        void path(glm::vec2 xy);
        void debug() const;

    private:
        glm::vec2* m_path;
        int        m_length;
        glm::vec4  m_color;
        float      m_thickness;
};
