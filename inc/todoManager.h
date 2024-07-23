#ifndef TODOMANAGER_H
#define TODOMANAGER_H

#include "task.h"
#include "util.h"

class todoManager {

private:
  inputhandler inputUtil;
  task todotask[100];
  int todoCount{1};
  void addTask(std::string &uDesc);
  void deleteTask(int taskNo);
  void markTask(int index);

  void showTasks();
  void showSingleTask(int index);

public:
  todoManager() {};
  ~todoManager() {};

  void addTodoWindow();
  void deleteTodoWindow();
  void showTodoWindow();
  void markTodoWindow();
  void editTodoWindow();
};

#endif
