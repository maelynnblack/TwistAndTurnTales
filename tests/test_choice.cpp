#include <cassert>
#include <iostream>

#include "../include/Choice.h"
#include "../include/StoryNode.h"
#include "../include/Story.h"
#include "../include/Author.h"

void testChoiceAccessors() {
    Author author(1, "Maelynn Black", "test@email.com");
    Story story(1, "Adventure", &author);
    StoryNode node(1, "Node", "Text", &story);

    Choice choice(1, "Select this", &node);

    assert(choice.getChoiceId() == 1);
    assert(choice.getText() == "Select this");
    assert(choice.getNextNode() == &node);
}

int main() {
    testChoiceAccessors();
    std::cout << "Choice tests passed\n";
    std::cout << "Press Enter to exit...";
    std::cin.get(); // waits for you to press Enter
    return 0;
}
