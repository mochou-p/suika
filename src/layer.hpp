// suika

#include <iostream>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include "glm/glm.hpp"

struct Path
{
    glm::vec2* positions;
};

struct Stroke
{
    Path  path;
    // Brush brush;
    glm::vec4 color;
    float thickness;
};

class Layer
{
    public:
        Layer();
        ~Layer() {};

        void render();

        Stroke* m_data;

        static void _draw(double x_position, double y_positoin);

        inline static Layer** layers = nullptr;

    private:
        void draw(double x_position, double y_positoin);

        inline static int layer_count  =  0;
        inline static int active_layer = -1;
};
