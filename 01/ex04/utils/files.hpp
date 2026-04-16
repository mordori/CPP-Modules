#pragma once

#include <string>

bool readFileToString(std::string& src, const std::string& fileName);
bool writeStringToFile(const std::string& src, const std::string& fileName);
