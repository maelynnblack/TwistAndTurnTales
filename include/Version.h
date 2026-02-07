#pragma once
#include <string>

// Forward declaration
class Story;
class Author;

class Version {
private:
    int versionId;
    std::string label;

public:
    Version(int id, const std::string& label);
};
