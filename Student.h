#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>


class Student{

 public:
  Student();
  int getId();
  char* getFirstName();
  char* getLastName();
  float getGPA();
  void printStudent();
 private:
  int id;
  char firstName[100];
  char lastName[100];
  float GPA;
};

#endif
