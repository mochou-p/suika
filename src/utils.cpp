// suika

#include "utils.hpp"

std::string read_file
(const std::string& filename)
{
    std::ifstream file("res/shaders/" + filename);

    if (!file.is_open())
    {
        std::cout << "file res/shaders/" << filename << " does not exist" << std::endl;
    }

    std::string content;

    std::getline(file, content, '\0');

    return content;
}
