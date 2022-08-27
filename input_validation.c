
#include "input_validation.h"
#include <stdbool.h>

/*
this function checks if the number of arguments are not one
e.g, running the program with more, or less than 1 arguments 
is not allowed.
*/
bool	check_correct_argc(int argc)
{
	if (argc == 2)
		return (true);
	return (false);
}

/*
this function checks the pattern of the arguments passed into the program.
the inputs must all be numbers and separated by space (and only space)
this doesn't work with anything else.
this function also checks the total length of the arguments passed.
*/
bool	check_correct_value(char *src)
{
	int	i = 0;

	while (src[i])
	{
		// checks if the even arguments are spaces or not, only spaces allowed
		// as argument delimiters
		if (i % 2 == 1 && src[i] != 32)
			return (false);
		// checks if the odd arguments are valide character numbers, only valid 
		// character numbers are allowed
		if (i % 2 == 0 && (src[i] < 49 || src[i] > 52))
			return (false);
		i++;
	}
	// checks if the total count of arguments (spaces and numbers) is not equal
	// to 32, (16(numbers) + 16(spaces) = 32)
	if (i == 31)
		return (true);
	return (false);
}
