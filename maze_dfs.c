#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100 // Maximum maze size

// Global direction arrays
int dx[4], dy[4];

char maze[MAX][MAX];
bool visited[MAX][MAX];
int rows, cols;
int startX, startY, endX, endY;
bool found = false;

// Function to find start and end points
void findStartEnd()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (maze[i][j] == 'S')
            {
                startX = i;
                startY = j;
            }
            else if (maze[i][j] == 'E')
            {
                endX = i;
                endY = j;
            }
        }
    }
}
void setDirectionOrder()
{
    char order[5]; // 4 characters + null terminator
    printf("Enter order of directions (e.g., LRUD for Left, Right, Up, Down): ");
    scanf("%4s", order); // Read up to 4 characters

    if (strlen(order) != 4)
    {
        printf("Please enter exactly 4 characters (L, R, U, D).\n");
        exit(1);
    }

    for (int i = 0; i < 4; i++)
    {
        char d = order[i];
        if (d == 'L' || d == 'l')
        {
            dx[i] = 0;  // Row change: none
            dy[i] = -1; // Column change: left
        }
        else if (d == 'R' || d == 'r')
        {
            dx[i] = 0;
            dy[i] = 1;
        }
        else if (d == 'U' || d == 'u')
        {
            dx[i] = -1; // Row change: up
            dy[i] = 0;
        }
        else if (d == 'D' || d == 'd')
        {
            dx[i] = 1; // Row change: down
            dy[i] = 0;
        }
        else
        {
            printf("Invalid direction character: %c\n", d);
            exit(1);
        }
    }
}

// DFS Function (Recursive)
bool dfs(int x, int y)
{
    // If out of bounds or at a wall or already visited, return false
    if (x < 0 || y < 0 || x >= rows || y >= cols || maze[x][y] == '1' || visited[x][y])
        return false;

    // Mark as visited
    visited[x][y] = true;

    // If we reached the end, return true
    if (x == endX && y == endY)
    {
        return true;
    }

    // Recursively explore all four directions
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (dfs(newX, newY))
        {
            maze[x][y] = '*'; // Mark the correct path
            return true;
        }
    }

    return false; // If no path found
}

// Function to solve the maze using DFS
void solveWithDFS()
{
    setDirectionOrder();
    // Initialize visited array
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            visited[i][j] = false;

    found = dfs(startX, startY);

    if (found)
    {
        printf("\nSolved Maze using DFS:\n");
        maze[startX][startY] = 'S'; // Restore start position
        maze[endX][endY] = 'E';     // Restore end position
        // output function
    }
    else
    {
        printf("\nNo solution exists.\n");
    }
}

int main()
{
    // input function
    findStartEnd();

    printf("\nSolving maze using DFS...\n");
    solveWithDFS();

    return 0;
}
