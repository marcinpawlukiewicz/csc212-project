#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

#include <vector>
#include <iostream>
#pragma once

class MergeSort{

    private:
        // declaring the left vector which would hold the left data of arr when divided
        std::vector<int> left_vector;
        // declaring the right vector which would hold the left data of arr when divided
        std::vector<int> right_vector;

    public:
        // merge is where the array are going to be divide
        void merge(std::vector<int> arr, unsigned int left, unsigned int mid, unsigned int right);
        // declaration of the constructor for MergeSort
        MergeSort(std::vector<int> arr, int const begin, int const end);

};

#endif
