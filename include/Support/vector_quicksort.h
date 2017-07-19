/*  Copyright 2017 George Le
    Declaration of multiple functions that facilitate a generic quicksort of generic vectors
    
    Declarations:
        -Functions:
            -void quicksort(std::vector<Object>& list, unsigned int left, unsigned int right)
            -int partition(std::vector<Object>& list, unsigned int left, unsigned int right)
*/
#ifndef VECTOR_QUICKSORT_H
#define VECTOR_QUICKSORT_H

#include <vector>

// preconditions: Function requires a valid std::vector of comparable Objects, meaning 
// they all have a function pointer that enables them to compare to another of the same object
// comp is a generic function in for what you want to compare in the vectors
// (assume less than for smallest to largest, greater than for largest to smallest)
// postcondition: Returns void, std::vector<Object> list will be sorted in accordance
// to your functor definition
template<class Object, class Compare = std::less_equal<Object>>
void quicksort(std::vector<Object>& list, unsigned int left, unsigned int right, const Compare& comp = Compare());

template<class Object, class Compare = std::less_equal<Object>>
int partition(std::vector<Object>& list, unsigned int left, unsigned int right, const Compare& comp = Compare());

#include "vector_quicksort.imp"

#endif