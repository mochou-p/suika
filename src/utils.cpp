// suika

#include "utils.hpp"

const char* read_file
(std::string filename)
{
    std::string content;
    std::ifstream file("res/shaders/" + filename);

    std::getline(file, content, '\0');

    return content.c_str();
}
