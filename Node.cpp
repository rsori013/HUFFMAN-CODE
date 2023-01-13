/**
* Course: CS010C Summer 2022
*
* First Name: Rovin
* Last Name: Soriano
* Username:	rsori013
* email address: rsori013@ucr.edu
*
*
* Assignment:  Programming Assignment 4
* Filename : Node.cpp
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#include <string>
#include <cstdlib>
#include "Node.h"
using namespace std;

Node::Node() {}
Node::Node(char cc, int countt) {
		left = NULL;
		right = NULL;
		c = cc;
		count = countt;
}
Node::Node(Node* leftt, Node* rightt, char cc, int countt) {
		left = leftt;
		right = rightt;
		c = cc;
		count = countt;
}
Node::Node(Node* leftt, Node* rightt, int countt) {
		left = leftt;
		right = rightt;
		count = countt;
	}
Node::~Node() {}