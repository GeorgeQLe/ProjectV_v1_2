#include <iostream>
#include <fstream>
#include <string>
#include "Support/random_messages.h"
#include "Support/random.h"

void select_random_response(const std::string& file_name, int number_of_lines)
{
    std::string line;
    ifstream file(file_name)
    int counter = 0, line_number = roll_d_whatever(number_of_lines);
    
    if(file.is_open())
    {
        while(getline(file, line))
        {
            if(counter == line_number)
            {
                std::cout << line << std::endl;
            }
        }
    }
}