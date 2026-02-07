#include "Author.h"

Author::Author(int id, const std::string& name, const std::string& email)
    : authorId(id), name(name), email(email) {}

int Author::getAuthorId() const {
    return authorId;
}

std::string Author::getName() const {
    return name;
}
