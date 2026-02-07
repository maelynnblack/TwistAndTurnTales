#include <cassert>
#include <iostream>

#include "../include/Author.h"

void testAuthorConstruction() {
    Author author(1, "Maelynn Black", "test@email.com");

    // If construction succeeds, the test passes
    assert(true);
}

int main() {
    testAuthorConstruction();
    std::cout << "Author tests passed\n";
    std::cout << "Press Enter to exit...";
    std::cin.get(); // waits for you to press Enter
    return 0;
}
