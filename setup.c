#include <stdlib.h>

//parses the 1 dimensional input argument,
// and fills it into a 1 dimensional array.
int	*ft_input_parse(char *str)
{
	int	*dest;
	int	i;
	int	j;

	// allocate memory for the argument array
	dest = (int *)malloc(sizeof(int) * 16);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= 49 && str[i] <= 52)
		{
			// if the value is within 1 ~ 4, convert char back to int
			dest[j] = str[i] - 48;
			j++;
		}
		i++;
	}
	return (dest);
}

// generate a grid of (N+2)*(N+2) (for now is 6) the extra two is for saving the clues in the grid
// *src is the array containing the parsed argv[1]
int	**generate_grid(int *src)
{
	int	**grid;
	int	i;
	int	j;

	// i to iterate horizontally through *src (AKA clues)
	// j to move array to next index (inside 2d grid)
	i = -1;
	// create a int array with 6 slots of size integer
	grid = (int **)malloc(6 * sizeof(int *));
	// for each previously created slot,
	//make another int array with 6 slots of size integer inside
	while (++i < 6)
		grid[i] = (int *)malloc(6 * sizeof(int));
	grid[0][0] = 1;
	grid[0][5] = 1;
	i = 0;
	j = 1;
	while (i < 4)
		// access first row, second col then assign clue to the slot
		grid[0][j++] = src[i++];
	j = 1;
	while (i < 8)
		// access last row, second col
		grid[5][j++] = src[i++];
	j = 1;
	while (i < 12)
		// access first col, second row
		grid[j++][0] = src[i++];
	j = 1;
	while (i < 16)
		// access last col, second row
		grid[j++][5] = src[i++];
	return (grid);
}
