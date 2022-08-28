int	get_size(int **grid)
{
	int i;

	i = 1;
	while (grid[0][i] != 0)
		i++;
	return (i - 1);
}