#pragma once
#include <string>
#include <vector>

// Forward declarations
class StoryNode;
class Author;
class Version;

class Story {
private:
    int storyId;
    std::string title;
    std::vector<StoryNode*> nodes;
    Author* author;

public:
    Story(int id, const std::string& title, Author* author);

    void addNode(StoryNode* node);
    StoryNode* getNodeById(int id) const;
};
