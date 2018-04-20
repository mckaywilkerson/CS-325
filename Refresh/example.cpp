#include <iostream>
#include <vector>

using namespace std;

int main () {
    int min, temp, n;
    int nums[] = {23,14,65,3,19,2,71,12,8,61,5,25};
    
    n = 12;
    
    for (int i = 0; i < (n - 2); i++) {
        for (int j = i + 1; j < (n - 1); j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        temp = nums[min];
        nums[min] = nums[i];
        nums[i] = temp;
    }
    
    for (int k = 0; k < (n - 1); k++) {
        cout << nums[k];
    }
    
    
    
    return 0;
}