// suika

#pragma once

#include "program.hpp"

#include "stb_image.h"

class Texture
{
    public:
        explicit Texture(const std::string& filename);
        ~Texture();

        unsigned int   m_id;

        std::string    m_filename;

        unsigned char* m_data;
        int            m_width;
        int            m_height;
        int            m_channels;
};
