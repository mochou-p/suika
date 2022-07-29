// suika

#include "stroke.hpp"

Stroke::Stroke
(glm::vec2 xy, glm::vec4 color, float thickness)
{
    m_length    = 0;
    m_color     = color;
    m_thickness = thickness;
    path(xy);

    debug();
}

void Stroke::path
(glm::vec2 xy)
{
    m_path[m_length] = xy;
}

void Stroke::debug
() const
{
    for (int i = 0; i <= m_length; i++)
    {
        std::cout << "\n\npath[" << i << "]   = " << m_path[i].x << ", " << m_path[i].y;
    }
    std::cout << "\nlength    = " << m_length;
    std::cout << "\ncolor     = " << m_color.r << ", " << m_color.g << ", " << m_color.b << ", " << m_color.a;
    std::cout << "\nthickness = " << m_thickness;
}
