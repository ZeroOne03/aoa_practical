/*

             EXP 3
AIM:IMPLEMENTION AND ANALYSIS OF MERGE FUNCTION

THEORY:Merge sort is defined as a sorting algorithm that works by dividing an array into smaller subarrays,
 sorting each subarray,and then merging the sorted subarrays back together to form the final sorted array.

ALGORITHM:
1.Merge sort(arr,beg,end)
2.if beg<end
3.set mid = beg+end/2.
4.merge sort(arr,beg,end)
5.merge sort(arr,mid+1,end)
6.merge sort(arr,mid,end)
7.enf of if


CODE:*/
#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[100];

    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
    }

    for (k = lb; k <= ub; k++)
    {
        arr[k] = b[k];
    }
}

void merge_sort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = lb + (ub - lb) / 2;
        merge_sort(arr, lb, mid);
        merge_sort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main()
{
    int array[100], n, i;
    printf("Enter number of Elements: ");
    scanf("%d", &n);
    printf("Enter %d Numbers: ", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Elements before sorting: \n");
    display(array, n);

    merge_sort(array, 0, n - 1);

    printf("Elements after sorting:\n");
    display(array, n);

    return 0;
}

/*
OUTPUT:Enter number of Elements: 5
Enter 5 Numbers: 109 41 56 78 15
Elements before sorting:
109 41 	56 	78 	15
Elements after sorting:
15 	41 	56 	78 	109

ANALYSIS:
    Merge Sort allows the user to input the number of elements in the array and the elements themselves.
   It then sorts the array using the Merge Sort algorithm and prints the sorted array.
  This code demonstrates the basic implementation of Merge Sort and how user input can be incorporated into the sorting process.
  The Merge Sort algorithm has a time complexity of O(n log n), making it an efficient algorithm for sorting large data sets.
  By allowing user input, the code provides flexibility in sorting different arrays based on user-defined elements,
  showcasing its practical applicability. Overall, the code exemplifies the fundamental concepts of user input, array manipulation,
 and sorting algorithms.

 */
