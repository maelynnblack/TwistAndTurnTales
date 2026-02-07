#include "Version.h"
#include "Story.h"
#include "Author.h"

Version::Version(int id, Story* snapshot, const std::string& lbl, Author* a)
    : versionId(id), storySnapshot(snapshot), label(lbl), author(a) {
    timestamp = "2026-02-06"; // Placeholder timestamp
}

int Version::getVersionId() const { return versionId; }
std::string Version::getLabel() const { return label; }
std::string Version::getTimestamp() const { return timestamp; }

Story* Version::restore() const { return storySnapshot; }

void Version::saveSnapshot() {
    // Could copy snapshot if deep copy desired
}

std::string Version::compare(const Version* other) const {
    return "Comparison feature not implemented yet.";
}
