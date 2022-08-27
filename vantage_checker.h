#include <stdbool.h>

#ifndef VANTAGE_CHECKER_H
# define VANTAGE_CHECKER_H

bool	ft_vantage_checker(int **grid, int col, int row);
bool	ft_vantage_checker_left(int **grid, int row);
bool	ft_vantage_checker_right(int **grid, int row);
bool	ft_vantage_checker_top(int **grid, int col);
bool	ft_vantage_checker_bottom(int **grid, int col);

#endif