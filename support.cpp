/*  Copyright 2016 George Le
    This file provides definitions to the generic supporting functions 
    declared in support.h, see header file for details
*/

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <sstream>
#include "support.h"

void read_files(const std::string& file_name)
{
    using std::string;
    using std::ifstream;
    using std::cout;
    using std::endl;
    // 
    string line = " ";
    ifstream file(file_name);
    
    if(file.is_open())
    {
        while(getline(file, line))
        {
            cout << line << endl;
        }
    }
    else
    {
        cout << "Unable to open file. Make sure " << file_name << " is in directory!" << endl;
        exit(1);
    }
    
    file.close();
}

int get_number_from_user(int smallest_possible_choice, int largest_possible_choice)
{
    using std::cin;
    using std::cout;
    using std::numeric_limits;
    using std::streamsize;
    using std::string;
    
    int user_choice = 0; 
    
    cin >> user_choice;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    while((user_choice < smallest_possible_choice) || (user_choice > largest_possible_choice))
    {
        cout << "That's not a valid choice! Select a number from " << smallest_possible_choice;
        cout << " to " << largest_possible_choice << "!";
        
        cin >> user_choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    return user_choice;
}

std::string getline_from_user_unrestricted()
{
    using std::cin;
    using std::cout;
    using std::numeric_limits;
    using std::streamsize;
    using std::string;
    
    string user_input = "";
    
    cin >> user_input;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    while(user_input.compare("") == 0)
    {
        cout << "Please input a selection, or ... for silence.\nInput:";
        cin >> user_input;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    return user_input;
}

std::string getline_from_user_restricted(unsigned int min_length, unsigned int max_length)
{
    using std::cin;
    using std::cout;
    using std::numeric_limits;
    using std::streamsize;
    using std::string;
    
    string user_input = "";
    
    cin >> user_input;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    while(user_input.compare("") == 0 && ((user_input.size() < min_length) || (user_input.size() > max_length)))
    {
        cout << "Please input a selection, or ... for silence.\n";
        cout << "Your input has to be at least " << min_length << "and ";
        cout << max_length << " character(s) long.\n" << "New input:";
        cin >> user_input;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    return user_input;
}

bool get_y_or_n_as_bool()
{
    using std::cout;
    using std::cin;
    using std::numeric_limits;
    using std::streamsize;
    using std::string;
    
    char answer = ' '; // declaring a default character answer
    string line = " "; // declaring a default std::string line
	bool player_answer = false; // default answer is a NO 

    getline(cin , line);
    if(line.length() == 1)
    {
        answer = line[0];
    }

	while ((answer != 'y') && (answer != 'Y') && (answer != 'n') && (answer != 'N'))
	{
		cout << "Invalid answer. Please input a valid selection, (y/n)\nInput:";
        getline(cin, line);
        if(line.length() == 1)
        {
            answer = line[0];
        }
	}

	if ((answer == 'Y') || (answer == 'y'))
	{
		player_answer = true;
	}
	else if((answer == 'N') || (answer == 'n'))
    {
        player_answer = false;
    }

	return player_answer;
}

void clear_screen()
{
    using std::cout;
    using std::string;
    
    //prints out a string that is 100 newline characters
    cout << string(100, '\n');
}