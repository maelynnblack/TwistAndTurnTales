#include <cassert>
#include <iostream>

#include "../include/Version.h"

void testVersionConstruction() {
    Version version(1, "Initial Version");

    // If construction succeeds, the test passes
    assert(true);
}

int main() {
    testVersionConstruction();
    std::cout << "Version tests passed\n";
    std::cout << "Press Enter to exit...";
    std::cin.get(); // waits for you to press Enter
    return 0;
}
