#include <cassert>
#include <iostream>

#include "../include/StoryNode.h"
#include "../include/Choice.h"
#include "../include/Story.h"
#include "../include/Author.h"

void testStoryNodeChoices() {
    Author author(1, "Maelynn Black", "test@email.com");
    Story story(1, "Adventure", &author);

    StoryNode start(1, "Start", "Beginning", &story);
    StoryNode next(2, "Next", "Next scene", &story);

    Choice choice(1, "Go forward", &next);
    start.addChoice(&choice);

    assert(start.getChoices().size() == 1);
    assert(start.getNextNode(1) == &next);
}

int main() {
    testStoryNodeChoices();
    std::cout << "Story node tests passed\n";
    std::cout << "Press Enter to exit...";
    std::cin.get(); // waits for you to press Enter
    return 0;
}
