/*
						   EXP 9
AIM : IMPLEMENTION AND ANALYSIS OF N-QUEEN PROBLEM

THEORY :

The N-Queens problem is a classic problem in computer science and combinatorial optimization. In the N-Queens problem,
the task is to place N chess queens on an N×N chessboard in such a way that no two queens threaten each other.
Specifically, no two queens should share the same row, column, or diagonal.

Here's a brief overview of the problem:

Objective: Place N queens on an N×N chessboard so that no two queens attack each other.

Constraints:
Each row can contain only one queen.
Each column can contain only one queen.
No two queens should share the same diagonal.
Solution: Finding a placement of queens that satisfies the constraints mentioned above.

Approaches:
Backtracking: A common approach to solving the N-Queens problem is by using backtracking.
This involves recursively exploring all possible configurations of queens on the chessboard and backtracking when a configuration is found to violate the constraints.
Constraint Satisfaction: The problem can also be approached as a constraint satisfaction problem,
where the goal is to find values for variables (the positions of queens) that satisfy a set of constraints (no two queens attack each other).

Optimization Techniques: Various optimization techniques, such as pruning search space or symmetry breaking, can be employed to improve the efficiency of the solution search.
Applications: The N-Queens problem has applications in various domains, including artificial intelligence, constraint programming,
combinatorial optimization, and recreational mathematics.
It serves as a benchmark problem for evaluating algorithms and techniques for constraint satisfaction and combinatorial optimization.
*/

/******************* CODE ******************/
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
Enter the number of Queens:: 4


Solution #1:
*	Q	*	*
*	*	*	Q
Q	*	*	*
*	*	Q	*

Solution #2:
*	*	Q	*
Q	*	*	*
*	*	*	Q
*	Q	*	*

Total Solutions = 2
*/

/*
ANALYSIS:
Time Complexity: The time complexity of the backtracking algorithm for the N-Queens problem is exponential, O(2^N).
This is because each queen can be placed in N different positions on the board, resulting in a total of N^N possible configurations.
However, due to backtracking, the actual number of explored configurations is typically much lower.

Space Complexity: The space complexity depends on the implementation but is usually O(N^2) to represent the chessboard.
*/