#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iterator>
#include <iomanip>

#include "student.h"

#ifndef NODE_H
#define NODE_H

class Node{//has a student and a pointer to the next Node
	
	public:
		Node(Student*);//sets student to parameter, sets nextNode to NULL and youll need to set it's next node b4 you get the nextNode
		~Node();//deletes student too
		Node* getNext();//returns nextNode
		void setNext(Node*);//sets next node
		Student* getStudent();//returns student
				
	private:
		Student* student;
		Node* nextNode;
	
};


#endif