/*

EXP 8 AIM : IMPLEMENTION AND ANALYSIS OF SUM OF SUBSET PROBLEM USING BACKTRACKING

                THEORY :


The Subset Sum Problem is a classic problem in computer science that asks whether there exists a subset of a given set of integers whose sum is equal to a given target sum. It is a decision problem and can be solved using various approaches, including backtracking.

1. Backtracking Approach:
Backtracking is a general algorithmic technique that incrementally builds solutions by exploring all possible choices and "backtracks" when it encounters a dead-end. It is a systematic way of searching for solutions to optimization problems, such as the Subset Sum Problem.

2. Basic Idea:
The basic idea behind solving the Subset Sum Problem using backtracking is to recursively explore all possible subsets of the given set. At each step of the recursion, we have two choices for each element of the set: either include it in the current subset or exclude it.

3. Recursive Function:
The backtracking algorithm is implemented using a recursive function. This function explores all possible combinations of elements by making decisions at each step of the recursion.

4. Parameters of the Recursive Function:
set[]: The original set of integers.
n: The total number of elements in the set.
sum: The target sum we want to achieve.
currentSum: The current sum of elements in the subset being explored.
index: The index of the current element being considered from the set.

5. Base Cases:
If currentSum equals the target sum, it means we have found a subset with the desired sum, so we output it.
If we have processed all elements of the set (index >= n), we stop the exploration of the current path and backtrack.

6. Recursive Steps:
Include the current element in the subset and recursively explore further (findSubset(set, n, sum, currentSum + set[index], index + 1)).
Exclude the current element from the subset and recursively explore further (findSubset(set, n, sum, currentSum, index + 1)).

7. Backtracking:
If neither of the above cases is true, it means that we need to explore both possibilities (include and exclude) for the current element. After exploring both possibilities, we backtrack to the previous state and try another path.
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Global array to store the subset
int subset[MAX];

// Function to print the subset
void printSubset(int subset[], int subsetSize)
{
    for (int i = 0; i < subsetSize; i++)
        printf("%d ", subset[i]);
    printf("\n");
}

// Function to find all possible subsets with the given sum
void findSubsets(int set[], int n, int sum, int subsetSize, int total, int index)
{
    // If the subset has the desired sum, print it
    if (total == sum)
    {
        printSubset(subset, subsetSize);
        return;
    }

    // If we have processed all elements or sum becomes negative, backtrack
    if (index >= n || total > sum)
        return;

    // Include the current element and backtrack
    subset[subsetSize] = set[index];
    findSubsets(set, n, sum, subsetSize + 1, total + set[index], index + 1);

    // Exclude the current element and backtrack
    findSubsets(set, n, sum, subsetSize, total, index + 1);
}

int main()
{
    int set[MAX];
    int n, sum;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &sum);

    printf("Solution sets:\n");
    findSubsets(set, n, sum, 0, 0, 0);

    return 0;
}

/*
OUTPUT:
Enter the number of elements in the set: 4
Enter the elements of the set:
1 2 3 4
Enter the target sum: 5
Solution sets:
1 4
2 3

*/

/*
Complexity Analysis:
Time Complexity: The time complexity of the algorithm is exponential, O(2^n), where n is the number of elements in the set.
This is because there are 2^n possible subsets, and the algorithm explores each subset.
Space Complexity: The space complexity is O(n), where n is the number of elements in the set.
This is due to the recursion stack used by the recursive function.
*/
