#include <iostream>
#include "StoryNode.h"
#include "Choice.h"

int main() {
    StoryNode* start = new StoryNode(
        1,
        "The Beginning",
        "You wake up in a dark forest. Two paths lie ahead.",
        nullptr
    );

    StoryNode* village = new StoryNode(
        2,
        "Quiet Village",
        "You reach a peaceful village. You are safe.",
        nullptr
    );

    StoryNode* dragon = new StoryNode(
        3,
        "Dragon's Lair",
        "A dragon appears. Your journey ends here.",
        nullptr
    );

    start->addChoice(new Choice(1, "Take the left path", village));
    start->addChoice(new Choice(2, "Take the right path", dragon));

    StoryNode* current = start;

    while (current) {
        current->display();

        if (current->getChoices().empty()) {
            std::cout << "\n--- THE END ---\n";
            break;
        }

        std::cout << "\nEnter choice number: ";
        int choice;
        std::cin >> choice;

        StoryNode* next = current->getNextNode(choice);
        if (!next) {
            std::cout << "Invalid choice. Try again.\n";
            continue;
        }

        current = next;
    }

    std::cout << "\nPress Enter to exit...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
