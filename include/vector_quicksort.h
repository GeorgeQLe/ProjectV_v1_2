/*  Copyright 2017 George Le
    Declaration of multiple functions that facilitate a generic quicksort of generic vectors
    
    Declarations:
        -Functions:
            -void quicksort(std::vector<T>& list, unsigned int left, unsigned int right)
            -int partition(std::vector<T>& list, unsigned int left, unsigned int right)
*/
#ifndef VECTOR_QUICKSORT_H
#define VECTOR_QUICKSORT_H

#include <vector>

template<class T, class Compare = std::less_equal<T>>
void quicksort(std::vector<T>& list, unsigned int left, unsigned int right, const Compare& comp = Compare());

template<class T, class Compare = std::less_equal<T>>
int partition(std::vector<T>& list, unsigned int left, unsigned int right, const Compare& comp = Compare());

#include "vector_quicksort.imp"

#endif
