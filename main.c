#include "brute_force.h"
#include "get_size.h"
#include "input_validation.h"
#include "optimise.h"
#include "printer.h"
#include "setup.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int **grid;
	int n;
	int i;
	// check if input format is correct
	if (!check_correct_argc(argc) || !check_correct_value(argv[1]))
		return (0);

	// generate the grid
	grid = generate_grid(ft_input_parse(argv[1]));
	// get size of grid
	n = get_size(grid);
	// solve for spots that are definite first (optimization)
	solve_known_ans(grid);
	// brute forcing
	ft_solve(grid, n);

	// check if the combination is possible

	//printing
	ft_print_grid(grid, n);

	//free memory
	i = -1;
	while (++i < n + 2)
		free(grid[i]);
	free(grid);
	return (0);
}