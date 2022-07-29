// suika

#pragma once

#include "stroke.hpp"

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

        static void _draw(int status, double x_position, double y_position);

        inline static Layer** layers = nullptr;

        void render();

        Stroke* m_strokes;

        int stroke_count = 0;

    private:
        void start_drawing(double x_position, double y_position);
        void continue_drawing(double x_position, double y_position);
        void debug() const;

        inline static int layer_count  = 0;
        inline static int active_layer = 0;
};
