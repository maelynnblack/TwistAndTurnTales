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
    // Constructor
    StoryNode(int id, const std::string& t, const std::string& text, Story* parent);

    // Getters/Setters
    int getNodeId() const;
    std::string getTitle() const;
    void setTitle(const std::string& t);
    std::string getNarrativeText() const;
    void setNarrativeText(const std::string& text);
    Story* getParentStory() const;

    // Choice management
    void addChoice(Choice* choice);
    void removeChoice(int choiceId);
    std::vector<Choice*> getChoices() const;
    StoryNode* getNextNode(int choiceId);
};
