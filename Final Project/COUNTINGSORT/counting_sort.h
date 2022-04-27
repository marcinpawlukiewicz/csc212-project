#ifndef __COUNT_SORT_H__
#define __COUNT_SORT_H__

#include <iostream>
#include <vector>
#include <algorithm>
#pragma once

class CountSort{

    private:
        // this int will hold the highest value founded within the array/vector
        int max;
        // this int will hold the lowest value founded within the array/vector
        int min;
        int range;

    public:
        // this is the method which would be utilize to sort arr
        CountSort(std::vector<int> arr);
        // this method would output the sorted array
        void printarray(std::vector<int> arr);

};

#endif