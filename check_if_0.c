#include <stdbool.h>

//check if any int slot in 4x4 is null/0
bool	ft_is_0(int **grid, int col, int row)
{
	int	i;

	i = 0;
	while (row > 0 && row < 5)
	{
		if (grid[row][i++] == 0)
			return (true);
		row++;
	}
    i = 0;
	while (col > 0 && col <5)
	{
        if (grid[i++][col] == 0)
            return (true);
        col++;
    }
	return (false);
}