#include <string>
#include <task.h>

task::task(int id, const std::string desc) {
  this->id = id;
  description = desc;
  completed = false;
}

task::task(const std::string desc) {
  description = desc;
  completed = false;
}

//  getters
std::string task::getDescription() const { return description; }

int task::getId() const { return id; }

bool task::isCompleted() const { return completed; }

// setters

void task::setCompleted() { completed = true; }

void task::setDescription(std::string newDesc) { description = newDesc; }

void task::setId(int newId) { id = newId; }
