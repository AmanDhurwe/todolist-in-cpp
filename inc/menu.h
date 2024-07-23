#ifndef MENU_H
#define MENU_H
#include "todoManager.h"
#include "util.h"

class menu {
private:
  todoManager todo;
  inputhandler inputUtil;

public:
  void mainMenu();
  void taskManagementMenu();
};

#endif
