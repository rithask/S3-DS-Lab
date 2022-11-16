// Write a program to implement linear and binary search.

/*
ALGORITHM

Algorithm for main
1. Start
2. Declare variables
3. Read the number of elements in the array
4. Read the elements of the array
5. Read the element to be searched
6. Call linear_search() function
7. If the element is found
    7.1. Display Element found at position i
8. Else
    8.1. Display Element not found
9. Sort the array and print it
10. Call binary_search() function
11. If the element is found
    11.1. Display Element found at position i
12. Else
    12.1. Display Element not found
13. Stop

Algorithm to read the array
1. Start
2. Iterate from 0 to n
    2.1. Read the element
    2.2. Store the element in the array
3. Stop

Algorithm to print the array
1. Start
2. Iterate from 0 to n
    2.1. Display the element
3. Stop

Algorithm to sort the array
1. Start
2. Iterate from 0 to n - 1
    2.1. Iterate from 0 to n - 1
        2.1.1. If the element is greater than the next element
            i. Swap the elements
3. Stop

Algorithm for linear search
1. Start
2. Iterate from 0 to n
    2.1. If the element is equal to the element to be searched
        2.1.1. Return i
3. Return -1
4. Stop

Algorithm for binary search
1. Start
2. Declare variables
3. Set low = 0 and high = n - 1
4. While low <= high
    4.1. Set mid = (low + high) / 2
    4.2. If the element is equal to the element to be searched
        4.2.1. Return mid
    4.3. Else if the element is greater than the element to be searched
        4.3.1. Set high = mid - 1
    4.4. Else
        4.4.1. Set low = mid + 1
5. Return -1
6. Stop
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void read_array(int *a, int n);
void print_array(int *a, int n);
void sort_array(int *a, int n);
int linear_search(int *arr, int n, int key);
int binary_search(int *arr, int n, int key);

int main()
{
    int arr[SIZE], n, search, pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    read_array(arr, n);

    printf("Enter the item to search: ");
    scanf("%d", &search);

    printf("\nLinear Search\n");
    pos = linear_search(arr, n, search);
    (pos == -1)
        ? printf("Item not found\n")
        : printf("Item found at position %d\n", pos);

    sort_array(arr, n);
    printf("\nSorted array: ");
    print_array(arr, n);

    printf("\nBinary Search\n");
    pos = binary_search(arr, n, search);
    (pos == -1)
        ? printf("Item not found\n")
        : printf("Item found at position %d\n", pos);

    return 0;
}

void read_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int linear_search(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;

    return -1;
}

void sort_array(int *a, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int binary_search(int *arr, int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}