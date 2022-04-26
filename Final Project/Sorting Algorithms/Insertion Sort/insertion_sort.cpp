#include "insertion_sort.h"

InsertionSort::InsertionSort(std::vector<int> arr){
    // declaring temp, which would serve as a place holder for arr[i]
    // declaring j, which would intialize the inner for loop of the nested for loop
    int temp, j;

    unsigned int i;

    for(i = 1; i < arr.size(); i++){
        // temp would equal to arr[i]
        temp = arr[i];
        // j equal to i - 1
        j = i - 1;
        // if j is greater or equal to zero  and arr[j] is less than temp
        while(j >= 0 && arr[j] > temp){
            // arr[j+1] equal to arr[j]
            arr[j + 1] = arr[j];
            // decrement by one
            j = j - 1;
        }
        // arr[j+1] equal to temp
        arr[j + 1] = temp;
    }
}
