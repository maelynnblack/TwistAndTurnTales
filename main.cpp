#include <iostream>
#include "Author.h"
#include "Story.h"
#include "StoryNode.h"
#include "Choice.h"
#include "Version.h"

int main() {
    // Create an Author
    Author* author = new Author(1, "Maelynn Black", "maelynn@example.com", "Writer");

    // Create a Story
    Story* story = author->createStory("The Dark Forest Adventure");

    // Create StoryNodes
    StoryNode* node1 = new StoryNode(101, "Start", "You wake up in a dark forest.", story);
    StoryNode* node2 = new StoryNode(102, "Left Path", "You take the left path and hear a river.", story);
    StoryNode* node3 = new StoryNode(103, "Right Path", "You take the right path and see a cave.", story);

    // Add nodes to Story
    story->addNode(node1);
    story->addNode(node2);
    story->addNode(node3);

    // Create Choices for branching
    Choice* choice1 = new Choice(201, "Go left");
    Choice* choice2 = new Choice(202, "Go right");

    choice1->setNextNode(node2);
    choice2->setNextNode(node3);

    // Add choices to starting node
    node1->addChoice(choice1);
    node1->addChoice(choice2);

    // Save a version of the story
    Version* version1 = story->createVersion("Initial Version");

    // Print story information
    std::cout << "Author: " << author->getName() << std::endl;
    std::cout << "Story: " << story->getTitle() << std::endl;
    std::cout << "\nStory Nodes and Choices:" << std::endl;

    // Dynamically list all nodes and their choices
    for (auto node : story->getNodes()) {
        std::cout << "- Node: " << node->getTitle() << "\n  Narrative: " << node->getNarrativeText() << std::endl;
        if (!node->getChoices().empty()) {
            std::cout << "  Choices:" << std::endl;
            for (auto choice : node->getChoices()) {
                std::cout << "   - " << choice->getDescription()
                    << " -> " << choice->getNextNode()->getTitle() << std::endl;
            }
        }
        std::cout << std::endl;
    }

    // Demonstrate restoring a story version
    Story* restored = version1->restore();
    std::cout << "Restored Story: " << restored->getTitle()
        << " (Version: " << version1->getLabel() << ")" << std::endl;

    // Pause before exit
    std::cout << "\nPress Enter to exit...";
    std::cin.get();

    // Clean up dynamic memory
    delete version1;
    delete choice1;
    delete choice2;
    delete node1;
    delete node2;
    delete node3;
    delete story;
    delete author;

    return 0;
}
