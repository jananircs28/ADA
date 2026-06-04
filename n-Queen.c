#include <stdio.h>
#include <stdlib.h>

int board[20], n;

int isSafe(int row, int col)
{
    int i;

    for (i = 0; i < row; i++)
    {
        if (board[i] == col ||
            abs(board[i] - col) == abs(i - row))
            return 0;
    }

    return 1;
}

void printSoln()
{
    int i, j;

    printf("\nSolution:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void solveQueen(int row)
{
    int col;

    if (row == n)
    {
        printSoln();
        return;
    }

    for (col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row] = col;      // Place queen
            solveQueen(row + 1);   // Recur for next row
        }
    }
}

int main()
{
    printf("Enter N: ");
    scanf("%d", &n);

    solveQueen(0);

    return 0;
}
