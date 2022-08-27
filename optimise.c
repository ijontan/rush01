

#include "config.h"

void solve_known_ans(int **grid)
{
    int col;
    int row;
    col= 0;
    while (col <= N)
    {
        row = 0;
        if (grid[0][col] == N)
        {
            while (++row <= N)
                grid[row][col] = j;
        }
        if (grid[0][col]==1)
            grid[1][col]=N;
        if (grid[0][col]+grid[N+1][col]==N+1)
            grid[grid[0][col]][col]=N;
    }
}