
/*
    EXP 7 AIM : IMPLEMENTION AND ANALYSIS OF WARSHALL ALGORITHM

                    THEORY :
                    */
/*
The Floyd-Warshall algorithm is a dynamic programming-based approach used to find the shortest paths between all pairs of vertices in a weighted graph,
including negative edge weights (but no negative cycles). It is an efficient method that works for both directed and undirected graphs.
*/

/*ALGORITHM:-
Initialization: Initialize a distance matrix D of size n x n, where n is the number of vertices in the graph. For each pair of vertices (i, j), D[i][j] is the shortest known distance between vertices i and j.

If there is an edge between vertices i and j, set D[i][j] to the weight of the edge.
If there is no edge between vertices i and j, set D[i][j] to infinity (or a large value representing "no path").
Main Algorithm:

Iterate over all vertices k from 1 to n. This vertex represents a potential intermediate vertex through which we consider paths between pairs of vertices.

For each pair of vertices (i, j):

If vertex k is on the shortest path from i to j, update D[i][j] to the minimum of:
The current value of D[i][j].
The sum of the distances from i to k and from k to j.
Mathematically, this can be expressed as: D[i][j] = min(D[i][j], D[i][k] + D[k][j]).

Termination:
After completing the main algorithm, the D matrix will contain the shortest distances between all pairs of vertices.
Output:
The D matrix represents the shortest path distances between all pairs of vertices. Each element D[i][j] contains the shortest distance from vertex i to vertex j.
*/

/* ********** CODE ********** */

#include <stdio.h>

#define nV 4
#define INF 999

void printMatrix(int matrix[][nV]);
void floydWarshall(int graph[][nV]);

int main()
{
    int graph[nV][nV];

    printf("Enter the adjacency matrix for the graph (%d x %d):\n", nV, nV);
    for (int i = 0; i < nV; i++)
        for (int j = 0; j < nV; j++)
            scanf("%d", &graph[i][j]);

    floydWarshall(graph);

    return 0;
}

void printMatrix(int matrix[][nV])
{
    printf("The shortest path distance between every pair of vertices is : \n");
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][nV])
{
    int matrix[nV][nV];

    for (int i = 0; i < nV; i++)
        for (int j = 0; j < nV; j++)
            matrix[i][j] = graph[i][j];

    for (int k = 0; k < nV; k++)
    {
        for (int i = 0; i < nV; i++)
        {
            for (int j = 0; j < nV; j++)
            {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    printMatrix(matrix);
}

/**Output:
Enter the adjacency matrix for the graph (4 x 4):
4
5
8
7
10
5
6
9
3
4
8
7
58
47
4
-5
The shortest path distance between every pair of vertices is :
   4   5   8   2
   9   5   6   4
   3   4   8   2
   2   3  -1 -10
**/

/*
Analysis :-
The time complexity of the Floyd-Warshall algorithm is O(n^3), where n is the number of vertices in the graph.
This makes it suitable for small to medium-sized graphs but may become inefficient for very large graphs due to its cubic time complexity.
However, it is particularly useful when we need to find shortest paths between all pairs of vertices in a graph.
*/
