#pragma once

#include <string>

#define CHECK_EMPTY_STR(x) checkEmptyString(x, #x, __FILE__, __LINE__)

bool checkEmptyString(const std::string& str, const std::string& name, const std::string& file, int line);
void replaceSubString(std::string& src, const std::string& s1, const std::string& s2);
