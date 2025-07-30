#ifndef SED_IS_FOR_LOSERS_HPP
#define SED_IS_FOR_LOSERS_HPP

#include <iostream>
#include <string>
#include <fstream>

std::string read_content(std::ifstream &file);
std::string replace_content(std::string content, const std::string &s1, const std::string &s2);

#endif