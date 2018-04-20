#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "print.h"

using namespace std;

int main(int argc, char *argv[]) 
{
    vector<string> names;
    vector<string> numPounds;
    vector<string> fishNames;
    
    //cout << "argc "<<argc<<" argv[0] "<<argv[0]<<" argv[1]= "<<argv[1]<<endl;
    if(argc != 2) {
        cout << "Usage: "<<argv[0]<<" <filename>"<<endl;
    } else {
        ifstream fileHandle(argv[1]);
        if(!fileHandle.is_open()) {
            cout << "Could not open file"<<endl;
        } else {
            string name, fish;
            string pound;
            while(fileHandle>>name>>pound>>fish) {
                cout << name << "\t\t" << pound << "\t" << fish << endl;
                if (name != "Search") {
                    names.push_back(name);
                    numPounds.push_back(pound);
                    fishNames.push_back(fish);
                }
            }
            
            cout << endl << "Type wanted: " << pound << endl;
            
            for (int i = 0; i < fishNames.size(); i++) {
                if (fishNames.at(i) == pound) {
                    cout << names.at(i) << " caught " << numPounds.at(i) << " pounds of " << pound << endl;
                }
            }
        }
    }
    sort(names.begin(), names.end());
    ofstream outHandle("sorted.txt");
    for(vector<string>::iterator it=names.begin();
      it!=names.end(); it++) {
          //cout << *it<<endl;
          outHandle << *it <<endl;
    }
    //cout << "Using print"<<endl;
    //print(names);
}