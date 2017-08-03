/*  Copyright 2017 George Le
    
    Definition of the member function of UnitTestManager, void RunUnitTests()
*/
#include <iostream>
#include "Unit_tests/Unit_test.h"

unsigned int UnitTestManager::RunUnitTests()
{
    // the number of successful unit tests conducted
   unsigned int f_score = 0;
    
    for (auto& test : m_test_cases)
    {
        // prints out the name of the unit test
    	std::cout << test.first << "\t...\t";
    	
    	// performs the unit test and sets f_success 
    	// equal to the result
    	bool f_success = test.second();
 
        // print out success or failure
    	std::cout << (f_success ? " success" : " fail") << std::endl;
 
        // increment the score if f_success is true
        f_score += (f_success ? 1 : 0);
    }
    
    return f_score;
}