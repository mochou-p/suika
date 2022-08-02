// suika

#pragma once

#include "glm/glm.hpp"

#include <iostream>

struct Stroke
{
    Stroke
    (
        glm::vec3 xyz   = {0, 0, 0},
        glm::vec4 color = {0, 0, 0, 0},
        float thickness = 0
    )
    : m_color     (color)
    , m_thickness {thickness}
    {
        add_to_path(xyz);
    }

    inline void add_to_path(glm::vec3 xyz) { m_path[m_length++] = xyz; }

    private:
        glm::vec3  m_path[512];
        int        m_length = 0;
        glm::vec4  m_color;
        float      m_thickness;
};

enum Status
{
    STOP,
    START,
    CONTINUE
};

class Layer
{
    public:
        Layer();
        ~Layer() {};

        Stroke m_strokes[10];

        int m_stroke_count = 0;

    public:
        static void _draw(int status, double x_position, double y_position);

        inline static Layer* s_layers[2] = {nullptr, nullptr};

    private:
        inline static int s_layer_count  = 0;
        inline static int s_active_layer = 0;
};
