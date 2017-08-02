/*  Copyright 2017 George Le

    Unit tests for code in development

*/
#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <iostream>
#include <memory>
#include <vector>

#include "Grid.h"

class UnitTestManager
{
    public:
    void perform_unit_tests()
    {
        int successes = 0;
        
        // list functions here
    }
    
    static std::shared_ptr<UnitTestManager> GetInstance(unsigned int num_of_unit_tests)
    {
        static std::shared_ptr<UnitTestManager> instance(new UnitTestManager(num_of_unit_tests));
        
        return instance;
    }
    
    private:
    UnitTestManager(unsigned int num_of_unit_tests) : m_num_of_unit_tests(num_of_unit_tests) {}
    
    unsigned int m_num_of_unit_tests;
};

#endif // UNIT_TEST_H