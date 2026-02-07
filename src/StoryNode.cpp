#include "StoryNode.h"
#include "Choice.h"
#include <algorithm>

StoryNode::StoryNode(int id, const std::string& t, const std::string& text, Story* parent)
    : nodeId(id), title(t), narrativeText(text), parentStory(parent) {
}

int StoryNode::getNodeId() const { return nodeId; }
std::string StoryNode::getTitle() const { return title; }
void StoryNode::setTitle(const std::string& t) { title = t; }
std::string StoryNode::getNarrativeText() const { return narrativeText; }
void StoryNode::setNarrativeText(const std::string& text) { narrativeText = text; }
Story* StoryNode::getParentStory() const { return parentStory; }

void StoryNode::addChoice(Choice* choice) {
    if (choice) choices.push_back(choice);
}

void StoryNode::removeChoice(int choiceId) {
    choices.erase(std::remove_if(choices.begin(), choices.end(),
        [choiceId](Choice* c) { return c->getChoiceId() == choiceId; }),
        choices.end());
}

std::vector<Choice*> StoryNode::getChoices() const {
    return choices;
}

StoryNode* StoryNode::getNextNode(int choiceId) {
    for (auto* c : choices) {
        if (c->getChoiceId() == choiceId) {
            return c->getNextNode();
        }
    }
    return nullptr;
}
