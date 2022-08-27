#include "config.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_print_grid(int **grid)
{
	int row = 0;

	while (++row <= N)
	{
		int col = 0;
		while (++col < N)
		{
			ft_putchar(grid[row][col]+48);
			ft_putchar(' ');
		}
		while (++col = N)
		{
			ft_putchar(grid[row][col]+48);
		}
		ft_putchar('\n');
	}
}

void	ft_errormsg(void)
{
	ft_putstr("ERROR\n");
}
