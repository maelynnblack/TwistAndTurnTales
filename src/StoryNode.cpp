#include "StoryNode.h"
#include "Choice.h"
#include <iostream>

StoryNode::StoryNode(int id, const std::string& title,
                     const std::string& text,
                     Story* parent)
    : nodeId(id), title(title), narrativeText(text), parentStory(parent) {}

int StoryNode::getNodeId() const {
    return nodeId;
}

std::string StoryNode::getTitle() const {
    return title;
}

std::string StoryNode::getNarrativeText() const {
    return narrativeText;
}

void StoryNode::addChoice(Choice* choice) {
    choices.push_back(choice);
}

std::vector<Choice*> StoryNode::getChoices() const {
    return choices;
}

StoryNode* StoryNode::getNextNode(int choiceId) {
    for (Choice* c : choices) {
        if (c->getChoiceId() == choiceId) {
            return c->getNextNode();
        }
    }
    return nullptr;
}

void StoryNode::display() const {
    std::cout << "\n=== " << title << " ===\n";
    std::cout << narrativeText << "\n\n";

    for (Choice* c : choices) {
        std::cout << c->getChoiceId()
                  << ". " << c->getText() << "\n";
    }
}
