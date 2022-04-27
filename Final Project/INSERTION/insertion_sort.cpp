#include "insertion_sort.h"

InsertionSort::InsertionSort(std::vector<int> arr){

    int temp, j;
    unsigned int i;

    for(i = 1; i < arr.size(); i++){

        temp = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = temp;
    }
}
