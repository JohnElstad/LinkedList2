#include "node.h"

Node::Node(Student* s){
  student = s;
  nextNode = NULL;
}

Node::~Node(){
  delete student;
}

void Node::setNext(Node* n){
  nextNode = n;
}
Node* Node::getNext(){
  return nextNode;
}
Student* Node::getStudent(){
  return student;
}
