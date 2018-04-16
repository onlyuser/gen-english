#ifndef UTIL_H
#define UTIL_H

#include <string>

std::string replace(std::string &s, std::string find_string, std::string replace_string);
std::string apply_contractions(std::string &s);

#endif
