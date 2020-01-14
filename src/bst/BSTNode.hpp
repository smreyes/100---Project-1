/**
 * Name: Steffe Reyes (A16083679)
 * Ji Hyun An (A91108783)
 */
#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iomanip>
#include <iostream>
using namespace std;

/**
 * TODO: add class header
 */
template <typename Data>
class BSTNode {
  private:
    Data data;

  public:
    BSTNode<Data>* left;
    BSTNode<Data>* right;
    BSTNode<Data>* parent;

    /*Initializing a BSTNode/ no parent and no children */
    BSTNode(const Data& d) : data(d) {
    	left = right = parent = 0;
    }

    /** Set the value of data */
    void setData(const Data& d) { data = d; }

    /** Get the value of data */
    Data getData() { return data; }

    /** TODO */
    BSTNode<Data>* successor() {
	  BSTNode<Data> *curr = this;
	  
	  //Continue until we reach the leftmost leaf
	  if(curr->right) {
		  curr = curr->right;
		  
		  while (curr->left) {
			  curr = curr->left;
		  }
		  return curr;
	  }
	  //if successor is parent
	  else {
		 while (curr->parent) {
			if (curr->left == this) {
			       return curr->parent;
			}
	 		if (curr->parent && curr->data > this->data) {
				return curr->parent;
			}
		}		
	    
	  } 
	  //if no successor found
	    return 0;
    }
};

/**
 * DO NOT CHANGE THIS METHOD
 * Overload operator<< to print a BSTNode's fields to an ostream.
 */
template <typename Data>
ostream& operator<<(ostream& stm, const BSTNode<Data>& n) {
    stm << '[';
    stm << setw(10) << &n;                  // address of the BSTNode
    stm << "; p:" << setw(10) << n.parent;  // address of its parent
    stm << "; l:" << setw(10) << n.left;    // address of its left child
    stm << "; r:" << setw(10) << n.right;   // address of its right child
    stm << "; d:" << n.data;                // its data field
    stm << ']';
    return stm;
}

#endif  // BSTNODE_HPP
