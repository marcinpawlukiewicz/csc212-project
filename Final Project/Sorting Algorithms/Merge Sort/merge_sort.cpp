#include "merge_sort.h"

MergeSort::MergeSort(std::vector<int> arr, int const begin, int const end){
    // if being is greater or equal to end return the function
    if(begin >= end){
        return;
    }
    // mid is equal to (begin + (end-begin)/2) to prevent overflowing
    unsigned int mid = begin + (end-begin)/2; 
    MergeSort(arr, begin, mid);
    MergeSort(arr, mid+1, end);
    merge(arr, begin, mid, end);
}

void MergeSort::merge(std::vector<int> arr, unsigned int left, unsigned int mid, unsigned int right){

    // the size of the left vector will be mid - left + 1;
    int sub_vector_one = mid - left + 1;
    // the size of the right vector will be right - mid;
    int sub_vector_sec = right - mid;
    
    // declaring to integers to initialize two for loop
    unsigned int i, j;
    
    // this is copying the right data of arr into the left vector
    for(i = 0; i < sub_vector_one; i++){
        left_vector.push_back(arr[left+i]);
    }
    // this is copying the right data of arr into the right vector
    for(j = 0; j < sub_vector_sec; j++){
        // push back the data of the right vector from arr[mid + 1 + j]
        right_vector.push_back(arr[mid + 1 + j]);
    }
    // this would counter for the index of vector one
    unsigned int index_vector_one = 0;
    // this would counter for the index of vector sec
    unsigned int index_vector_sec = 0;
    // initialize the index of the vector at left
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
            // increment the index_vector_sec by one so we can keep track where to place the next element
            index_vector_sec++;
        }
        // increment the index of index_vector by one 
        index_vector++;
    }
    // if the index vector one doesn't surpass the sum of sub_vector_one proceed, there is space to add one interger
    while(index_vector_one < sub_vector_one){
        // at arr postion index_vector make that equal to the left_vector at postion index_vector_one
        arr[index_vector] = (left_vector)[index_vector_one];
        // increment index_vector_one by one
        index_vector_one++;
        // increment index_vector by on as one position has been added into the arr
        index_vector++;
    }

    while(index_vector_sec < sub_vector_sec){
        arr[index_vector] = (right_vector)[index_vector_sec];
        // increment index_vector_sec by one
        index_vector_sec++;
        // increment index_vector by on as one position has been added into the arr
        index_vector++;
    }
}#include "merge_sort.h"

MergeSort::MergeSort(std::vector<int> arr, int const begin, int const end){
    // if being is greater or equal to end return the function
    if(begin >= end){
        return;
    }
    // mid is equal to (begin + (end-begin)/2) to prevent overflowing
    unsigned int mid = begin + (end-begin)/2; 
    MergeSort(arr, begin, mid);
    MergeSort(arr, mid+1, end);
    merge(arr, begin, mid, end);
}

void MergeSort::merge(std::vector<int> arr, unsigned int left, unsigned int mid, unsigned int right){

    // the size of the left vector will be mid - left + 1;
    int sub_vector_one = mid - left + 1;
    // the size of the right vector will be right - mid;
    int sub_vector_sec = right - mid;
    
    // declaring to integers to initialize two for loop
    unsigned int i, j;
    
    // this is copying the right data of arr into the left vector
    for(i = 0; i < sub_vector_one; i++){
        left_vector.push_back(arr[left+i]);
    }
    // this is copying the right data of arr into the right vector
    for(j = 0; j < sub_vector_sec; j++){
        // push back the data of the right vector from arr[mid + 1 + j]
        right_vector.push_back(arr[mid + 1 + j]);
    }
    // this would counter for the index of vector one
    unsigned int index_vector_one = 0;
    // this would counter for the index of vector sec
    unsigned int index_vector_sec = 0;
    // initialize the index of the vector at left
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
            // increment the index_vector_sec by one so we can keep track where to place the next element
            index_vector_sec++;
        }
        // increment the index of index_vector by one 
        index_vector++;
    }
    // if the index vector one doesn't surpass the sum of sub_vector_one proceed, there is space to add one interger
    while(index_vector_one < sub_vector_one){
        // at arr postion index_vector make that equal to the left_vector at postion index_vector_one
        arr[index_vector] = (left_vector)[index_vector_one];
        // increment index_vector_one by one
        index_vector_one++;
        // increment index_vector by on as one position has been added into the arr
        index_vector++;
    }

    while(index_vector_sec < sub_vector_sec){
        arr[index_vector] = (right_vector)[index_vector_sec];
        // increment index_vector_sec by one
        index_vector_sec++;
        // increment index_vector by on as one position has been added into the arr
        index_vector++;
    }
}
