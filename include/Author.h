#pragma once
#include <string>
#include <vector>

// Forward declaration
class Story;
class Version;

class Author {
private:
    int authorId;
    std::string name;
    std::string email;

public:
    Author(int id, const std::string& name, const std::string& email);

    int getAuthorId() const;
    std::string getName() const;
};
