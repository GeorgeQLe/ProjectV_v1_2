/*  Copyright 2016 George Le
    Very useful functions for any project really
    
    Declaration:
        functions:
            -void read_files(const std::string& file_name)
            -void print_line(const std::string& line)
            -void print_list(const std::vector<std::string>& list_of_strings)
            -int get_number_from_user(int smallest_possible_choice, int largest_possible_choice)
            -std::string getline_from_user_unrestricted()
            -std::string getline_from_user_restricted(unsigned int min_length, unsigned int max_length)
            -bool get_y_or_n_as_bool()
            -void clear_screen()
*/
#ifndef SUPPORT_H
#define SUPPORT_H
#include <vector>
#include <string>

// output functions

// precondition: Function parameter takes in a name of file and passes it as a const reference
// postcondition: Returns void and upon successful opening of the file, reads and write to the 
//				 screen the contents of the file. Upon failure of opening the file, execute exit
void read_files(const std::string& file_name);

// precondition: Function parameter takes in one valid std::string and pass it as a const reference
// postcondition: Prints the string with newline to the terminal window and returns void
void print_line(const std::string& line);

// precondition: Function parameter takes in a valid vector of strings and pass it as a const reference
// postcondition: Prints the contents of the vector to the terminal window, returns void
void print_list(const std::vector<std::string>& list_of_strings);

// input functions

// precondition: Function parameter takes in two valid ints and passes them as const reference
// postcondition: Returns the user's choice within the bounds given in the function parameters
//               If user inputs int out of range, reprompts user for input within range
int get_number_from_user(int smallest_possible_choice, int largest_possible_choice);

// precondition: No inputs for function parameters
// postcondition: Returns a valid string from user
// Warning this will allow for any non-empty string to be grabbed from the user hence unrestricted
std::string getline_from_user_unrestricted();

// precondition: Function requires two valid positive integers to be passed into function.
// postcondition: Returns a valid string from user that is between the specified length.
std::string getline_from_user_restricted(unsigned int min_length, unsigned int max_length);

// precondition: No inputs for function parameters
// postcondition: Returns true for yes and false for no
bool get_y_or_n_as_bool();

// cross-platform naive approach - basically printing 100 newline characters to the screen
// probably shouldn't use, left here to laugh at for the future
void clear_screen();

#endif