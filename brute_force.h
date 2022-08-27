#include <stdbool.h>
#ifndef BRUTE_FORCE_H
# define BRUTE_FORCE_H

bool    ft_is_possible(int **grid,	int col, int row, int value);
void	ft_solve(int **grid, int col, int row);

#endif