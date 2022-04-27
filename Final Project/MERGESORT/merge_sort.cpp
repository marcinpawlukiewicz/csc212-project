#include "merge_sort.h"

MergeSort::MergeSort(std::vector<int> &arr, int const begin, int const end){

    if(begin >= end){
        return;
    }

    unsigned int mid = begin + (end-begin)/2;
    MergeSort(arr, begin, mid);
    MergeSort(arr, mid+1, end);
    merge(arr, begin, mid, end);
}

void MergeSort::merge(std::vector<int> &arr, unsigned int left, unsigned int mid, unsigned int right){

    int sub_vector_one = mid - left + 1;
    int sub_vector_sec = right - mid;
    unsigned int i, j;

    for(i = 0; i < sub_vector_one; i++){
        left_vector.push_back(arr[left+i]);
    }

    for(j = 0; j < sub_vector_sec; j++){
        right_vector.push_back(arr[mid + 1 + j]);
    }

    unsigned int index_vector_one = 0;
    unsigned int index_vector_sec = 0;
    int index_vector = left;

    while(index_vector_one < sub_vector_one && index_vector_sec < sub_vector_sec){
        // if the current element at index_vector_one is smaller than the element at index_vector_sec
        if(left_vector[index_vector_one] <= right_vector[index_vector_sec]){
            // at arr index_vector push back the left_vector at index_vector_one
            arr[index_vector] = (left_vector)[index_vector_one];
            // increment the index_vector_one by one so we can keep track where to place the next element
            index_vector_one++;
        }else{
            // if the right_vector element is smaller than the current element at the left_vector this else statement will be executed
            arr[index_vector] = (right_vector)[index_vector_sec];
            index_vector_sec++;
        }
        index_vector++;
    }

    while(index_vector_one < sub_vector_one){
        arr[index_vector] = (left_vector)[index_vector_one];
        index_vector_one++;
        index_vector++;
    }

    while(index_vector_sec < sub_vector_sec){
        arr[index_vector] = (right_vector)[index_vector_sec];
        index_vector_sec++;
        index_vector++;
    }
}
void MergeSort::print_array(std::vector<int> arr){

    for(int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
}
