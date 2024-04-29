
/*



							 EXP 2

AIM : IMPLEMENTATION AND ANALYSIS OF SELECTION SORT
*/

/*
THEORY:

	Selection sort is an in-place comparison-based sorting algorithm.
	It divides the input list into two parts: the sorted sublist and
	the unsorted sublist.

	The algorithm repeatedly selects the smallest (or largest) element
	from the unsorted sublist and swaps it with the first unsorted element.
	This process is repeated until the entire list is sorted.

	The time complexity of the selection sort algorithm is O(n2)O(n^2)O(n2),
	and its space complexity is O(1)O(1)O(1) as it doesn't take any extra
	space.

*/

/* ********** CODE ********** */

#include <stdio.h>

// Display function

int i, min;
void display(int a[], int n)
{

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
// Swap Function

void swap(int i, int min, int a[])
{
	int temp = a[i];
	a[i] = a[min];
	a[min] = temp;
}
// Function to sort an array using selection sort

void selectionSort(int a[], int n)
{

	for (int i = 0; i < n - 1; i++)
	{

		int min = i;

		for (int j = i + 1; j < n; j++)
		{

			if (a[j] < a[min])
			{
				min = j;
			}
		}

		if (min != i)
		{

			swap(i, min, a);
		}
	}
}
// Accept the values from user and print before and after sort array

int main()
{

	int array[100], n;
	printf("Enter number of elements:");
	scanf("%d", &n);

	printf("Enter the values:");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}

	printf("Elements before sorting:");
	display(array, n);

	printf("Elements after sorting:");
	selectionSort(array, n);
	display(array, n);
}

/* OUTPUT :

Enter number of elements:5
Enter the values:8
7
6
5
4
Elements before sorting:8 7 6 5 4
Elements after sorting:4 5 6 7 8

*/

/*
ANALYSIS:

	Selection sort is a simple and efficient sorting algorithm that
	works by repeatedly selecting the smallest (or largest) element
	from the unsorted portion of the array and swapping it with the
	first (or last) element in the sorted portion.

	The algorithm has the following time and space complexity:

	Time Complexity:

	Best-case: O(n^2), when the array is already sorted

	Average-case: O(n^2), when the elements of the array are in a
	disordered or random order, without a clear ascending or descending

	Worst-case: O(n^2), when the array is initially in descending order


	The time complexity of selection sort can be analyzed as follows:

	The outer loop iterates n - 1 times, as it selects the smallest
	element from the unsorted portion of the array

	The inner loop iterates n - i times, as it compares the current
	element with the remaining unsorted elements

	The total number of comparisons is approximately equal to n^24


	Space Complexity:

	Selection sort is an in-place algorithm, meaning it performs all
	computations in the original array and does not use any extra memory

	The space complexity is O(1)


	In summary, selection sort is a simple and efficient sorting
	algorithm with a time complexity of O(n^2) and a space complexity
	of O(1)
*/
