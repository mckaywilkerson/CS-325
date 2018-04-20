#include <iostream>
#include <string>

using namespace std;

int main {

string numbers = "";
    int arrayptr[5] = {1, 2, 3, 4, 5};
    string numbers = "";
    int arrayCount = 4;
            for (int i = 0; i < arrayCount; i++) {
                numbers += arrayptr[i];
                numbers += ",";
                //numbers.append(arrayptr[i] + ",");
            }
    cout << numbers;
    return 0;
}