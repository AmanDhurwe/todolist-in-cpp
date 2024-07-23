#include <iostream>
#include <limits>
#include <string>
#include <util.h>

char inputhandler::getCharInput() {
  char input;

  while (true) {
    std::cout << "->";
    std::cin >> input;
    if (std::cin.fail() || std::cin.peek() != '\n') {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "\n Invalid Input !!" << std::endl;
    } else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  };

  return input;
}

int inputhandler::getIntInput() {
  int input;

  while (true) {
    std::cout << "->";
    std::cin >> input;
    if (std::cin.fail() || std::cin.peek() != '\n') {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "\n Invalid Input !!" << std::endl;
    } else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  };

  return input;
}

std::string inputhandler::getStringInput() {
  std::string input;
  std::cout << "-> ";
  if (std::cin.peek() == '\n')
    std::cin.ignore();
  std::getline(std::cin, input);

  return input;
}

void inputhandler::clearScreen() { std::cout << "\033[2J\033[1;1H"; }
