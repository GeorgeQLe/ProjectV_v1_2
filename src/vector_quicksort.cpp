/*  Copyright 2017 George Le
    Definition of functions declared in vector_quicksort.h

*/
#include <algorithm> // for std::swap()
#include "vector_quicksort.h"

template<class T>
void quicksort(std::vector<T>& list, unsigned int left, unsigned int right)
{
    int f_partition;
    // ensure that left is less than right as it should
    if(left < right)
    {
        // get the partition for the quick sort and sort from the left to the right
        f_partition = partition(list, left, right);
        // recursively call quicksort with the new partition being the right
        quicksort(list , left, f_partition);  
        // recursively call quicksort with the new partition incremented by 1 being
        // the left hand side
        quicksort(list, f_partition+1, right);
    }
}

template<class T>
int partition(std::vector<T>& list, unsigned int left, unsigned int right)
{
    // set partition equal to the right
    int f_partition = left;
    // create a temporary reference to the element in the vector at the left
    T f_temp = list.at(left);
    
    // compare from the left hand element to the right hand element, the right
    // hand element being the partition
    for(unsigned int i = left+1; i < right; i++)
    {
        // change functions for what you want to compare in the vectors
        // if the element in the vector at the left+1 position is less than or 
        // equal to the element at the left position then execute within this
        if(list.at(i).speed() <= f_temp.speed())
        {
            // increment the partition
            f_partition++;
            // swap the elements at the partition with the element at the 
            // i'th position
            std::swap(list.at(f_partition), list.at(i));
        }
    }
    // swap the partition with the left hand side
    std::swap(list.at(f_partition), list.at(left));
    return f_partition;
}