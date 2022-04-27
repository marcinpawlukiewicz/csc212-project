#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

#include <vector>
#include <iostream>
#pragma once

class MergeSort{

    private:
        std::vector<int> left_vector;
        std::vector<int> right_vector;

    public:
        void merge(std::vector<int> &arr, unsigned int left, unsigned int mid, unsigned int right);
        MergeSort(std::vector<int> &arr, int const begin, int const end);
        void print_array(std::vector<int> arr);

};

#endif