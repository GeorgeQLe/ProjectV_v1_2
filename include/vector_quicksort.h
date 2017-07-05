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

template<class Object, class Compare = std::less_equal<Object>>
void quicksort(std::vector<Object>& list, unsigned int left, unsigned int right, const Compare& comp = Compare());

template<class Object, class Compare = std::less_equal<Object>>
int partition(std::vector<Object>& list, unsigned int left, unsigned int right, const Compare& comp = Compare());

#include "vector_quicksort.imp"

#endif