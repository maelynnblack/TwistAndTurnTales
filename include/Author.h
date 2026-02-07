#pragma once
#include <string>
#include <vector>

// Forward declarations
class Story;
class Version;

class Author {
private:
    int authorId;
    std::string name;
    std::string email;
    std::string role;
    std::vector<Story*> activeStories;

public:
    // Constructors
    Author(int id, const std::string& n, const std::string& e, const std::string& r);

    // Getters/Setters
    int getAuthorId() const;
    std::string getName() const;
    void setName(const std::string& n);
    std::string getEmail() const;
    void setEmail(const std::string& e);
    std::string getRole() const;
    void setRole(const std::string& r);

    // Story management
    void addStory(Story* story);
    std::vector<Story*> getActiveStories() const;
    Story* createStory(const std::string& title);
    void editStory(Story* story, const std::string& newTitle);
    Version* saveStoryVersion(Story* story, const std::string& label);
};
