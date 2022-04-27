#include "array.h"

int main(int argc, char* argv[]){
    
    unsigned int size = std::stoi(argv[1]);

    // this counter would the total about of time the array constructor is being called 
    int counter = 0;
    // this is the declaration of the 3d vector, which would contain all the times for different sorting algor
    std::vector<std::vector<std::vector<double> > > times (4, std::vector<std::vector<double> >(4, std::vector<double>(5,0.0)));
    // calling the array constructor with a size of 5000, counter would serve to know where the next num would be save in the 3d vector
    Array sample1((size*1)/5, counter, times);
    Array sample2((size*2)/5, counter, times);
    Array sample3((size*3)/5, counter, times);
    Array sample4((size*4)/5, counter, times);
    Array sample5((size*5)/5, counter, times);

    std::cout << std::endl;
   
    for( int i = 0; i < times.size(); i++){
            if(i == 0){

                std::cout << std::endl;
                std::cout << "\t \t " <<(size*1)/5 <<   " \t\t"  << (size*2)/5 << " \t   " << (size*3)/5 <<  " \t \t" <<  (size*4)/5 << "\t\t" << (size*5)/5 <<  std::endl;
                std::cout << std::endl;
                std::cout << "Random:" << std::endl;
                std::cout << std::endl;
            }
            if(i == 1){

                std::cout << "Reverse:" << std::endl;
                std::cout << std::endl;
            }   
            if(i == 2){

                std::cout << "Sorted:" << std::endl;
                std::cout << std::endl;
            }   
            if(i == 3){

                std::cout << "Partially:" << std::endl;
                std::cout << std::endl;
            }   
        for(int j = 0; j < times[i].size(); j++){
            if(j == 3){

                std::cout << "MergeSort: \t" ;
            }
            if(j == 2){

                std::cout << "QuickSort: \t" ;
            }
            if(j == 0){

                std::cout << "CountingSort: \t" ;
            }
            if(j == 1){

                std::cout << "Insertion: \t" ;
            }
            for(int k = 0; k < times[i][j].size(); k++){
                std::cout << times[i][j][k] << "     ";
            }   
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
