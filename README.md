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

---

## Compilation Instructions (Windows - MinGW)

1. Open **Command Prompt** or **Git Bash**.
2. Navigate to the project root directory (where `main.cpp` and `include/` folder are located).
3. Run the following command:
```bash
g++ -std=c++11 -I include src/*.cpp main.cpp -o TwistAndTurnTales.exe
```
This compiles all .cpp files and produces TwistAndTurnTales.exe.

Run the program:

TwistAndTurnTales.exe


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
Restored Story: The Dark Forest Adventure (Version: Initial Version)

Future Enhancements

GUI-based story editor with drag-and-drop node linking

Deep copy of story snapshots for full version restore

Export stories to JSON or XML

Interactive story navigation with user input