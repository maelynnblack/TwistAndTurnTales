#include "Choice.h"

Choice::Choice(int id, const std::string& text, StoryNode* next)
    : choiceId(id), text(text), nextNode(next) {}

int Choice::getChoiceId() const {
    return choiceId;
}

std::string Choice::getText() const {
    return text;
}

StoryNode* Choice::getNextNode() const {
    return nextNode;
}
