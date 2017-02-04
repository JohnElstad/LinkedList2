#include "Student.h"
#include <iostream>
#include "node.h"
#include <iomanip>
using namespace std;
Student::Student(){
  cout<<"What is their ID?"<<endl;
  cin>>id;
  cout<<"What is their GPA?"<<endl;
  cin>>GPA;
  cout<<"First Name?"<<endl;
  cin>>firstName;
  cout<<"Last Name?"<<endl;
  cin>>lastName;
}

int Student::getId(){
  return id;
}
float Student::getGPA(){
  return GPA;
}
void Student:: printStudent(){
  cout<<"ID: "<<id<<endl;
  cout<<"First Name: "<<firstName<<endl;
  cout<<"Last Name: "<<lastName<<endl;
  cout<<"GPA: "<<setprecision(2)<<fixed<<GPA<<endl;
}
