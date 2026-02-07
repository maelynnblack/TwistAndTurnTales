# Class Diagram Design
Key Concepts from Use Cases: \
-	**Story**: contains multiple nodes, has a version history.
-	**StoryNode**: has narrative text, title, unique ID, branching choices.
-	**Version**: snapshot of a story at a point in time.
-	**Author**: can create/edit stories.
-	**Choice**: links nodes for branching stories.
### Proposed Classes
1. **Author** \
    _Attributes_:
    - authorId: int
    - name: String
    - email: String
    - role: String
    - activeStories: List<Story>

    _Getters/Setters_ for all attributes

    _Methods_:
    - createStory(title: String): Story
    - editStory(story: Story): void
    - saveStoryVersion(story: Story): Version
    - addNodeToStory(story: Story, node: StoryNode): void
    - viewStoryVersions(story: Story): List<Version>
________________________________________

2. **Story** \
    _Attributes_:
    - storyId: int
    - title: String
    - nodes: List<StoryNode>
    - versions: List<Version>
    - author: Author
    - creationDate: Date

    _Getters/Setters_

    _Methods_:
    - addNode(node: StoryNode): void
    - removeNode(nodeId: int): void
    - getNodeById(nodeId: int): StoryNode
    - createVersion(): Version
    - getCurrentVersion(): Version
________________________________________

3. **StoryNode** \
    _Attributes_:
    - nodeId: int
    - title: String
    - narrativeText: String
    - choices: List<Choice>
    - timestamp: Date
    - parentStory: Story

    _Getters/Setters_

    _Methods_:
    - addChoice(choice: Choice): void
    - removeChoice(choiceId: int): void
    - editNarrative(newText: String): void
    - validateNode(): Boolean
    - getNextNode(choiceId: int): StoryNode
________________________________________

4. **Choice** \
    _Attributes_:
    - choiceId: int
    - description: String
    - nextNode: StoryNode

    _Getters/Setters_

    _Methods_:
    - setNextNode(node: StoryNode): void
    - getNextNode(): StoryNode
    - validateChoice(): Boolean
________________________________________

5. **Version** \
    _Attributes_:
    - versionId: int
    - storySnapshot: Story
    - timestamp: Date
    - label: String
    - author: Author

    _Getters/Setters_

    _Methods_:
    - restore(): Story
    - compare(otherVersion: Version): String
    - saveSnapshot(): void
    - validateVersion(): Boolean
________________________________________

### Class Diagram Relationships
•	Author → Story (1 Author → many Stories) \
•	Story → StoryNode (1 Story → many Nodes) \
•	Story → Version (1 Story → many Versions) \
•	StoryNode → Choice (1 Node → many Choices) \
•	Choice → StoryNode (1 Choice → 1 NextNode) \
•	Version → Story (snapshot relationship) \
________________________________________

## Sequence Diagram for UC-FR2 (Add Story Node)
_Actors_: Author, StoryEditorSystem \
_Steps_:
1.	Author opens Story Editor.
2.	System displays story structure.
3.	Author clicks "Add Node".
4.	System displays Node Form.
5.	Author enters title, narrative text, optional attributes.
6.	System validates input.
7.	System assigns Node ID.
8.	System saves node to database and updates Story object.
9.	System updates display in editor.
10.	Author adds branching choices → System saves Choice objects.
Sequence Diagram Objects:
•	Author
•	StoryEditor
•	Story
•	StoryNode
•	Database
________________________________________

## Sequence Diagram for UC-FR5 (Save Story Version)
_Actors_: Author, StoryEditorSystem \
_Steps_:
1.	Author opens Story Editor.
2.	System displays current & previous versions.
3.	Author clicks "Save New Version".
4.	System creates snapshot of Story object.
5.	System timestamps and labels version.
6.	System stores Version in database.
7.	System confirms save.
8.	Author can view/restore versions.
Sequence Diagram Objects:
•	Author
•	StoryEditor
•	Story
•	Version
•	Database
________________________________________
## High-Level Architecture Diagram
_Layered Approach_:
1.	Presentation Layer (Frontend):
    - Story Editor UI
    - Node Form
    - Version Viewer
    - Handles Author interactions
2.	Application Layer (Backend Logic):
    - StoryService: add/edit nodes, manage choices
    - VersionService: create/restore/compare versions
    - ValidationService: validate node and choice input
3.	Data Layer (Database):
    - Story Table
    - StoryNode Table
    - Choice Table
    - Version Table
    - Author Table

_Diagram Relationships_: \
    - Presentation Layer → calls → Application Layer \
    - Application Layer → CRUD → Data Layer \
    - Application Layer → Updates → Story, StoryNode, Version objects

