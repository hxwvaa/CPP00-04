#include "sed_is_for_losers.hpp"

std::string read_content(std::ifstream &file) {
    std::string content;
    std::string line;
    while (std::getline(file, line)) {
        content += line + "\n";
    }
    return content;
}

std::string replace_content(std::string content, const std::string &s1, const std::string &s2) {
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
    return content;
}
