#include "LinkedList.h"

    /*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value) {
	    Node *ptr = mylist;
	    
	    // look for duplicates
	    while (ptr != NULL) {
	        if (ptr->data == value) {
	            return;
	        }
	        ptr = ptr->next;
	    }
	    
	    ptr = mylist;
	    if (mylist == NULL) {
	        mylist = new Node(value, NULL);
	        num_items ++;
	        return;
	    }
	    else {
	        mylist = new Node(value, ptr);
	        num_items ++;
	        return;
	    }
	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value) {
	    Node *ptr = mylist;
	    
	    // look for duplicates
	    while (ptr != NULL) {
	        if (ptr->data == value) {
	            return;
	        }
	        ptr = ptr->next;
	    }
	    
	    ptr = mylist;
		if(mylist == NULL){
			mylist = new Node(value, NULL);
		} else {
			while(ptr != NULL){
			    
				if(ptr->next == NULL) {
					ptr->next = new Node(value, NULL);
					break;
				} else {
					ptr = ptr->next;
				}
			}
		}
		num_items++;
	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode) {
	    Node *ptr = mylist;
	    
	    
	    // look for duplicates
	    while (ptr != NULL) {
	        if (ptr->data == value) {
	            return;
	        }
	        ptr = ptr->next;
	    }
	    ptr = mylist;
	    
	    while (ptr != NULL) {
	        if (ptr->data == insertionNode) {
	            Node *newnode = new Node(value, ptr->next);
	            ptr->next = newnode;
	            num_items ++;
	            break;
	        }
	        ptr = ptr->next;
	    }
	    
	    
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value) {
	    Node *ptr = mylist;
	    
	    while (ptr->next != NULL) {
	        if (ptr->next->data == value) {
	            Node *current = ptr->next;
	            ptr->next = ptr->next->next;
	            delete current;
	            num_items --;
	            return;
	        }
	    }
	}

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear() {
	    Node *ptr = mylist;
	    for (int i = 0; i < num_items; i++) {
	        if (ptr-> next != NULL) {
	            Node *next = ptr->next;
	            delete ptr;
	            ptr = next;
	        }
	        else {
	            delete ptr;
	        }
	    }
	}

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index) {
	    
	    if(index >= num_items) {
			throw std::out_of_range("At Error");
		}
		else {
			Node *ptr = mylist;
			for(int i = 0; i <= index; i++) {
		  		if(i == (index)) { 
		  			return(ptr->data);
		  		}
		  		else {
		  			ptr = ptr->next;
		  		}
			}
		}
	}

	/*
	size

	Returns the number of nodes in the list.
	*/
	int size() {
	    return num_items;
	}

	/*
	toString
	
	Returns a string representation of the list, with the value of each node listed in order (Starting from the head) and separated by a single space
	There should be no trailing space at the end of the string

	For example, a LinkedList containing the value 1, 2, 3, 4, and 5 should return
	"1 2 3 4 5"
	*/
	string toString() {
	    if (mylist == NULL) {
	        return "";
	    }
	    
	    Node *ptr = mylist;
	    ostringstream oss;
	    while (ptr != NULL) {
	        oss << ptr->data << " ";
	        ptr = ptr->next;
	    }
	    string value = oss.str();
	    value.pop_back();
	    return value;
	}