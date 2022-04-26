#include "quick_sort.h"

QuickSort::QuickSort(std::vector<int> arr, int start, int end){
    
    // if the start is greater or equal to end return nothing, which would mark end to the function
    if(start >= end){
        return;
    }
    
    int p = partition(arr, start, end);
    // recall the QuickSort constructor and subract one from the partition to be passed an argument for end
    QuickSort(arr, start, p - 1);
    // recall the QuickSort constructor and add one from the partition to be passed an argument for start
    QuickSort(arr, p + 1, end);
}

int QuickSort::partition(std::vector<int> arr, int start, int end){

    unsigned int i, j, pivot_index, tracker = 0;

    int pivot = arr[end];

    for(i = start + 1; i <= end; i++){
        if(arr[i] <= pivot){
            tracker++;
        }
    }
    // the current pivot_index is start plus the tracker
    pivot_index = start + tracker;

    std::swap(arr[pivot_index], arr[start]);
    // i will be intialize at start
    i = start;
    // j will be intialize at end
    j = end;

    while(i < pivot_index && j > pivot_index){
        // while the arr at position i is smaller than the pivot, increment i by one
        while(arr[i] <= pivot){
            i++;
        }
        // while arr at position a is greater than the pivot decrement j by one
        while(arr[j] > pivot){
            j--;
        }
        // if the i and j cross each other swap them
        if(i < pivot_index && pivot_index < j){
            std::swap(arr[i++], arr[j--]);
        }

    }
    return pivot_index;
}
