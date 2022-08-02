// suika

#include "layer.hpp"

Layer::Layer
()
{
    s_layers[s_layer_count++] = this;
}

void Layer::_draw
(int status, double x_position, double y_position)
{
    Layer*  l = s_layers[s_active_layer];
    Stroke* s = l->m_strokes;
    void* vpi = &l->m_stroke_count;
    int     i = *static_cast<int*>(vpi);

    switch (status)
    {
        case START:
            s[i] = Stroke({x_position, y_position, 0.0}, {1.0, 0.0, 0.0, 1.0}, 5.0);
            break;

        case CONTINUE:
            s[i].add_to_path({x_position, y_position, 0.0});
            break;

        case STOP:
            ++(*static_cast<int*>(vpi));
            break;

        default:
            break;
    }
}
