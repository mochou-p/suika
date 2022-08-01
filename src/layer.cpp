// suika

#include "layer.hpp"

Layer::Layer
()
{
    layers[layer_count++] = this;
}

void Layer::start_drawing
(double x_position, double y_position)
{
    m_strokes[stroke_count] = Stroke({x_position, y_position, 0.0}, {1.0, 0.0, 0.0, 1.0}, 5.0);
}

void Layer::continue_drawing
(double x_position, double y_position)
{
    m_strokes[stroke_count].add_to_path({x_position, y_position, 0.0});
}

void Layer::debug
() const
{
    for (int i = 0; i <= stroke_count; i++)
    {
        std::cout << "\n\npath      =";
        for (int j = 0; j < m_strokes[i].m_length; j++)
        {
            std::cout << " {" << m_strokes[i].m_path[j].x << "," << m_strokes[i].m_path[j].y << "," << m_strokes[i].m_path[j].z << "}";
        }
        std::cout << "\nlength    = " << m_strokes[i].m_length;
        std::cout << "\ncolor     = {" << m_strokes[i].m_color.r << "," << m_strokes[i].m_color.g << "," << m_strokes[i].m_color.b << "," << m_strokes[i].m_color.a << "}";
        std::cout << "\nthickness = " <<m_strokes[i].m_thickness;
    }
}

void Layer::_draw
(int status, double x_position, double y_position)
{
    switch (status)
    {
        case START:
            layers[active_layer]->start_drawing(x_position, y_position);
            break;

        case CONTINUE:
            layers[active_layer]->continue_drawing(x_position, y_position);
            break;

        case STOP:
            layers[active_layer]->debug();
            //layers[active_layer]->stroke_count++;
            break;

        default:
            break;
    }
}
