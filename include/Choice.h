#pragma once
#include <string>

// Forward declaration
class StoryNode;

class Choice {
private:
    int choiceId;
    std::string description;
    StoryNode* nextNode;

public:
    // Constructor
    Choice(int id, const std::string& desc);

    // Getters/Setters
    int getChoiceId() const;
    std::string getDescription() const;
    void setDescription(const std::string& desc);

    void setNextNode(StoryNode* node);
    StoryNode* getNextNode() const;
};
