#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

#include <vector>
#pragma once

class QuickSort{

    private:
        // unsigned int pivot_index;
        // int pivot;
        // unsigned int tracker;

    public:
        QuickSort(std::vector<int> arr, int start, int end);
        int partition(std::vector<int> arr, int start, int end);
        void print_array(std::vector<int> arr);

};

#endif