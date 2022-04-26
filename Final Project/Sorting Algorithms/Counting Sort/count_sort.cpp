#include "count_sort.h"
#include "array.h"

CountSort::CountSort(std::vector<int> arr){
    // find biggest element of the arr
    max = *max_element(arr.begin(), arr.end());
    //the find smallest element of the arr
    min = *min_element(arr.begin(), arr.end());
    // the range is biggest element and smallest element plus one so 
    range = max - min + 1;
    // create count vector that serve as to count the amount of time an element is founded within the arr
    std::vector<int> count(range);
    // create a output vector that would the final sorted array
    std::vector<int> output(arr.size());

    // this is counting the occurrence a particular element within arr and outputing the counter to the count vector
    for(unsigned int i = 0; i < arr.size(); i++){
        // at the postion in which the element was founded increment the count by one
        count[arr[i] - min]++;
    }

    for(unsigned int i = 1; i < count.size(); i++){
        // add the previous index with the current one to determine the correct location of the element later on
        count[i] += count[i-1];
        // count[i] = count[i] + count[i-1]
    }
    // this for would be intialized at position arr.size() and would end when i is less or equal to zero
    // the main objective of this for loop is to input the correct order of number by subracting one
    for(int i = arr.size() - 1; i >= 0; i--){
        // output at position count[arr[i]-min] - 1] = equal to the position of arr[i]
        output[count[arr[i] - min] - 1] = arr[i];
        // substract one to the count[arr[i] - min] as this would give the correct index in case there is a another element with same value
        count[arr[i] - min]--;
    }

    for(unsigned int i = 0; i < arr.size(); i++){
        // this organizing the information by replacing the existing data with the data  from the output(sorted data) into the arr
        arr[i] = (output[i]);
    }
}
