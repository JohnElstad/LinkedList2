#include <iostream>
#include "node.h"
#include "Student.h"
#include <cstring>
#include <iomanip>

using namespace std;
//John Elstad- This is a linked List program- 1/6/17
void addStudent(Node* head, Student* student);
void deleteStudent(Node* current, Node* previous, int deleteId);
void printStudent(Node* head);
void averageGPA(Node* head);

int main(){

  cout<<"Linked List"<<endl;
  bool running = true;
  Node* head = new Node(NULL);
  while(running==true){
    cout<<"ADD, AVERAGE, PRINTALL, QUIT and DELETE are valid commands"<<endl;
    char input[100];
    cin>>input;
    //add
    if(strcmp(input,"ADD")==0){
      cout<<"Adding New Student"<<endl;
      addStudent(head, new Student);
    }
    //PRINT
    else if(strcmp(input,"PRINTALL")==0){
      cout<<"Printing..."<<endl;
      printStudent(head->getNext());
    }
    //DELETE
    else if(strcmp(input,"DELETE")==0){
      if(head->getNext()){
	int deleteId;
	cout<<"What is the Id of the student you want to remove?"<<endl;
	cin>>deleteId;
	deleteStudent(head,NULL,deleteId);
      }
    }
    //AVERAGE
    else if(strcmp(input,"AVERAGE")==0){
      averageGPA(head);
	}
    //QUIT
    else if(strcmp(input,"QUIT")==0){
      cout<<"QUITTING"<<endl;
      running=false;
    }
    else{
      cout<<"PRINTALL DELETE ADD QUIT"<<endl;
    }
  }
}
//adds a student
void addStudent(Node* head, Student* student){
  if(!head->getNext()){
    head->setNext(new Node(student));
  }
  else if(head->getNext()->getStudent()->getId() > student->getId()){
    Node* temp = head->getNext();//sets a temp
      head->setNext(new Node(student));
      head->getNext()->setNext(temp);
  }
  else{
    addStudent(head->getNext(),student);
  }

}
//deletes a student
void deleteStudent(Node* current,Node* previous,int id){
  if(current->getStudent() != NULL && current->getStudent()->getId() == id){
    previous->setNext(current->getNext());
    delete current;
  }
  else if(current->getNext()){
    deleteStudent(current->getNext(),current,id);
    
  }
  else{
    cout<<"There are no students to delete"<<endl;
  }
}
//prints a student
void printStudent(Node* head){
  if(!head){
    return;
  }
  cout<<"*****************************"<<endl;
  head->getStudent()->printStudent();
  if(head->getNext()){
    printStudent(head->getNext());
  }
  
}
//averages the GPA of all students
void averageGPA(Node* head){
  int count = 0;
  float gpa = 0;
  cout<<endl;
  for(Node* currentNode = head->getNext(); currentNode != NULL; currentNode = currentNode->getNext()){
    count++;
    gpa+=currentNode->getStudent()->getGPA();
  }
  gpa/=count;
  cout<<"Average GPA:"<<setprecision(2)<<fixed<<gpa<<endl;

}
