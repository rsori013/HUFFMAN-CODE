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
* Filename : Node.h
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
/* 
 * Node.h
 * cs10c_sum21
 * huffman 
 */
#include <string>
using namespace std;

#ifndef __NODE_H_
#define __NODE_H_

class Node {
public:
 	Node();
	Node(char cc, int countt);
	Node(Node* leftt, Node* rightt, char cc, int countt);
	Node(Node* leftt, Node* rightt, int countt);
	~Node();
  Node* left;
  Node* right;
  char c;
  int count;
  string bits;
};

#endif /* NODE_H_ */


