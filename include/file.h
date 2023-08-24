#include <string>

std::string get_shader(const std::string &name) {
    std::string p = "/Users/pan/workspace_cxx/learn-opengl/resources/shaders/" + name;
    return p;
}

std::string get_texture(const std::string &name) {
    std::string p = "/Users/pan/workspace_cxx/learn-opengl/resources/textures/" + name;
    return p;
}

std::string get_model(const std::string &name) {
    std::string p = "/Users/pan/workspace_cxx/learn-opengl/resources/" + name;
    return p;
}