// suika

#pragma once

#include "program.hpp"

#include "stb_image.h"

class Texture
{
    public:
        explicit Texture(const std::string& filename);
        ~Texture();

        unsigned int   m_id = 0;

    private:
        std::string    m_filename = "test.png";

        unsigned char* m_data     = nullptr;
        int            m_width    = 0;
        int            m_height   = 0;
        int            m_channels = 0;
};
