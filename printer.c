#include <get_size.h>
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

void	ft_print_grid(int **grid)
{
	int	n;
	int	row;
	int	col;

	n = get_size(grid);
	row = 0;
	while (++row <= n)
	{
		col = 0;
		while (++col < n)
		{
			ft_putchar(grid[row][col] + 48);
			ft_putchar(' ');
		}
		ft_putchar(grid[row][col] + 48);
		ft_putchar('\n');
	}
}

void	ft_errormsg(void)
{
	ft_putstr("ERROR\n");
}
