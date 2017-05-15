/*  George Le
    Various random number generators and dice roll simulators. Most have return values of either ints or bools
    The use of these functions require at least c++11
    2016-Still being updated
*/

#ifndef RANDOM_H
#define RANDOM_H

//precondition: Function parameter takes in two valid ints and passes them as const reference
//postcondition: Returns a random number within the bounds given in the function parameters
int random_int(int smallest_number, int largest_number);

//precondition: None
//postcondition: Returns true on a roll of 1 and false on a roll of 2
bool random_fifty_fifty();

//precondition: None
//postcondition: Return a random number within 1 and 4
int roll_d_four();

//precondition: None
//postcondition: Returns a random number within 1 and 20
//used for gambler class in Diadal
int roll_d_twenty();

#endif //RANDOM_H