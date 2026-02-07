#include "Story.h"
#include "StoryNode.h"
#include "Version.h"
#include <algorithm>

Story::Story(int id, const std::string& t, Author* a)
    : storyId(id), title(t), author(a) {
}

int Story::getStoryId() const { return storyId; }
std::string Story::getTitle() const { return title; }
void Story::setTitle(const std::string& t) { title = t; }
Author* Story::getAuthor() const { return author; }

void Story::addNode(StoryNode* node) {
    if (node) nodes.push_back(node);
}

void Story::removeNode(int nodeId) {
    nodes.erase(std::remove_if(nodes.begin(), nodes.end(),
        [nodeId](StoryNode* n) { return n->getNodeId() == nodeId; }),
        nodes.end());
}

StoryNode* Story::getNodeById(int nodeId) {
    for (auto* node : nodes) {
        if (node->getNodeId() == nodeId) return node;
    }
    return nullptr;
}

std::vector<StoryNode*> Story::getNodes() const { return nodes; }

Version* Story::createVersion(const std::string& label) {
    int newId = versions.size() + 1;
    Version* v = new Version(newId, this, label, author);
    versions.push_back(v);
    return v;
}

Version* Story::getCurrentVersion() const {
    if (versions.empty()) return nullptr;
    return versions.back();
}
