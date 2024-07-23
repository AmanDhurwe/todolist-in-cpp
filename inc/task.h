#ifndef TASK_H
#define TASK_H
#include <string>

class task {
private:
  int id;
  std::string description;
  bool completed;

  //             METHODS
public:
  // constructor
  task(){};
  ~task(){};
  task(int id, const std::string desc);
  task(const std::string desc);

  // getters
  std::string getDescription() const;
  int getId() const;
  bool isCompleted() const;

  // setters
  void setDescription(std::string newDesc);
  void setId(int newId);
  void setCompleted();
};
#endif // !DEBUG
