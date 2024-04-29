
/*



                             EXP 1

AIM : IMPLEMENTATION AND ANALYSIS OF INSERTION SORT
*/

/*
THEORY:

    Insertion sort is a simple and efficient algorithm for sorting elem
    ents in ascending or descending order. It works by dividing the input
    array into a sorted and an unsorted part, and then it iterates thro-
    ugh the unsorted part, picking one element at a time and inserting
    it into its correct position in the sorted part.

    Here is a basic theory for the insertion sort algorithm in C:

    Algorithmic Paradigm:-
    The Insertion Sort algorithm follows an incremental approach1

    In-Place and Stability:-

    In-Place: Insertion sort is an in-place sorting algorithm, meaning
    it does not require any additional storage space other than the ori-
    ginal array1

    Stable: It is a stable sorting algorithm, maintaining the relative
    order of equal elements in the sorted output1


    When to Use:
    Insertion sort is used when the number of elements is small or when
    the input array is almost sorted1

*/

/* ********** CODE ********** */

#include <stdio.h>

// Function to print elements in array

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Function to sort an array using insertion sort

void insert_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (temp < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
    }
}
// Accept the values from user and print before and after sort array

int main()
{
    int array[100], n, i;
    printf("Enter number of element you want to insert:");
    scanf("%d", &n);
    printf("Enter %d number:", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("before Sort:\n");
    display(array, n);
    insert_sort(array, n);
    printf("After Sort:\n");
    display(array, n);
}

/* OUTPUT :

Enter number of element you want to insert:3
Enter 3 number:
44
4
545
before Sort:
44 4 545
After Sort:
4 44 545

*/

/*
ANALYSIS :

    Insertion sort is a simple and efficient algorithm for sorting
    elements. It has a time complexity of O(n^2) in the worst case,
    but O(n) in the best case. The algorithm is in-place and stable,
    making it suitable for small input sizes and partially sorted
    arrays. While not the most efficient for large data sets, it
    is easy to implement and understand, often used as a building
    block for more complex sorting algorithms.
*/
