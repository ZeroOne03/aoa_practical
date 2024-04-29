/*
 NAME: Shaikh Zaid Muddaris Husain
 ROLL NO: 23dco06
 CLASS: SECO
 BATCH:03
             EXP 6
AIM:IMPLEMENTION AND ANALYSIS OF N QUEEN PROBLEM.

THEORY:In N-Queen problem, we are given an NxN chessboard and we have to place N number of queens on the board in such a way that no two queens attack each other. A queen will attack another queen if it is placed in horizontal, vertical or diagonal points in its way. The most popular approach for solving the N Queen puzzle is Backtracking.

ALGORITHM:
Step 1 -Place the first queen in the top-left cell of the chessboard.
Step 2 -After placing a queen in the first cell, mark the position as a part of the solution and then recursively check if this will lead to a solution.
Step 3 -Now, if placing the queen doesn’t lead to a solution. Then go to the first step and place queens in other cells. Repeat until all cells are tried.
Step 4 -If placing queen returns a lead to solution return TRUE.
Step 5 -If all queens are placed return TRUE.
Step 6 -If all rows are tried and no solution is found, return FALSE.

CODE:*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a[30], count = 0;
int place(int pos) // for finding the right position
{
    for (int i = 1; i < pos; i++)
    {
        if ((a[i] == a[pos]) || ((abs(a[i] - a[pos]) == abs(i - pos))))
            return 0;
    }
    return 1;
}

void print_sol(int n) // for printing the solution
{
    count++;

    printf("\n\nSolution #%d:\n", count);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == j)
                printf("Q\t");
            else
                printf("*\t");
        }
        printf("\n");
    }
}

void queen(int n) // N - queen problem algorithm
{
    int k = 1;
    a[k] = 0;

    while (k != 0)
    {
        a[k] = a[k] + 1;
        while ((a[k] <= n) && !place(k))
            a[k]++;
        if (a[k] <= n)
        {
            if (k == n)
                print_sol(n);
            else
            {
                k++;
                a[k] = 0;
            }
        }
        else
            k--;
    }
}

int main()
{
    int i, n;
    printf("\nEnter the number of Queens:: ");
    scanf("%d", &n);
    queen(n);
    printf("\nTotal Solutions = %d", count);
    return 0;
}
/*
OUTPUT:
$ ./ex_07.exe

Enter the number of Queens:: 4


Solution #1:
*       Q       *       *
*       *       *       Q
Q       *       *       *
*       *       Q       *


Solution #2:
*       *       Q       *
Q       *       *       *
*       *       *       Q
*       Q       *       *

Total Solutions = 2s
*/