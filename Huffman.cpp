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
* Filename : Huffman.cpp
*
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include "Huffman.h"
#include "pq_zero.h"
#include "Node.h"

using namespace std;

Huffman::Huffman(){}
Huffman::~Huffman(){}

Huffman::Huffman(const string& inputFile){
  string line;
  message = "";
  ifstream myfile(inputFile);
  if(myfile.is_open()){
      while(getline(myfile,line)){
          message+=line;
          message+="\n";
      }
  }
  //cout << message << endl;
  myfile.close();
  BuildCharacterFrequencyTable(message);
  BuildPQ();
}
void Huffman:: BuildCharacterFrequencyTable(string inputString){//zybooks
    for (auto i : inputString) mymap[i]++;
}


void Huffman:: PrintCharFrequencies(){
    //for (auto i : message) mymap[i]++;
    map<char,int> :: iterator it;
    for (it = mymap.begin(); it != mymap.end(); it++){
        if(it->first == '\n'){
            cout << "endl=>" << it->second << endl;
        }
        else {
            cout << it->first  << "=>" << it->second << endl;
      }
    }//range based for loops easier that ^ 
    // for (auto i : mymap){
    //   if(i.first == '\n'){
    //         cout << "endl=>" << i.second << endl;
    //     }
    //     else {
    //         cout << i.first  << "=>" << i.second << endl;
    //   } 
    // } 
}

void Huffman:: BuildPQ(){
    for (auto i : mymap){
        Node* newNode = new Node(i.first,i.second);
        pq.push(newNode,float(i.second));
    }
}

void Huffman:: Stats(){
    cout << "Without compression, 8-bit characters:" << endl;
    map<char,int> :: iterator it;
    int total = 0;
    for(it=mymap.begin();it !=mymap.end();++it){
        total+=it->second*8;
        if(it->first == '\n'){
            cout << "endl occurs " << it->second << " times. Cost of: " 
              << it->second*8 << " bits. Total so far: " << total << endl;
        }
        else {
             cout << it->first << " occurs " << it->second << " times. Cost of: " 
              << it->second*8 << " bits. Total so far: " << total << endl;
      }
    }
      cout << "Total bits: " << total << endl << endl;
      
    total = 0;
    cout << "With compression, 8-bit characters:" << endl;
    for (auto i : mymap_compress) {
        total+=mymap[i.first]*i.second.size();
        if(i.first == '\n'){
		  cout << "endl occurs " << mymap[i.first] << " times. Bit sequence: " << i.second << ". ";
		  cout << "Cost of: " << mymap[i.first]*i.second.size() << " bits.";
		  cout << "Total so far: " << total << " bits." << endl;
	    }
	    else{
	      cout << i.first << " occurs " << mymap[i.first] << " times. Bit sequence: " << i.second << ". ";
		  cout << "Cost of: " << mymap[i.first]*i.second.size() << " bits.";
		  cout << "Total so far: " << total << " bits." << endl;  
	    }
    }
         cout << "Total bits = " << total << endl;
 }

void Huffman:: BuildHuffmanTree(){//zybooks ref
    while(pq.size()>1){
        Node* left = pq.top();
        pq.pop();
        Node* right =pq.top();
        pq.pop();
        //pop the two nodes
        int freqSum = left->count + right->count; //merging count from the 2 popped
        Node* parent = new Node(left,right,freqSum); // merged
        
        pq.push(parent,float(freqSum)); //pushed go crazy
    }
    root = pq.top();
 }
void Huffman:: SetBitsPerChar(){
    SetBitsPerChar(root);
}
void Huffman:: DisplayPrefixTree(){
    DisplayPrefixTree(root);
    
}
void Huffman:: SetBitCodes(){
    SetBitCodes(root,"");
}
void Huffman:: BitMap(){
    for (auto i : mymap_compress) {
	    if(i.first == '\n'){	  
		  cout << "endl, " << i.second << endl;
	    }
	    else{
		  cout << i.first << ',' << i.second << endl;
	    }
	}
}

void Huffman:: PrintMessage(){
    compressedBits = "";
    for (auto i : message){
        compressedBits= compressedBits+mymap_compress[i];
    }
    cout << compressedBits << endl;
}


void Huffman:: HuffmanDecompress(){//zybooks
    Node* curr = root;
    for (auto i: compressedBits){
        if(i == '0'){
            curr=curr->left;
        }
        else{
            curr= curr->right;
        }
        if(curr->left == NULL && curr->right == NULL){//its a leaaafff
            cout << curr->c;
            curr = root;
        }
    
    }
    cout << endl;
}
//private functions
void Huffman::SetBitCodes(Node* n,string prefix){// sets string bits for leaf nodes
    if(n==NULL) return;
    else{
      n->bits = prefix;
      SetBitCodes(n->left,prefix+"0");
      SetBitCodes(n->right,prefix+"1");
    }
  } 

void Huffman:: DisplayPrefixTree(Node* t){ // optional, use for debugging, display tree
  static int depth = 0;
	  ++depth;
	  if (t == NULL) return;
	  if (t->right != NULL) DisplayPrefixTree(t->right);
	  for (int i=0; i<depth; i++) cout << " ";
	  if (t->left == NULL && t->right == NULL) cout << t->c;
	  cout << "=>" << t->count << "=>" << t->bits << endl;
	  if (t->left != NULL) DisplayPrefixTree(t->left);
	  --depth;
  }//lab display example
  
  
 void Huffman:: SetBitsPerChar(Node* n) { // maps bitstream to char
      if (n== NULL){
      return;
      }
       if (n->left==NULL && n->right == NULL){//meaning its a leaf
        mymap_compress[n->c]=n->bits;
      }
       else {
      SetBitsPerChar(n->left);
      SetBitsPerChar(n->right);
      }
}