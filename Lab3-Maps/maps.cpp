#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <sstream>

using namespace std;

deque<string> writeDeque (string filename) {
    string token;
    deque<string> unique;
    
    ifstream fin;
    ofstream outputFile;
    
    fin.open(filename.c_str());
    outputFile.open("deque.txt");
	
	if (fin.fail()) {
	    cout << "Unable to read file." << endl;
	}
	else {
	    while (fin >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
	          
		    unique.push_back(nopunct);
		    outputFile << nopunct << " ";
	    }
	    
	}
	outputFile.close();
	fin.close();
	
	return unique;
}

vector<string> writeVector (string filename) {
    string token;
    vector<string> unique;
    
    ifstream fin;
    ofstream outputFile;
    
    fin.open(filename.c_str());
    outputFile.open("vector.txt");
	
	if (fin.fail()) {
	    cout << "Unable to read file." << endl;
	}
	else {
	    while (fin >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
	          
		    unique.push_back(nopunct);
		    outputFile << nopunct << " ";
	    }
	}
	outputFile.close();
	fin.close();
	
	return unique;
}

void makeprintMap (vector<string> text, int genlength) {
    map<queue<string>, vector<string>> model;
    ostringstream oss;
    string next;
    
    queue<string> initialcontext;
    initialcontext.push("");                                // add more initialcontext.push("") to make it look for more words
    initialcontext.push("");
    initialcontext.push("");
    queue<string> context = initialcontext;
    
    for (auto &s : text) {
    model[context].push_back(s);
    context.push(s);
    context.pop();
    }
    
    context = initialcontext;
    for (int i = 0; i < genlength; i++) {
        next = model[context][rand() % model[context].size()];
        context.push(next);
        context.pop();
        cout << next << " ";
        //oss << next << " ";
    }
}

int main () {
    string filename;
    string nextword;
    deque<string> dequeText;
    vector<string> vectorText;
    map<queue<string>, vector<string>> model;
    int genLength = 100;
    
    
    ifstream fin;
    
    cout << "Input the name of the file to be read: ";
	cin >> filename;
	cout << endl;
	filename = filename + ".txt";
	
    //dequeText = writeDeque(filename);
    vectorText = writeVector(filename);
    
    makeprintMap(vectorText, genLength);
    
    
    
    return 0;
}