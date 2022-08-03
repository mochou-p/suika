// suika

#include "utils.hpp"

std::string read_file
(const std::string& filename)
{
    std::ifstream file("res/shaders/" + filename);

    assert(file.is_open());

    std::string content;

    std::getline(file, content, '\0');

    return content;
}
