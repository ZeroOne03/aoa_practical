/*

             EXP 5
AIM:IMPLEMENTION AND ANALYSIS OF BINARY SEARCH ALGORITHM.

THEORY:Binary Search algorithm is an interval searching method that performs the searching in intervals only. The input taken by the binary search algorithm must always be in a sorted array since it divides the array into subarrays based on the greater or lower values. The algorithm follows the procedure below −

ALGORITHM:
Step 1 − Select the middle item in the array and compare it with the key value to be searched. If it is matched, return the position of the median.
Step 2 − If it does not match the key value, check if the key value is either greater than or less than the median value.
Step 3 − If the key is greater, perform the search in the right sub-array; but if the key is lower than the median value, perform the search in the left sub-array.
Step 4 − Repeat Steps 1, 2 and 3 iteratively, until the size of sub-array becomes 1.
Step 5 − If the key value does not exist in the array, then the algorithm returns an unsuccessful search.


CODE:*/
#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int binary_search(int arr[], int n, int x)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main()
{
    int n, x;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    merge_sort(arr, 0, n - 1);

    printf("Enter the element to search: ");
    scanf("%d", &x);

    int result = binary_search(arr, n, x);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
/* OUTPUT :

Enter the number of elements in the array: 5
Enter the elements of the array: 12 5 8 3 9
Enter the element to search: 8
Element found at index 2

*/