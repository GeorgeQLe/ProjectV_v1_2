/*  Copyright 2017 George Le

    Command station of the Concept IO unit test suite
    
    To run, type command to execute unit tests
    ./tests (# of unit test)
*/
#include <stdlib.h> // atoi

#include "Unit_test.h"

int main(int argv, char* argc[])
{
    if(argv == 2)
    {
        unsigned int num_of_unit_tests = static_cast<unsigned int>(atoi(argc[argv - 1]));
        std::shared_ptr<UnitTestManager> unit_tester = UnitTestManager::GetInstance(num_of_unit_tests);
        unit_tester->perform_unit_tests();
    }
}