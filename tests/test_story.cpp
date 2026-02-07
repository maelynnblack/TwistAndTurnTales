#include <cassert>
#include <iostream>

#include "../include/Story.h"
#include "../include/StoryNode.h"
#include "../include/Author.h"

void testAddAndRetrieveNode() {
    Author author(1, "Maelynn Black", "test@email.com");
    Story story(1, "Test Story", &author);

    StoryNode node(1, "Start", "Beginning", &story);
    story.addNode(&node);

    StoryNode* retrieved = story.getNodeById(1);

    assert(retrieved != nullptr);
    assert(retrieved->getNodeId() == 1);
}

int main() {
    testAddAndRetrieveNode();
    std::cout << "Story tests passed\n";
    std::cout << "Press Enter to exit...";
    std::cin.get(); // waits for you to press Enter
    return 0;
}
