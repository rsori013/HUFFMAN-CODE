/**
* Course: CS010C Summer 2022
*
* First Name: Rovin
* Last Name: Soriano
* Username:	rsori013
* email address: rsori013@ucr.edu
*
*
* Assignment:  lab5 &PA5
* Filename : pq_zero.h
* Worked w/ Kobe Ying
* I hereby certify that the contents of this file represent
* my own original individual work. Nowhere herein is there
* code from any outside resources such as another individual,
* a website, or publishings unless specifically designated as
* permissible by the instructor or TA.
*/
#ifndef PQ_ZERO_H
#define PQ_ZERO_H

#include <iostream>
#include <vector>
#include <map>
#include <limits>
using namespace std;


template< class Item > 
class pq_zero {
private:
  vector<Item> heap; // The heap expands/shrinks to fit data
  typedef int indx;  // index with heap
  map<Item,indx> index;  // records each Item's place in heap
  map<Item,float> priority; // records each Item's priority
  map<Item,int> timestamp;//for 2 time with same prio, to check who came in first
  int t = 0; // time counter
  float MAX_FLOAT = numeric_limits<float>::infinity();
  void percolate_up( indx i ) const; 
  void percolate_down( indx i ) const;
  int parent(indx i) const;
  int lchild(indx i) const;
  int rchild(indx i) const;
  
  void percolate_up(indx i) {//zybooks
	  while (i>0) {
		  if (priority[heap[i]]<priority[heap[parent(i)]]) {
			  swap(heap[i],heap[parent(i)]);
			  i = parent(i);
		  }
		  else break;
	  }
	  for (int i=0; i<size(); i++) index[heap[i]] = i; // reassign indexes
  }
  void percolate_down(indx i) {
	  while (i<size()) {
		  //for (auto x : priority) cout << x.second << ' ';
		  //cout << endl;
		  int l = lchild(i), r = rchild(i);
		  float prio_l = MAX_FLOAT, prio_r = MAX_FLOAT;
		  if (l<size()) prio_l = priority[heap[l]]; // we have a left and we are going to assign the priot
		  if (r<size()) prio_r = priority[heap[r]];
		  //cout << prio_l << ' ' << prio_r << ' ' << priority[heap[i]] << endl;
		  if (priority[heap[i]] < prio_l && priority[heap[i]] < prio_r) return; // nothing to change if already lower
		  if (prio_l == prio_r) { // if they have the same prio
			  if (prio_l == MAX_FLOAT) return;
			  else { // left and right child have same priorities and are lower than parent
				  if (timestamp[heap[l]] < timestamp[heap[r]]) {
					  swap(heap[i],heap[l]);
					  i = l;
				  }
				  else {
					  swap(heap[i],heap[r]);
					  i = r;
				  }
			  }
		  }
		  else if (prio_l < prio_r) { // if who is lower we swap
			  swap(heap[i],heap[l]);
			  i = l;
		  }
		  else if (prio_l > prio_r) {
			  swap(heap[i],heap[r]);
			  i = r;
		  }
		  //cout << prio_l << ' ' << prio_r;
	  }
	  for (int i=0; i<size(); i++) index[heap[i]] = i; // reassign indexes
  }
  int parent(indx i) {
	  return (i-1)/2;
  }
  int lchild(indx i) {
	  return 2*i+1;
  }
  int rchild(indx i) {
	  return 2*i+2;
  }
public: 
  // These use the min-heap functions above.
  pq_zero(){}  
  pq_zero(vector<Item> heap, float prio ){
			build_heap();
  }
  int size( ) const;
  bool empty( ) const;
  const Item& top( ) const;
  void pop( ) const;
  void push( const Item& w, float prio );
  const Item& front( ) const;
  void build_heap() const;
  
  int size( ) {
	  return heap.size();
  }
  bool empty( ) {
	  return (heap.empty());
  }
  const Item& top( ) {
	  if (!empty()) return heap[0];
	  return NULL;
  }
  const Item& front( ) {
	  if (!empty()) return heap[0];
	  return NULL;
  }
  void  pop( ){//delete root,replace it with the rightmost,
	  priority.erase(heap[0]); 
	  heap[0] = heap[size()-1];
	  heap.pop_back();
	  percolate_down(0);
	  for (int i=0; i<size(); i++) index[heap[i]] = i;
  }
  void  push( Item& w, float prio ){
   //for (int j =0; j<heap.size();j++){
   //i=heap[j]; }
	  for (auto i : heap) { //iterate heap(i) 1by1
		  if (i==w) {
			  if (prio < priority[w]) {
				  priority[w] = prio;
				  percolate_down(index[w]);
			  }
			  else if (prio > priority[w]) {
				  priority[w] = prio;
				  percolate_up(index[w]);
			  }
			  priority[w] = prio;
			  timestamp[w] = t; // time t
			  t++;
			  for (int i=0; i<size(); i++) index[heap[i]] = i;
			  return;
		  }
	  }
	  priority[w] = prio;
	  timestamp[w] = t;
	  t++;
	  heap.push_back(w); // right most push
	  percolate_up(size()-1);
	  for (int i=0; i<size(); i++){
			index[heap[i]] = i;
	  } 
  }
  void build_heap() {
	  for (int x = size()/2-1; x >= 0; x--) {
		  percolate_down(x);
	  }
  }
  
};
#endif