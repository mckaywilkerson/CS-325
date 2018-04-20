//YOU MAY NOT MODIFY THIS DOCUMENT

#pragma once

#include <iostream>
#include "NodeInterface.h"

template <typename Item_Type>
class Node: public NodeInterface {
private:
	struct BTNode {
		Item_Type data;
		BTNode<Item_Type>* left;
		BTNode<Item_Type>* right;
		
		BTNode(const Item_Type& the_data,
			   BTNode* left_val = NULL,
			   BTNode* right_val = NULL :
			  data(the_data), left(left_val), right(right_val) {})
			  // maybe need to put a deconstructor and to_string here (slides)
	};
	
	BTNode mylist;
public:
	Node() {}
	virtual ~Node() {}

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData() const;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface * getLeftChild() const;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface * getRightChild() const;

};