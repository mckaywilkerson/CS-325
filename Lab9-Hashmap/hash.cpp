#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
int hashme(T param, int tablesize) {
    unsigned char *ptr = (unsigned char *)&param;
    int sum = 0;
    for(int i = 0; i < sizeof(param); i++) {
        sum += ptr[i];
    }
    int hashval = sum%tablesize;
    cout << "Size = "<<sizeof(param)<<" Sum = "<<sum<<" hash "<<hashval<<endl;
    return hashval;
}
int main()
{
    const int tablesize = 11;
    vector<string> strvec;
    string foo("Hello");
    cout << "Hash of Hello "<<hashme<string>(foo, tablesize)<<endl;
    strvec.push_back(foo);
    cout << "Hash of vector "<<hashme<vector<string>>(strvec, tablesize)<<endl;
    foo = "Goodbye";
    cout << "Hash of Goodbye "<<hashme<string>(foo, tablesize)<<endl;
    strvec.push_back(foo);
    cout << "Hash of vector "<<hashme<vector<string>>(strvec, tablesize)<<endl;
}