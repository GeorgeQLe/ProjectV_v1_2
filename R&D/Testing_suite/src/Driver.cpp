/*  Copyright 2017 George Le

    Command station of the Concept IO unit test suite
    
    To run, type command to execute unit tests
    ./tests (# of unit test)
*/
#include <iostream> // std::cout, std::endl
#include <stdlib.h> // atoi

#include "Unit_tests/Unit_test.h"

void PrintScore(unsigned int num_of_success, unsigned int total_successes);

int main()
{   
    // recieves an instance of the Unit Tests
    std::shared_ptr<UnitTestManager> unit_tester = UnitTestManager::GetInstance();
    
    // checks to see if there are unit tests to run 
    if(unit_tester->NumOfUnitTests() != 0)
    {
        PrintScore(unit_tester->RunUnitTests(), unit_tester->NumOfUnitTests());
    }
}

void PrintScore(unsigned int num_of_success, unsigned int total_successes)
{
    std::cout << "There were " << num_of_success << "/" << total_successes;
    std::cout << " successes." << std::endl;
}