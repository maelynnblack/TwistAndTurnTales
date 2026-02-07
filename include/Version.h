#pragma once
#include <string>

// Forward declarations
class Story;
class Author;

class Version {
private:
    int versionId;
    Story* storySnapshot;
    std::string timestamp; // Simplified
    std::string label;
    Author* author;

public:
    // Constructor
    Version(int id, Story* snapshot, const std::string& lbl, Author* a);

    // Getters/Setters
    int getVersionId() const;
    std::string getLabel() const;
    std::string getTimestamp() const;

    // Methods
    Story* restore() const;
    void saveSnapshot();
    std::string compare(const Version* other) const;
};
