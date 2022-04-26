#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include <iostream>
#include <vector>
#pragma once

class QuickSort{

    private:

    public:
        // declaring the QuickSort constructor
        QuickSort(std::vector<int> arr, int start, int end);
        /* 
        -declaring the partition of the QuickSort
        -The partition works by selecting a element from the array and then breaking the array into two sub array, 
        based if they are greater or smaller than the pivot

        */
        int partition(std::vector<int> arr, int start, int end);

};

#endif
