#include "QS.h"

/*
SLIDES
Before: set median of the first, middle and last as the first element (so it can be the pivot)
Partitioning (first element as pivot)

take first element
then start from left and find first value that is > my pivot
then start from right and find first value that is < my pivot
exchange those values

repeat

keep going until you get the > value on the right side of the < value
then replace pivot with the < value

NOW ITS IN THE MIDDLE
*/

	/*
	* sortAll()
	*
	* Sorts elements of the array.  After this function is called, every
	* element in the array is less than or equal its successor.
	*
	* Does nothing if the array is empty.
	*/
void QS::sortAll() {
    quicksort(0, arrayCount - 1);
}

bool QS::quicksort(int first, int last) {
    if ((last - first) < 2) {
        return true;
    }
    int pivot = medianOfThree(first, last);
    pivot = partition(first, last, pivot);
    quicksort(first, pivot);
    quicksort(pivot + 1, last);
    return true;
}

	/*
	* medianOfThree()
	*
	* The median of three pivot selection has two parts:
	*
	* 1) Calculates the middle index by averaging the given left and right indices:
	*
	* middle = (left + right)/2
	*
	* 2) Then bubble-sorts the values at the left, middle, and right indices.
	*
	* After this method is called, data[left] <= data[middle] <= data[right].
	* The middle index will be returned.
	*
	* Returns -1 if the array is empty, if either of the given integers
	* is out of bounds, or if the left index is not less than the right
	* index.
	*
	* @param left
	* 		the left boundary for the subarray from which to find a pivot
	* @param right
	* 		the right boundary for the subarray from which to find a pivot
	* @return
	*		the index of the pivot (middle index); -1 if provided with invalid input
	*/
int QS::medianOfThree(int left, int right) {
    int middle, holder;
    
    // error checking
    if (arrayptr == 0) {
        return -1;
    }
    else if (right <= left) {
        return -1;
    }
    else if (left < 0 || right < 0) {
        return -1;
    }
    else if (left >= arrayCount || right >= arrayCount) {
        return -1;
    }
    
    //main program
    else {   
        middle = (left + right) / 2;
        
        //sorting left, middle, and right array values
        if (arrayptr[left] > arrayptr[middle]) {
            holder = arrayptr[left];
            arrayptr[left] = arrayptr[middle];
            arrayptr[middle] = holder;
        }
        if (arrayptr[right] < arrayptr[middle]) {
            holder = arrayptr[middle];
            arrayptr[middle] = arrayptr[right];
            arrayptr[right] = holder;
        }
        if (arrayptr[middle] < arrayptr[left]) {
            holder = arrayptr[left];
            arrayptr[left] = arrayptr[middle];
            arrayptr[middle] = holder;
        }
        
        return middle;
    }
}

	/*
	* Partitions a subarray around a pivot value selected according to
	* median-of-three pivot selection.  Because there are multiple ways to partition a list,
	* we will follow the algorithm on page 611 of the course text when testing this function.
	*
	* The values which are smaller than the pivot should be placed to the left
	* of the pivot; the values which are larger than the pivot should be placed
	* to the right of the pivot.
	*
	* Returns -1 if the array is null, if either of the given integers is out of
	* bounds, or if the first integer is not less than the second integer, or if the
	* pivot is not within the sub-array designated by left and right.
	*
	* @param left
	* 		the left boundary for the subarray to partition
	* @param right
	* 		the right boundary for the subarray to partition
	* @param pivotIndex
	* 		the index of the pivot in the subarray
	* @return
	*		the pivot's ending index after the partition completes; -1 if
	* 		provided with bad input
	*/
int QS::partition(int left, int right, int pivotIndex) {
    // error checking
    if (arrayptr == 0) {
        return -1;
    }
    else if (right <= left) {
        return -1;
    }
    else if (left < 0 || right < 0) {
        return -1;
    }
    else if (left >= arrayCount || right >= arrayCount) {
        return -1;
    }
    else if (pivotIndex < left || pivotIndex > right) {
        return -1;
    }
    
    else {
    int temp = arrayptr[pivotIndex];
    arrayptr[pivotIndex] = arrayptr[left];
    arrayptr[left] = temp;
    
    int up = left + 1;
    int down = right;
    
    do {
        while ((arrayptr[up] <= arrayptr[left]) && (up < right)) {
            up++;
        }
        while ((arrayptr[down] >= arrayptr[left]) && (down > left)) {
            down--;
        }
        
        if (up < down) {
            temp = arrayptr[up];
            arrayptr[up] = arrayptr[down];
            arrayptr[down] = temp;
        }
        
    } while (up < down);
    
    temp = arrayptr[left];
    arrayptr[left] = arrayptr[down];
    arrayptr[down] = temp;
    
    return down;
    }
}

	/*
	* Produces a comma delimited string representation of the array. For example: if my array
	* looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
	* with no trailing comma.  The number of cells included equals the number of values added.
	* Do not include the entire array if the array has yet to be filled.
	*
	* Returns an empty string, if the array is NULL or empty.
	*
	* @return
	*		the string representation of the current array
	*/
string QS::getArray() const {
    ostringstream oss;
    if (arrayptr != 0) {
        if (arrayCount > 0) {
            for (int i = 0; i < arrayCount; i++) {
                oss << arrayptr[i] << ",";
            }
            string numbers = oss.str();
            numbers.pop_back();
            return numbers;
        }
        else {
            return "";
        }
    }
    else {
        return "";
    }
}

	/*
	* Returns the number of elements which have been added to the array.
	*/
int QS::getSize() const {
    return arrayCount;
}

	/*
	* Adds the given value to the end of the array starting at index 0.
	* For example, the first time addToArray is called,
	* the give value should be found at index 0.
	* 2nd time, value should be found at index 1.
	* 3rd, index 2, etc up to its max capacity.
	*
	* If the array is filled, do nothing.
	* returns true if a value was added, false otherwise.
	*/
bool QS::addToArray(int value) {
    if (arrayCount < arraySize) {
        arrayptr[arrayCount] = value;
        arrayCount ++;
        return true;
    }
    else {
        return false;
    }
}

	/*
	* Dynamically allocates an array with the given capacity.
	* If a previous array had been allocated, delete the previous array.
	* Returns false if the given capacity is non-positive, true otherwise.
	*
	* @param
	*		size of array
	* @return
	*		true if the array was created, false otherwise
	*/
bool QS::createArray(int capacity) {
    if (capacity > 0) {
        arrayCount = 0;
        if (arrayptr != 0) {
            clear();
        }
        arrayptr = new int [capacity];
        arraySize = capacity;
        return true;
    }
    else {
        return false;
    }
}

	/*
	* Resets the array to an empty or NULL state.
	*/
void QS::clear() {
    delete[] arrayptr;
    arrayptr = 0;
    arrayCount = 0;
}