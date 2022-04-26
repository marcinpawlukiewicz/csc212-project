#include "array.h"
#include "count_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "insertion_sort.h"

// the current problem is that the array constructor is not producing 
Array::Array(unsigned int size, int& counter, std::vector<std::vector<std::vector<double> > > &times){
    
    // the size of the object equal to the provided size
    this->current_size = size;
    // the range of the object equal to the provided range
    range = 1000;
    // calling the reverse vector function which would create a reverse vector to be utilized for the different sorting algorithms
    reverse_vector();
    // calling the random vector function which would create a random vector to be utilized for the different sorting algorithms
    random_vector();
    partially_sorted_vector();
    sorted_vector();
    // this calling all the sorting algorithm and benchmarking 
    running_counting_sort(counter, times);
    running_insertion_sort(counter, times);
    running_quick_sort(counter, times);
    running_merge_sort(counter, times);
    // increment the counter by one so when the next constructor is call the value would be append int the next column
    counter++;
}

void Array::random_vector(){

    unsigned int i;
    // this would produce a random seed
    srand((unsigned)time(NULL));
    // it would create a randomlist from i into the provided size
    for(i = 0; i < current_size/2; i++){
        // random vector would include the same amount of negative and positive interger
        random.push_back(rand() % range);
        random.push_back((rand() % range)*-1);
    }
}

void Array::reverse_vector(){

    unsigned int i;
    // this would produce a random seed
    srand((unsigned)time(NULL));
    // the for loop would only range from 0 to f_size/2 as a positive and negative for every increment of i
    for(i = 0; i < current_size/2; i++){
        // to provide the same probability of positive and negative numbers
        reverse.push_back(rand() % range);
        reverse.push_back((rand() % range)*-1);
    }
    // this would sort the array in descending or reverse order
    sort(reverse.begin(), reverse.end(), std::greater<int>());
}

void Array::partially_sorted_vector(){

    unsigned int i;
    // this would produce a random seed
    srand((unsigned)time(NULL));
    // the for loop would only range from 0 to f_size/2 as a positive and negative for every increment of i
    for(i = 0; i < current_size/2; i++){
        // to provide the same probability of positive and negative numbers
        partially.push_back(rand() % range);
        partially.push_back((rand() % range)*-1);
    }
    // half life would be integer that would hold the half of the size of the vector
    // as we only want half of the vector to be sorted or the vector to be partially sorted
    unsigned int half_size = partially.size() / 2;
    // this would partially sort the provided array from the beginning to the middle 
    std::partial_sort(partially.begin(), partially.begin() + half_size, partially.end());
}

void Array::sorted_vector(){

    unsigned int i;
    // this would produce a random seed
    srand((unsigned)time(NULL));
    // the for loop would only range from 0 to f_size/2 as a positive and negative for every increment of i
    for(i = 0; i < current_size/2; i++){
        // to provide the same probability of positive and negative numbers
        sorted.push_back(rand() % range);
        sorted.push_back((rand() % range)*-1);
    }
    sort(sorted.begin(), sorted.end());
}

Array::~Array(){

}

void Array::running_counting_sort(int counter, std::vector<std::vector<std::vector<double> > > &times){
    // called the clock_class and the constructor as timer
    clock_t timer;
    timer = clock();
     // call the CountSort constructor
    CountSort test1(random);
    timer = clock() - timer;
    double time_taken = ((double)timer)/CLOCKS_PER_SEC;
    times[0][0][counter] = time_taken;

    // called the clock_class and the constructor as timer
    clock_t reverse_timer;
    reverse_timer = clock();
     // call the CountSort constructor
    CountSort test2(reverse);
    reverse_timer = clock() - reverse_timer;
    double reverse_time_taken = ((double)reverse_timer)/CLOCKS_PER_SEC;
    times[1][0][counter] = reverse_time_taken;
    
    clock_t sorted_timer;
    sorted_timer = clock();
     // call the CountSort constructor
    CountSort test3(sorted);
    sorted_timer = clock() - sorted_timer;
    double sorted_time_taken = ((double)sorted_timer)/CLOCKS_PER_SEC;
    times[2][0][counter] = time_taken;
    // called the clock_class and the constructor as partially timer
    clock_t partially_timer;
    partially_timer = clock();
    // call the CountSort constructor
    CountSort test4(partially);
    timer = clock() - timer;
    double partially_time_taken = ((double)partially_timer)/CLOCKS_PER_SEC;
    times[3][0][counter] = partially_time_taken;

    return; 
}

void Array::running_insertion_sort(int counter, std::vector<std::vector<std::vector<double> > > &times){
    // called the clock_class and the constructor as timer
    clock_t timer;
    timer = clock();
    // call the InsertionSort constructor
    InsertionSort test1(random);
    timer = clock() - timer;
    double time_taken = ((double)timer)/CLOCKS_PER_SEC;
    times[0][1][counter] = time_taken;
    // called the clock_class and the constructor as reverse timer
    clock_t reverse_timer;
    reverse_timer = clock();
    // call the InsertionSort constructor
    InsertionSort test2(reverse);
    reverse_timer = clock() - reverse_timer;
    double reverse_time_taken = ((double)reverse_timer)/CLOCKS_PER_SEC;
    times[1][1][counter] = reverse_time_taken;
    // called the clock_class and the constructor as sorted timer
    clock_t sorted_timer;
    sorted_timer = clock();
    // call the InsertionSort constructor
    InsertionSort test3(sorted);
    sorted_timer = clock() - sorted_timer;
    double sorted_time_taken = ((double)sorted_timer)/CLOCKS_PER_SEC;
    times[2][1][counter] = time_taken;
    // called the clock_class and the constructor as partially timer
    clock_t partially_timer;
    partially_timer = clock();
    // call the InsertionSort constructor
    InsertionSort test4(partially);
    timer = clock() - timer;
    double partially_time_taken = ((double)partially_timer)/CLOCKS_PER_SEC;
    times[3][1][counter] = partially_time_taken;

    return; 
}

void Array::running_merge_sort(int counter, std::vector<std::vector<std::vector<double> > > &times){
    // called the clock_class and the constructor as timer
    clock_t timer;
      // begin timer
    timer = clock();
    // call the MergeSort constructor
    MergeSort test1(random, 0, random.size()-1);
    // end timer
    timer = clock() - timer;
    double time_taken = ((double)timer)/CLOCKS_PER_SEC;
    times[0][3][counter] = time_taken;

    clock_t reverse_timer;
      // begin timer
    reverse_timer = clock();
    // call the MergeSort constructor
    MergeSort test2(reverse, 0, reverse.size()-1);
     // end timer
    reverse_timer = clock() - reverse_timer;
    double reverse_time_taken = ((double)reverse_timer)/CLOCKS_PER_SEC;
    times[1][3][counter] = reverse_time_taken;
    
    clock_t sorted_timer;
      // begin timer
    sorted_timer = clock();
    // call the MergeSort constructor
    MergeSort test3(sorted, 0, sorted.size()-1);
     // end timer
    sorted_timer = clock() - sorted_timer;
    double sorted_time_taken = ((double)sorted_timer)/CLOCKS_PER_SEC;
    times[2][3][counter] = time_taken;
    // called the clock_class and the constructor as partially timer
    clock_t partially_timer;
    partially_timer = clock();
    // the QuickSort constructor
    MergeSort test4(partially, 0, partially.size()-1);
    timer = clock() - timer;
    double partially_time_taken = ((double)partially_timer)/CLOCKS_PER_SEC;
    times[3][3][counter] = partially_time_taken;

    return; 
}

void Array::running_quick_sort(int counter, std::vector<std::vector<std::vector<double> > > &times){
    // called the clock_class and the constructor as timer
    clock_t timer;
    timer = clock();
       // call the QuickSort constructor
    QuickSort test1(random, 0, random.size()-1);
     // end timer
    timer = clock() - timer;
    double time_taken = ((double)timer)/CLOCKS_PER_SEC;
    times[0][2][counter] = time_taken;

    clock_t reverse_timer;
      // begin timer
    reverse_timer = clock();
    // call the QuickSort constructor
    QuickSort test2(reverse, 0, reverse.size()-1);
     // end timer
    reverse_timer = clock() - reverse_timer;
    double reverse_time_taken = ((double)reverse_timer)/CLOCKS_PER_SEC;
    times[1][2][counter] = reverse_time_taken;
    
    clock_t sorted_timer;
    sorted_timer = clock();
    // call the QuickSort constructor
    QuickSort test3(sorted, 0, sorted.size()-1);
     // end timer
    sorted_timer = clock() - sorted_timer;
    double sorted_time_taken = ((double)sorted_timer)/CLOCKS_PER_SEC;
    times[2][2][counter] = time_taken;
    // called the clock_class and the constructor as partially timer
    clock_t partially_timer;
    // begin timer
    partially_timer = clock();
    // call the QuickSort constructor
    QuickSort test4(partially, 0, partially.size()-1);
     // end timer
    timer = clock() - timer;
    double partially_time_taken = ((double)partially_timer)/CLOCKS_PER_SEC;
    times[3][2][counter] = partially_time_taken;

    return; 
}
