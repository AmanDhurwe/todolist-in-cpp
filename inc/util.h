#ifndef UTIL_H
#define UTIL_H
#include <string>

/*
 * util.h is created to provide the different utilities for the cli programmes
 * like error handling , etc...
 */

class inputhandler {

public:
  char getCharInput();
  int getIntInput();
  std::string getStringInput();
  void clearScreen();
};

#endif
