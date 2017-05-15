#include <random>
#include "random.h"

int random_int(int smallest_number, int largest_number)
{
	int random_number = -1;
	
	std::mt19937 gen(std::random_device{}());
	std::uniform_int_distribution<> dist(smallest_number, largest_number);
	random_number = dist(gen); 
	
	return random_number;
}

bool random_fifty_fifty()
{
	int random_number = -1;
	bool result = false;
	
	random_number = random_int(1, 2);
	
	if(random_number == 1)
	{
		result = true;
	}
	else if(random_number == 2)
	{
		result = false;
	}
	
	return result;
}

int roll_d_four()
{
	return random_int(1, 4);
}

int roll_d_twenty()
{
	return random_int(1, 20);
}