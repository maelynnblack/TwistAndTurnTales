#include "Choice.h"
#include "StoryNode.h"

Choice::Choice(int id, const std::string& desc)
    : choiceId(id), description(desc), nextNode(nullptr) {
}

int Choice::getChoiceId() const { return choiceId; }
std::string Choice::getDescription() const { return description; }
void Choice::setDescription(const std::string& desc) { description = desc; }

void Choice::setNextNode(StoryNode* node) { nextNode = node; }
StoryNode* Choice::getNextNode() const { return nextNode; }
