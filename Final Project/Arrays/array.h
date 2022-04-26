#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <algorithm>
#include <chrono>
#include <string>
#pragma once

class Array{
    
    private:
        // the reverse would hold reverse vector
        std::vector<int> reverse;
        // the partially would hold partially vector
        std::vector<int> partially;
        // the random would hold random vector
        std::vector<int> random;
        // the sorted would hold sorted vector
        std::vector<int> sorted;
        // current_size would serve a place holder, that would get updated with 
        unsigned int current_size;
        // range is the maximun and minimum number array can have or the range of it
        unsigned int range;

    public:
        Array(unsigned int f_size, int& counter, std::vector<std::vector<std::vector<double> > > &times);
        // member functions declarations, which would later be defined to create the different types of arrays
        void random_vector();
        void reverse_vector();
        void partially_sorted_vector();
        void sorted_vector();
      
        // member functions declarations, which would later be defined to call the different type of sorting algorithms and measure performings time
        void running_counting_sort(int counter, std::vector<std::vector<std::vector<double> > > &times);
        void running_merge_sort(int counter, std::vector<std::vector<std::vector<double> > > &times);
        void running_quick_sort(int counter, std::vector<std::vector<std::vector<double> > > &times);
        void running_insertion_sort(int counter, std::vector<std::vector<std::vector<double> > > &times);

        ~Array();

};

#endif
