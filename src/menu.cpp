#include "menu.h"
#include "iostream"

void menu::mainMenu() {

  int uChoice;
  bool exit{false};

  std::string taskinput;

  while (!exit) {
    inputUtil.clearScreen();
    std::cout << "\t\t\tTO DO LIST \n"
              << "\n 1. Add Task " << "\n 2. Show Task "
              << "\n 3. Exit Programme " << std::endl;

    uChoice = inputUtil.getIntInput();
    inputUtil.clearScreen();

    // user choices
    switch (uChoice) {

    case 1: // adding todo task
      todo.addTodoWindow();
      break;
    case 2: {
      todo.showTodoWindow();
      break;
    }
    case 3: // exiting the programme
    {
      char uConfirm{'n'};
      while (true) {
        std::cout << "-> Do you want to EXIT (y/n)" << std::endl;
        uConfirm = inputUtil.getCharInput();
        if (uConfirm == 'y' || uConfirm == 'Y') {
          exit = true;
          break;

        } else if (uConfirm == 'n' || uConfirm == 'N') {
          exit = false;
          break;

        } else {
          std::cout << "-> invalid input " << std::endl;
          exit = false;
        }
      }
      break;
    }
    default:
      std::cout << "\n-> Invalid input " << std::endl;
      break;
    }
  }
}
