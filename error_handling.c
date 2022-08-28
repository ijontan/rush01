#include <stdbool.h>

//check if any int slot in nxn is null/0
bool	ft_is_0(int **grid, int n)
{
	int	i;
	int	j;

	i = 0;
	while (++i < n + 1)
	{
		j = 0;
		while (++j < n + 1)
			if (grid[i][j] == 0)
				return (true);
	}
	return (false);
}

//{
//	row = 1;
//	col = 1;
//
//        while ((row > 0 && row < 5) && (col > 0 && col < 5))
//        {
//            if (grid[col][row++] == 0)
//                return(true);
//            col++;
//            row = 1;
//        }
//}

// //check if combination where clue 4 is not adjacent to 1,
// or if clue 1 is not adjacent to 4 (or any invalid combinations)
// bool	ft_combination(int **grid)
// {
// 	//if (grid[0][1] == 4)
// 	//	grid[1][1] = 1;
// 	//else if (grid[0][1] == 1)
// 	//	grid[1][1] = 4;
// 	if ((grid[0][i++] == 1) && (grid[5][i++] == 1))
// 		return (true);
// 	else if ((grid[i++][0] == 1) && (grid[i++][5] == 1))
// 		return (true);
// 	else if ((grid[0][i++] == 3) && (grid[5][i++] == 3))
// 		return (true);
// 	else if ((grid[i++][0] == 3) && (grid[i++][5] == 3))
// 		return (true);
// 	else if ((grid[0][i++] == 4) && (grid[5][i++] == 4))
// 		return (true);
// 	else if ((grid[i++][0] == 4) && (grid[i++][5] == 4))
// 		return (true);
// 	else
// 		return (false);
// 	//{
// 	//	return (true);
// 	//	ft_putchar(ft_errormsg);
// 	//}
// }