#pragma once
#include <string>
#include <vector>

// Forward declarations
class StoryNode;
class Version;
class Author;

class Story {
private:
    int storyId;
    std::string title;
    std::vector<StoryNode*> nodes;
    std::vector<Version*> versions;
    Author* author;
    std::string creationDate; // Simplified for console app

public:
    // Constructor
    Story(int id, const std::string& t, Author* a);

    // Getters/Setters
    int getStoryId() const;
    std::string getTitle() const;
    void setTitle(const std::string& t);
    Author* getAuthor() const;

    // Node management
    void addNode(StoryNode* node);
    void removeNode(int nodeId);
    StoryNode* getNodeById(int nodeId);
    std::vector<StoryNode*> getNodes() const;

    // Version management
    Version* createVersion(const std::string& label);
    Version* getCurrentVersion() const;
};
