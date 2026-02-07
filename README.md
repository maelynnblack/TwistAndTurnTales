# TwistAndTurnTales

## Project Overview
TwistAndTurnTales is a C++ application that allows authors to create interactive, branching stories. Authors can create stories, add nodes with narrative text, define branching choices, and save different versions of a story. This project demonstrates object-oriented design with classes like `Author`, `Story`, `StoryNode`, `Choice`, and `Version`.

---

## Features
- Create authors and stories
- Add story nodes with narrative text
- Define branching choices between nodes
- Save and restore story versions
- Simple console-based demonstration of story flow

---

Example YAML file:

---

## Dependencies
- C++11 or later
- Standard C++ libraries
- **MinGW** (Windows)

## Unit Testing

This project includes unit tests to validate the core functionality of the system. Tests are written using standard C++ assert statements to ensure simplicity, clarity, and compatibility with the MinGW toolchain.

_Tested Components_

Author: Story creation and story tracking

Story: Adding and retrieving story nodes

StoryNode: Managing narrative content and choices

Choice: Linking choices to subsequent story nodes

Version: Object construction and lifecycle validation

Running Unit Tests

Each test is compiled and executed independently. From the project root directory, run the following commands:

```bash
g++ -std=c++11 -I include src/*.cpp tests/test_author.cpp -o test_author.exe
g++ -std=c++11 -I include src/*.cpp tests/test_choice.cpp -o test_choice.exe
g++ -std=c++11 -I include src/*.cpp tests/test_story.cpp -o test_story.exe
g++ -std=c++11 -I include src/*.cpp tests/test_storynode.cpp -o test_storynode.exe
g++ -std=c++11 -I include src/*.cpp tests/test_version.cpp -o test_version.exe
```

Run each test executable:
- `test_author.exe`
- `test_choice.exe`
- `test_story.exe`
- `test_storynode.exe`
- `test_version.exe`

Each test prints a confirmation message when all assertions pass.

## Compilation Instructions (Windows - MinGW)

1. Open **Command Prompt** or **Git Bash**.
2. Navigate to the project root directory (where `main.cpp` and `include/` folder are located).
3. Run the following command:
```bash
g++ -std=c++11 -I include src/*.cpp main.cpp -o TwistAndTurnTales.exe
```
This compiles all .cpp files and produces TwistAndTurnTales.exe.

Run the program:

`TwistAndTurnTales.exe`

## Running the Application

After compilation, running the executable will:

Create an author and a story.

Add story nodes and branching choices.

Save an initial version of the story.

Print story information, node titles, choices, and restored version info.

Example output:

Author: Maelynn Black
Story: The Dark Forest Adventure
Starting Node: Start
Choices from start:
 - Go left -> Left Path
 - Go right -> Right Path
 - Restored Story: The Dark Forest Adventure (Version: Initial Version)

## Future Enhancements

1. GUI-based story editor with drag-and-drop node linking
2. Deep copy of story snapshots for full version restore
3. Export stories to JSON or XML
4. Interactive story navigation with user input