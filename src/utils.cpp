// suika

#include "utils.hpp"

std::string read_file
(const std::string& filename)
{
    std::string content;
    std::ifstream file("res/shaders/" + filename);

    std::getline(file, content, '\0');

    return content;
}
