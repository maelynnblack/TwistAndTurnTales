#pragma once
#include <string>

// Forward declaration
class StoryNode;

class Choice {
private:
    int choiceId;
    std::string text;
    StoryNode* nextNode;

public:
    Choice(int id, const std::string& text, StoryNode* next);

    int getChoiceId() const;
    std::string getText() const;
    StoryNode* getNextNode() const;
};
