// suika

#define STB_IMAGE_IMPLEMENTATION
#include "texture.hpp"

Texture::Texture
(const std::string& filename)
{
    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,     GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,     GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    m_filename = "res/images/" + filename;

    stbi_set_flip_vertically_on_load(1);

    m_data = stbi_load(m_filename.c_str(), &m_width, &m_height, &m_channels, 0);

    if (m_data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "failed to load " << filename << std::endl;
    }
}

Texture::~Texture
()
{
    free(m_data);
}
