/*  Copyright 2017 George Le

    Unit tests for code in development

    The UnitTestManager class is designed to recieve a series of unit tests 
    as function pointers from the user and then run from the main driver program. 
    The user inputs the functions in the UnitTestManager's constructor, where
    following the given example as a guide, the user will push_back a function
    pointer created by the std::bind 
*/
#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <functional> // std::function, std::bind
#include <list> // std::list
#include <memory> // std::shared_ptr
#include <string> // std::string

class UnitTestManager
{
    public:
    // performs all the unit tests in the list of test cases and
    // returns the number of successes
    unsigned int RunUnitTests();
    
    // returns the total number of lists
    unsigned int NumOfUnitTests() const { return m_test_cases.size(); }
    
    static std::shared_ptr<UnitTestManager> GetInstance()
    {
        static std::shared_ptr<UnitTestManager> instance(new UnitTestManager());
        
        return instance;
    }
    
    private:
    UnitTestManager()
    {
        /*  Add unit test functions here to m_test_cases.
           
            Ex.
            m_test_case.push_back( {"NameOfTestFunction, Parameter", std::bind(NameOfTestFunction, 0, passed_parameters)} );
        */
        
        
    }
    
    std::list<std::pair< const std::string, std::function<bool()>>> m_test_cases;
};

#endif // UNIT_TEST_H