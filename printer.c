#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_print_grid(int **grid, int n)
{
	int	row;
	int	col;

	row = -1;
	while (++row <= n)
	{
		col = -1;
		while (++col < n - 1)
		{
			ft_putchar(grid[row][col] + '0');
			ft_putchar(' ');
		}
		ft_putchar(grid[row][col] + '0');
		ft_putchar('\n');
	}
}
