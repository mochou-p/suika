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

    layers[layer_count++] = this;
}

void Layer::start_drawing
(double x_position, double y_position)
{
    std::cout << "A";
    m_strokes[stroke_count] = Stroke({x_position, y_position}, {1.0, 0.0, 0.0, 1.0}, 5.0);
    std::cout << "B";
}

void Layer::continue_drawing
(double x_position, double y_position)
{
    //  
}

void Layer::debug
() const
{
    std::cout << ":D";
}

void Layer::render
()
{
    // POSSIBLE ?IMPROVEMENT?
    // - probably just take every .x and .y from m_strokes.path[i]
    //   and make them into circles depending on m_strokes.thickness with geometry shader
    // - layout (location = x) color, for fragment shader, from m_strokes.color

    //
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
            //layers[active_layer]->continue_drawing(x_position, y_position);
            break;

        case STOP:
            //layers[active_layer]->debug();
            //layers[active_layer]->stroke_count++;
            break;

        default:
            break;
    }
}
