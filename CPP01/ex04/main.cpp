#include "sed_is_for_losers.hpp"

int main(int ac, char **av) {

    if (ac != 4) {
        std::cout << "Error: ./sed_is_for_losers <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty()) {
        std::cout << "Error: s1 cannot be empty." << std::endl;
        return 1;
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cout << "Error: Could not open file " << filename << std::endl;
        return 1;
    }
    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile) {
        std::cout << "Error: Could not open file." << std::endl;
        return 1;
    }

    std::string content = read_content(inputFile);
    if (content.empty()) {
        std::cout << "Error: File is empty." << std::endl;
        return 1;
    }
    std::string replacedContent = replace_content(content, s1, s2);
    
    outputFile << replacedContent;

    inputFile.close();
    outputFile.close();

    return 0;
}