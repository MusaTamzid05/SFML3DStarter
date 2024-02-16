#include "utils.h"
#include <fstream>
#include <iostream>
#include "headers.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


std::string read_file(const std::string& path) {
    std::ifstream input_file(path);

    if(!input_file.is_open()) {
        std::cerr << "Could not open " << path << "\n";
        exit(2);
    }

    std::string text = "";
    std::string line;

    while(std::getline(input_file, line)) 
        text += line + "\n";

    input_file.close();

    return text;

}


unsigned int load_texture(const std::string& path) {
    stbi_set_flip_vertically_on_load(true);

    unsigned int texture_id;
    glGenTextures(1, &texture_id);
    
    int width, height, nr_components;
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nr_components, 0);
    if (data)
    {
        GLenum format;
        if (nr_components == 1)
            format = GL_RED;
        else if (nr_components == 3)
            format = GL_RGB;
        else if (nr_components == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, texture_id);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return texture_id;

}
