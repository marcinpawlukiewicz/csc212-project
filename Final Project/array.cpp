#include "Array/array.h"
#include "countingsort/counting_sort.h"
#include "mergesort/merge_sort.h"
#include "quicksort/quick_sort.h"
#include "insertion/insertion_sort.h"

// the current problem is that the array constructor is not producing
Array::Array(unsigned int size, int& counter, std::vector<std::vector<std::vector<double> > > &times){

    // the size of the object equal to the provided size
    this->current_size = size;
    // the range of the object equal to the provided range
    range = 10;

    reverse_vector();
    random_vector();
    partially_sorted_vector();
    sorted_vector();

    // running_counting_sort(counter, times);
    running_insertion_sort(counter, times);
    // running_quick_sort(counter, times);
    // running_merge_sort(counter, times);


    counter++;
}

void Array::random_vector(){

    unsigned int i;
    // this would produce a random seed
    srand((unsigned)time(NULL));
    // it would create a randomlist from i into the provided size
    for(i = 0; i < current_size/2; i++){
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

    for(i = 0; i < current_size/2; i++){
        // to provide the same probability of positive and negative numbers
        partially.push_back(rand() % range);
        partially.push_back((rand() % range)*-1);
    }
    // half life would be integer that would hold the half of the size of the vector
    // as we only want half of the vector to be sorted or the vector to be partially sorted
    unsigned int half_size = partially.size() / 2;

    std::partial_sort(partially.begin(), partially.begin() + half_size, partially.end());
}

void Array::sorted_vector(){

    unsigned int i;
    // this would produce a random seed
    srand((unsigned)time(NULL));

    for(i = 0; i < current_size/2; i++){
        sorted.push_back(rand() % range);
        sorted.push_back((rand() % range)*-1);
    }
    sort(sorted.begin(), sorted.end());
}

void Array::print_array(std::vector<int> arr){

    unsigned int i;

    for(i = 0; i < arr.size(); i++){

        std::cout << arr.at(i) << " ";
    }
    std::cout << "\n";
    std::cout << "\n";
}

Array::~Array(){

}

void Array::running_counting_sort(int counter, std::vector<std::vector<std::vector<double> > > &times){

    clock_t timer;
    timer = clock();
    CountSort test1(random);
    timer = clock() - timer;
    double time_taken = ((double)timer)/CLOCKS_PER_SEC;
    times[0][0][counter] = time_taken;

    clock_t reverse_timer;
    reverse_timer = clock();
    CountSort test2(reverse);
    reverse_timer = clock() - reverse_timer;
    double reverse_time_taken = ((double)reverse_timer)/CLOCKS_PER_SEC;
    times[1][0][counter] = reverse_time_taken;

    clock_t sorted_timer;
    sorted_timer = clock();
    CountSort test3(sorted);
    sorted_timer = clock() - sorted_timer;
    double sorted_time_taken = ((double)sorted_timer)/CLOCKS_PER_SEC;
    times[2][0][counter] = time_taken;

    clock_t partially_timer;
    partially_timer = clock();
    CountSort test4(partially);
    timer = clock() - timer;
    double partially_time_taken = ((double)partially_timer)/CLOCKS_PER_SEC;
    times[3][0][counter] = partially_time_taken;

    return;
}

void Array::running_insertion_sort(int counter, std::vector<std::vector<std::vector<double> > > &times){

    clock_t timer;
    timer = clock();
    InsertionSort test1(random);
    timer = clock() - timer;
    double time_taken = ((double)timer)/CLOCKS_PER_SEC;
    times[0][1][counter] = time_taken;

    clock_t reverse_timer;
    reverse_timer = clock();
    InsertionSort test2(reverse);
    reverse_timer = clock() - reverse_timer;
    double reverse_time_taken = ((double)reverse_timer)/CLOCKS_PER_SEC;
    times[1][1][counter] = reverse_time_taken;

    clock_t sorted_timer;
    sorted_timer = clock();
    InsertionSort test3(sorted);
    sorted_timer = clock() - sorted_timer;
    double sorted_time_taken = ((double)sorted_timer)/CLOCKS_PER_SEC;
    times[2][1][counter] = time_taken;

    clock_t partially_timer;
    partially_timer = clock();
    InsertionSort test4(partially);
    timer = clock() - timer;
    double partially_time_taken = ((double)partially_timer)/CLOCKS_PER_SEC;
    times[3][1][counter] = partially_time_taken;

    return;
}

void Array::running_merge_sort(int counter, std::vector<std::vector<std::vector<double> > > &times){

    clock_t timer;
    timer = clock();
    MergeSort test1(random, 0, random.size()-1);
    timer = clock() - timer;
    double time_taken = ((double)timer)/CLOCKS_PER_SEC;
    times[0][3][counter] = time_taken;

    clock_t reverse_timer;
    reverse_timer = clock();
    MergeSort test2(reverse, 0, reverse.size()-1);
    reverse_timer = clock() - reverse_timer;
    double reverse_time_taken = ((double)reverse_timer)/CLOCKS_PER_SEC;
    times[1][3][counter] = reverse_time_taken;

    clock_t sorted_timer;
    sorted_timer = clock();
    MergeSort test3(sorted, 0, sorted.size()-1);
    sorted_timer = clock() - sorted_timer;
    double sorted_time_taken = ((double)sorted_timer)/CLOCKS_PER_SEC;
    times[2][3][counter] = time_taken;

    clock_t partially_timer;
    partially_timer = clock();
    MergeSort test4(partially, 0, partially.size()-1);
    timer = clock() - timer;
    double partially_time_taken = ((double)partially_timer)/CLOCKS_PER_SEC;
    times[3][3][counter] = partially_time_taken;

    return;
}

void Array::running_quick_sort(int counter, std::vector<std::vector<std::vector<double> > > &times){

    clock_t timer;
    timer = clock();
    QuickSort test1(random, 0, random.size()-1);
    timer = clock() - timer;
    double time_taken = ((double)timer)/CLOCKS_PER_SEC;
    times[0][2][counter] = time_taken;

    clock_t reverse_timer;
    reverse_timer = clock();
    QuickSort test2(reverse, 0, reverse.size()-1);
    reverse_timer = clock() - reverse_timer;
    double reverse_time_taken = ((double)reverse_timer)/CLOCKS_PER_SEC;
    times[1][2][counter] = reverse_time_taken;

    clock_t sorted_timer;
    sorted_timer = clock();
    QuickSort test3(sorted, 0, sorted.size()-1);
    sorted_timer = clock() - sorted_timer;
    double sorted_time_taken = ((double)sorted_timer)/CLOCKS_PER_SEC;
    times[2][2][counter] = time_taken;

    clock_t partially_timer;
    partially_timer = clock();
    QuickSort test4(partially, 0, partially.size()-1);
    timer = clock() - timer;
    double partially_time_taken = ((double)partially_timer)/CLOCKS_PER_SEC;
    times[3][2][counter] = partially_time_taken;

    return;
}
