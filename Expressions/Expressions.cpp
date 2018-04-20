#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

// The set of opening parentheses.
const string OPEN = "([{";
// The corresponding set of closing parentheses.
const string CLOSE = ")]}";


bool is_open(char ch) {
  return OPEN.find(ch) != string::npos;
}


bool is_close(char ch) {
  return CLOSE.find(ch) != string::npos;
}

bool string_open(string check) {
    if (check == "(" || check == "[" || check == "{") {
        return true;
    }
    else {
        return false;
    }
}

bool string_close(string check) {
    if (check == ")" || check == "]" || check == "}") {
        return true;
    }
    else {
        return false;
    }
}

bool isNumber(string token) {
    string::const_iterator it = token.begin();
    
    while (it != token.end() && isdigit(*it)) {
        it ++;
    }
    
    return !token.empty() && it == token.end();
}

bool isOperator(string token) {
    if ((token == "+") || (token == "-") || (token == "*") || (token == "/") || (token == "%")) {
        return true;
    }
    else {
        return false;
    }
}


bool isBalanced(string expression) {
    stack<char> s;
    bool balanced = true;
    
    for (string::const_iterator iter = expression.begin();
     balanced && (iter != expression.end());
     iter++) {
        char next_ch = *iter;
        if (is_open(next_ch)) {
            s.push(next_ch);
        } else if (is_close(next_ch)) {
            if (s.empty()) {
                balanced = false;
            } else {
                char top_ch = s.top();
                s.pop();
                balanced = 
                 OPEN.find(top_ch) == CLOSE.find(next_ch);
            }
        }
    }
    return balanced && s.empty();
}

string postfixToInfix(string postfixExpression) {
    stack<string> myStack;
    string valueOne;
    string valueTwo;
    istringstream input(postfixExpression);
    string token;
    string temp;
    
    while(input >> token) {
        if (isNumber(token)) {                   // function isNumber to check string "token" to see if they're all numbers
            myStack.push((token) + " ");
        }
        else if (isOperator(token) && (myStack.size() >= 2)) {
            valueTwo = myStack.top();
            myStack.pop();
            valueOne = myStack.top();
            myStack.pop();
            switch(token[0]) {
                case '+':
                    temp = "(" + valueOne + " + " + valueTwo + ")";
                    myStack.push(temp);
                break;
                case '-':
                    temp = "(" + valueOne + " - " + valueTwo + ")";
                    myStack.push(temp);
                break;
                case '*':
                    temp = "(" + valueOne + " * " + valueTwo + ")";
                    myStack.push(temp);
                break;
                case '/':
                    temp = "(" + valueOne + " / " + valueTwo + ")";
                    myStack.push(temp);
                break;
                case '%':
                    temp = "(" + valueOne + " % " + valueTwo + ")";
                    myStack.push(temp);
                break;
            }
        }
        else {
            cout << "Invalid";
        }
    }
    return myStack.top();
}

string postfixEvaluate(string postfixExpression) {
    stack<string> myStack;
    string valueOne;
    string valueTwo;
    istringstream input(postfixExpression);
    string token;
    string temp;
    int tempTotal;
    int tempOne;
    int tempTwo;
    
    while(input >> token) {
        if (isNumber(token)) {                   // function isNumber to check string "token" to see if they're all numbers
            myStack.push((token) + " ");
        }
        else if (isOperator(token) && (myStack.size() >= 2)) {
            valueTwo = myStack.top();
            myStack.pop();
            valueOne = myStack.top();
            myStack.pop();
            switch(token[0]) {
                case '+':
                    tempOne = atoi(valueOne.c_str());
                    tempTwo = atoi(valueTwo.c_str());
                    tempTotal = tempOne + tempTwo;
                    temp = to_string(tempTotal);
                    myStack.push(temp);
                break;
                case '-':
                    tempOne = atoi(valueOne.c_str());
                    tempTwo = atoi(valueTwo.c_str());
                    tempTotal = tempOne - tempTwo;
                    temp = to_string(tempTotal);
                    myStack.push(temp);
                break;
                case '*':
                    tempOne = atoi(valueOne.c_str());
                    tempTwo = atoi(valueTwo.c_str());
                    tempTotal = tempOne * tempTwo;
                    temp = to_string(tempTotal);
                    myStack.push(temp);
                break;
                case '/':
                    tempOne = atoi(valueOne.c_str());
                    tempTwo = atoi(valueTwo.c_str());
                    tempTotal = tempOne / tempTwo;
                    temp = to_string(tempTotal);
                    myStack.push(temp);
                break;
                case '%':
                    tempOne = atoi(valueOne.c_str());
                    tempTwo = atoi(valueTwo.c_str());
                    tempTotal = tempOne % tempTwo;
                    temp = to_string(tempTotal);
                    myStack.push(temp);
                break;
            }
        }
        else {
            cout << "Invalid";
        }
    }
    return myStack.top();
}

string infixToPostfix(string infixExpression) {
    stack<string> myStack;
    istringstream input(infixExpression);
    string token;
    string output = "";
    
     while(input >> token) {
         if (isNumber(token)) {             // function isNumber to check string "token" to see if they're all numbers
            output.append(token + " ");
            //myStack.push(token);
        }
        
        else if (isOperator(token)) {
            if (token == "+" || token == "-") {
                if (myStack.empty()) {
                    myStack.push(token);
                }
                    
                else if (string_open(myStack.top())) {
                    myStack.push(token);
                }
                else {
                    while (!myStack.empty() && !string_open(myStack.top())) {
                        output.append(myStack.top() + " ");
                        myStack.pop();
                    }
                    myStack.push(token);
                }
            }
            
            else if (token == "*" || token == "/" || token == "%") {
                if (myStack.empty()) {
                    myStack.push(token);
                }
                else if (string_open(myStack.top()) || myStack.top() == "+" || myStack.top() == "-") {
                    myStack.push(token);
                }
                else {
                   // while (!myStack.empty() && !string_open(myStack.top())) {  //|| myStack.top() == "+" || myStack.top() == "-")
                        output.append(myStack.top() + " ");
                        myStack.pop();
                   // }
                    myStack.push(token);
                }
            }
        }
        
        else if (string_open(token)) {
            myStack.push(token);
        }
        
        else if (string_close(token)) {
            while (!string_open(myStack.top()) && !myStack.empty()) {
                output.append(myStack.top() + " ");
                myStack.pop();
            }
            myStack.pop();
        }
     }
     
     while (!myStack.empty()) {
         output.append(myStack.top() + " ");
         myStack.pop();
     }
     
     return output;
}

int main() {
    string temp;
    
    if (1) {
        temp = infixToPostfix("40 * ( 2 + 4 - ( 2 + 2 ) ) - 4 / 5 / 6");
        cout << temp << endl;
    }
    else {
        cout << "Not Balanced" << endl;
    }
    
    return 0;
}