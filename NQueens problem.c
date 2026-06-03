#include <stdio.h>
#include <stdlib.h>

int board[20], n;
int count = 0;

int place(int row, int col)
{
    for(int i = 1; i < row; i++)
    {
        if(board[i] == col ||
           abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void nQueens(int row)
{
    for(int col = 1; col <= n; col++)
    {
        if(place(row, col))
        {
            board[row] = col;

            if(row == n)
            {
                count++;

                printf("\nSolution %d:\n", count);

                for(int i = 1; i <= n; i++)
                {
                    for(int j = 1; j <= n; j++)
                    {
                        if(board[i] == j)
                            printf("Q ");
                        else
                            printf(". ");
                    }
                    printf("\n");
                }
            }
            else
            {
                nQueens(row + 1);
            }
        }
    }
}

int main()
{
    printf("Enter number of queens: ");
    scanf("%d", &n);

    nQueens(1);

    printf("\nTotal number of solutions = %d\n", count);

    return 0;
}
