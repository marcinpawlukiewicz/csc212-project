#include <iostream>
#include "quick_sort.h"

QuickSort::QuickSort(std::vector<int> arr, int start, int end){

    // if the start is greater or equal to end return nothing, which would mark end to the function
    if(start >= end){
        return;
    }

    int p = partition(arr, start, end);

    QuickSort(arr, start, p - 1);
    QuickSort(arr, p + 1, end);
}

int QuickSort::partition(std::vector<int> arr, int start, int end){

    unsigned int i, j, pivot_index, tracker = 0;

    int pivot = arr[start];

    for(i = start + 1; i <= end; i++){
        if(arr[i] <= pivot){
            tracker++;
        }
    }

    pivot_index = start + tracker;

    std::swap(arr[pivot_index], arr[start]);

    i = start;
    j = end;

    while(i < pivot_index && j > pivot_index){
        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < pivot_index && pivot_index < j){
            std::swap(arr[i++], arr[j--]);
        }

    }

    return pivot_index;
}