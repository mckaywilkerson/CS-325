#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <deque>

using namespace std;

void print(vector<int> myVector) {
    for (vector<int>::iterator it = myVector.begin(); it!= myVector.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void print(stack<int> myStack) {
    stack<int> temp;
    
    while (myStack.size()) {
        cout << myStack.top() << " ";
        temp.push(myStack.top());
        myStack.pop();
    }
    cout << endl;
    
    while (temp.size()) {
        myStack.push(temp.top());
        temp.pop();
    }
}

void print(list<int> myList) {
    //same as vector
    for (list<int>::iterator it = myList.begin(); it!= myList.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void print(deque<int> myDeque) {
    cout << "list: ";
	for(std::deque<int>::iterator it = myDeque.begin(); it != myDeque.end(); it++) {
	    cout << *it<<" ";
	}
	cout << endl;
}

int main() {
    vector <int> intVector;
    
    intVector.push_back(1);
    intVector.push_back(2);
    intVector[0] = 3;
    print(intVector);
    
    stack<int> intStack;
    intStack.push(4);
    intStack.push(5);
    print(intStack);
    
    list<int> intList;
    intList.push_back(7);
    intList.push_back(8);
    print(intList);
    
    // basic: push onto back, pull from front
    deque<int> intDeque;
    intDeque.push_back(10);
    intDeque.push_back(11);
    print(intDeque);
    
    
    
    return 0;
}