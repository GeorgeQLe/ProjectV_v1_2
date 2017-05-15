#ifndef SUPPORT_H
#define SUPPORT_H
#include <string>

// precondition: Function parameter takes in a name of file and passes it as a const reference
// postcondition: Returns void and upon successful opening of the file, reads and write to the 
//				 screen the contents of the file. Upon failure of opening the file, execute exit
void read_files(const std::string& file_name);

// precondition: Function parameter takes in two valid ints and passes them as const reference
// postcondition: Returns the user's choice within the bounds given in the function parameters
//               If user inputs int out of range, reprompts user for input within range
int get_number_from_user(int smallest_possible_choice, int largest_possible_choice);

// precondition: No inputs for function parameters
// postcondition: Returns a valid string from user
// Warning this will allow for any non-empty string to be grabbed from the user
std::string get_line_from_user();

// precondition: No inputs for function parameters
// postcondition: Returns true for yes and false for no
bool get_y_or_n_as_bool();

// cross-platform naive approach - basically printing 100 newline characters to the screen
void clear_screen();

#endif