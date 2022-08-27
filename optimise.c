

#include "config.h"

void solve_known_ans(int **grid)
{
    solve_top_row(int **grid)
    solve_bottom_row(int **grid)
    solve_left_row(int **grid)
    solve_right_row(int **grid)
    
}

void solve_top_row(int **grid)
{
    int col;
    int row;
    col= 0;
    while (++col <= N)
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

void solve_bottom_row(int **grid)
{
    int col;
    int row;
    col= 0;
    while (++col <= N)
    {
        row = N+1;
        if (grid[N+1][col] == N)
        {
            while (--row <= N)
                grid[row][col] = j;
        }
        if (grid[N+1][col]==1)
            grid[N][col]=N;
       
    }
}
void solve_left_row(int **grid)
{
    int col;
    int row;
    row= 0;
    while (++row <= N)
    {
        col = N+1;
        if (grid[row][0] == N)
        {
            while (--col <= N)
                grid[row][col] = j;
        }
        if (grid[row][0]==1)
            grid[row][1]=N;
        if (grid[row][0]+grid[row][N+1]==N+1)
            grid[row][grid[row][0]]=N;
    }
}
void solve_right_row(int **grid)
{
    int col;
    int row;
    row= 0;
    while (++row <= N)
    {
        col = N+1;
        if (grid[row][N+1] == N)
        {
            while (--col <= N)
                grid[row][col] = j;
        }
        if (grid[row][N+1]==1)
            grid[row][N]=N;
      
    }
}
