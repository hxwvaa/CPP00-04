#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

int main(int argc, char **argv)
{
    if(argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        for(int i = 1; i < argc; i++)
        {
            for(size_t j = 0; j < std::strlen(argv[i]); j++)
                std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
        }
        std::cout << "\n";
    }
}