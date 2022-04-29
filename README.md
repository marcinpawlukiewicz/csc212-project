# CSC 212 Final Project Sorting Algorithms

#### Creators: Marcin Pawlukiewicz, Jeshua Benzant, Lisandro Torres

## Sorting Algorithms Benchmark

  The Sorting Algorithms Benchmark is a program that allows users to compare the total amount of time of different sorting algorithms, such as insertion sort, quicksort, mergesort, and counting sort required to sort input arrays in ascending orders. The input arrays that the program would test range from a sorted, partially sorted, random, and reverse array to test how different input arrays would make the different sorting algorithms behave relative to time. Furthermore, the user would select a range of sizes that they would like the input arrays to be. Finally, the Sorting Algorithm Benchmarked will provide the user with the data with all four sorting algorithms and illustrate their time performance with the different input arrays in the terminal.


## Dependencies

The following files are needed in order to compile the Project: array.cpp merge_sort.cpp main.cpp counting_sort.cpp quick_sort.cpp insertion_sort.cpp main.cpp

When you go to download and compile these files, before compiling, make sure all of the files are in the same directory all together. This avoids any confusion and any errors that may occur within the main.cpp.

When compiling, there is a main argument after compiling the named files (ie ./main), it is an intenger greater than 0 for how big they wish for the size of the array to be. 

## Results

The results shown for when the file compiles is a neatly edited format in the terminal showing different algorithms benchmarked after certain data sets. Arrays will separate the data into the different types of Arrays (randomized, partially sorted, Sorted, Reverse), with all 5 algorithms showing their benchmarked times.
