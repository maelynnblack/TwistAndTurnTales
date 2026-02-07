#include "Story.h"
#include "StoryNode.h"

Story::Story(int id, const std::string& title, Author* author)
    : storyId(id), title(title), author(author) {}

void Story::addNode(StoryNode* node) {
    nodes.push_back(node);
}

StoryNode* Story::getNodeById(int id) const {
    for (StoryNode* node : nodes) {
        if (node->getNodeId() == id) {
            return node;
        }
    }
    return nullptr;
}
