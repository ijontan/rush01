#include "brute_force.h"
#include "config.h"
#include "input_validation.h"
#include "printer.h"
#include "setup.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int **grid;
	// check if input format is correct
	if (!check_correct_argc(argc) || !check_correct_value(argv[1]))
		return (0);

	// generate the grid
	grid = generate_grid(ft_input_parse(argv[1]));

	// solve for spots that are definite first (optimization)

	// brute forcing
	ft_solve(grid);

	// check if the combination is possible

	//printing
	ft_print_grid(grid);

	//free memory
	free(grid);

	return (0);
}