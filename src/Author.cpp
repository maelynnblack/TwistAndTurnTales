#include "Author.h"
#include "Story.h"
#include "Version.h"

Author::Author(int id, const std::string& n, const std::string& e, const std::string& r)
    : authorId(id), name(n), email(e), role(r) {
}

int Author::getAuthorId() const { return authorId; }
std::string Author::getName() const { return name; }
void Author::setName(const std::string& n) { name = n; }
std::string Author::getEmail() const { return email; }
void Author::setEmail(const std::string& e) { email = e; }
std::string Author::getRole() const { return role; }
void Author::setRole(const std::string& r) { role = r; }

void Author::addStory(Story* story) {
    activeStories.push_back(story);
}

std::vector<Story*> Author::getActiveStories() const {
    return activeStories;
}

Story* Author::createStory(const std::string& title) {
    int newId = activeStories.size() + 1;
    Story* story = new Story(newId, title, this);
    addStory(story);
    return story;
}

void Author::editStory(Story* story, const std::string& newTitle) {
    if (story) {
        story->setTitle(newTitle);
    }
}

Version* Author::saveStoryVersion(Story* story, const std::string& label) {
    if (story) {
        return story->createVersion(label);
    }
    return nullptr;
}
