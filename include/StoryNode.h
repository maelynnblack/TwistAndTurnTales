#pragma once
#include <string>
#include <vector>

// Forward declarations
class Story;
class Choice;

class StoryNode {
private:
    int nodeId;
    std::string title;
    std::string narrativeText;
    std::vector<Choice*> choices;
    Story* parentStory;

public:
    StoryNode(int id, const std::string& title,
              const std::string& text,
              Story* parent);

    int getNodeId() const;
    std::string getTitle() const;
    std::string getNarrativeText() const;

    void addChoice(Choice* choice);
    std::vector<Choice*> getChoices() const;
    StoryNode* getNextNode(int choiceId);

    void display() const;
};
