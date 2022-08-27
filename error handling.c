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
		i = 0;
		while (col > 0 && col < 5)
		{
    		if (grid[i++][col] == 0)
				return (true);
        	col++;
    	}
		row++;
	}
	return (false);
}

//{
//        while ((row > 0 && row < 5) && (col > 0 && col < 5))
//        {
//            if (grid[col][row++] == 0)    
//                return(true);
//            col++;
//            row = 1;
//        }
//}









//check if combination where clue 4 is not adjacent to 1, or if clue 1 is not adjacent to 4 (or any invalid combinations)
bool	ft_combination(int **grid)
{
	if (grid[0][1] == 4)
		grid[1][1] = 1;
	else if (grid[0][1] == 1)
		grid[1][]
}