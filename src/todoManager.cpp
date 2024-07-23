#include "todoManager.h"
#include <iostream>

// these are the public methods of TodoManager class ;

//========================  [add todo window] ========================
void todoManager::addTodoWindow() {
  inputUtil.clearScreen();

  bool exitWindow{false};
  int userChoice;
  std::string taskinput;

  while (!exitWindow) {
    inputUtil.clearScreen();
    std::cout << "\n\n====================================================\n"
              << std::endl;

    std::cout << "                     ADD TASK                             "
              << std::endl;

    std::cout << " \n-> ENTER TASK" << std::endl;
    taskinput = inputUtil.getStringInput();
    addTask(taskinput);
    std::cout << "\n====================================================\n "
              << std::endl;

    bool exitInput{false};
    while (!exitInput) {

      std::cout << " 1. Add Task Again " << "\n 2. Exit ." << std::endl;
      userChoice = inputUtil.getIntInput();
      if (userChoice != 1 && userChoice != 2) {
        std::cout << "-> Invalid Input ! ";
        exitInput = false;
        exitWindow = false;

      } else if (userChoice == 2) {
        exitInput = true;
        exitWindow = true;

      } else if (userChoice == 1) {
        exitInput = true;
      }
    }
  }
}
//====================================================================

//========================  [show task wondow] =======================
void todoManager::showTodoWindow() {
  int input{'n'};
  bool exitwindow{false};

  while (!exitwindow) {
    inputUtil.clearScreen();
    std::cout << "\n\n===============================================\n"
              << std::endl;
    std::cout << "                     TASK`S                            "
              << std::endl;

    showTasks();

    std::cout << "\n\n===============================================\n"
              << std::endl;
    bool exitloop{true};
    while (exitloop) {
      std::cout << "\n 1. Mark task " << "\n 2. Edit Task "
                << "\n 3. Delete task " << "\n 4. Exit " << std::endl;

      input = inputUtil.getIntInput();

      switch (input) {
      case 1: {
        markTodoWindow();
        exitloop = false;
        break;
      }
      case 2: {
        editTodoWindow();
        exitloop = false;
        break;
      }
      case 3: {
        deleteTodoWindow();
        exitloop = false;
        break;
      }
      case 4: {
        exitloop = false;
        exitwindow = true;
        break;
      }
      default:
        std::cout << "-> Invalid input " << std::endl;
        break;
      }
    }
  };
}
//====================================================================

//========================  [mark todo wondow] =======================
void todoManager::markTodoWindow() {
  inputUtil.clearScreen();
  int choice;
  std::cout << "\n\n===============================================\n"
            << std::endl;
  std::cout << "\n\t\t\t\t\t MARK TASK \n" << std::endl;
  while (true) {
    std::cout << "\n-> Enter Task No" << std::endl;
    choice = inputUtil.getIntInput();

    if (choice <= todoCount && choice > 0) {
      markTask(choice);
      break;
    } else {
      std::cout << "\n-> No task found ! try again " << std::endl;
    }
  }
}
//====================================================================

//========================  [edit todo wondow] =======================
void todoManager::editTodoWindow() {
  inputUtil.clearScreen();
  std::cout << "\n-> Enter task no to edit " << std::endl;
  int choice;
  while (true) {
    choice = inputUtil.getIntInput();
    if (choice <= todoCount && choice > 0) {
      std::string ediTask;
      std::cout << "\n " << std::endl;
      showSingleTask(choice);
      std::cout << "\n-> Enter new edit " << std::endl;
      ediTask = inputUtil.getStringInput();
      todotask[choice].setDescription(ediTask);
      break;
    } else {
      std::cout << "\n-> No task found ! try again " << std::endl;
    }
  }
}
//====================================================================

//========================  [delete todo wondow] =======================
void todoManager::deleteTodoWindow() {
  inputUtil.clearScreen();
  int choice;
  while (true) {
    std::cout << "-> Enter task no to delete ! " << std::endl;

    choice = inputUtil.getIntInput();
    if (choice <= todoCount && choice > 0) {
      deleteTask(choice);
      break;
    } else {
      std::cout << "\n-> No task found , try again " << std::endl;
    }
  }
};
//====================================================================

//********************************************************************
//********************************************************************
// these are the private methods of TodoManager class ;
//********************************************************************
//********************************************************************
void todoManager::addTask(std::string &uDesc) {
  if (todoCount < 100) {
    todotask[todoCount] = task(uDesc);
    todoCount++;
    std::cout << "\n-> Task added " << std::endl;
  } else {
    std::cout << "\n-> task list is full " << std::endl;
  }
}

void todoManager::showTasks() {
  char mark{'x'};
  for (size_t i = 1; i < todoCount; i++) {
    if (todotask[i].isCompleted() == true) {
      mark = 'v';
    } else {
      mark = 'x';
    }

    std::cout << " " << i << ".  [" << mark << "]   "
              << todotask[i].getDescription() << std::endl;
  }
}

void todoManager::showSingleTask(int index) {
  char mark{'x'};
  if (todotask[index].isCompleted()) {
    mark = 'v';
  }

  std::cout << " " << index << ".  [" << mark << "]   "
            << todotask[index].getDescription() << std::endl;
}

void todoManager::deleteTask(int TaskNo) {
  for (int i = 1; i < todoCount; i++) {
    if (i >= TaskNo) {
      todotask[i] = todotask[i + 1];
    }
  }
  todoCount--;
};

void todoManager::markTask(int index) { todotask[index].setCompleted(); };
