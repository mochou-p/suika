// suika

#include "layer.hpp"

Layer::Layer
()
{
    if (layers == nullptr)
    {
        layers = (Layer**) malloc(1 + layer_count * sizeof(Layer));
    }
    else
    {
        layers = (Layer**) realloc(layers, 1 + layer_count * sizeof(Layer));
    }

    layer_count++;
    active_layer++;
}

void Layer::draw
(double x_position, double y_position)
{
    // do things with m_data

    //
}

void Layer::render
()
{
    // POSSIBLE ?IMPROVEMENT?
    // - probably just take every .x and .y from m_data.path[i]
    //   and make them into circles depending on m_data.thickness with geometry shader
    // - layout (location = x) color, for fragment shader, from m_data.color

    //
}

void Layer::_draw
(double x_position, double y_position)
{
    layers[active_layer]->draw(x_position, y_position);
}
