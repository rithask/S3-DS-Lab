// Implement quick sort, merge sort, and heap sort

/*
ALGORITHM

1. Start
2. Read the number of elements
3. Read the elements
4. Create three arrays of the same size
5. Copy the elements of the first array to the other two arrays
6. Call the quick sort function and pass the first array as the argument
7. Call the merge sort function and pass the second array as the argument
8. Call the heap sort function and pass the third array as the argument
9. Display the sorted arrays
10. Stop

Algorithm for quick sort
1. Start
2. If left is greater than or equal to right
	2.1 return
3. Set the pivot value return by the partition function
4. Call the quick sort function and pass the left and pivot - 1 as the arguments
5. Call the quick sort function and pass the pivot + 1 and right as the arguments
6. Stop

Algorithm for partition
1. Start
2. Set the pivot value to the rightmost element
3. Set i to low - 1
4. Traverse the array from low to high - 1
	4.1 If the element is less than or equal to the pivot value
		4.1.1 Increment i
		4.1.2 Swap the element at i and the element at j
5. Swap the element at i + 1 and the element at high
6. Return i + 1
7. Stop

Algorithm for merge sort
1. Start
2. If left is greater than or equal to right
	2.1 return
3. Set the middle value to the average of left and right
4. Call the merge sort function and pass the left and middle as the arguments
5. Call the merge sort function and pass the middle + 1 and right as the arguments
6. Call the merge function and pass the left, middle, and right as the arguments
7. Stop

Algorithm for merge
1. Start
2. Set the l_size to middle - left + 1
3. Set the r_size to right - middle
4. Create two arrays of size l_size and r_size
5. Copy the elements of the array from left to middle to the left array
6. Copy the elements of the array from middle + 1 to right to the right array
7. Declare two variables i and j and set them to 0
8. Repeat until i < l_size and j < r_size
	8.1 If left_array[i] < right_array[j]
		8.1.1 Copy left_array[i] to array[k]
		8.1.2 Increment i
	8.2 Else
		8.2.1 Copy right_array[j] to array[k]
		8.2.2 Increment j
	8.3 Increment k
9. Repeat until i < l_size
	9.1 Copy left_array[i] to array[k]
	9.2 Increment i and k
10. Repeat until j < r_size
	10.1 Copy right_array[j] to array[k]
	10.2 Increment j and k
11. Stop

Algorithm for heap sort
1. Start
2. Repeat until n > 1
	2.1 Call the heapify function and pass the array, n, and 0 as the arguments
	2.2 Swap the element at 0 and the element at n - 1
	2.3 Decrement n
3. Stop

Algorithm for heapify
1. Start
2. Set the largest to i
3. Set the left to 2 * i + 1
4. Set the right to 2 * i + 2
5. If left < n and array[left] > array[largest]
	5.1 Set largest to left
6. If right < n and array[right] > array[largest]
	6.1 Set largest to right
7. If largest is not equal to i
	7.1 Swap the element at i and the element at largest
	7.2 Call the heapify function and pass the array, n, and largest as the arguments
8. Stop
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(int a[], int low, int high);
int partition(int a[], int low, int high);

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quicksort(int a[], int low, int high)
{
    if (low >= high) return;

	int pivot = partition(a, low, high);
	quicksort(a, low, pivot - 1);
	quicksort(a, pivot + 1, high);
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
			swap(&a[i], &a[j]);
        }
    }
	swap(&a[i + 1], &a[high]);
    return i + 1;
}

void merge(int arr[], int left, int right, int mid)
{
    int l_size = mid - left + 1;
    int r_size = right - mid;

    /* create temp arrays */
    int left_arr[l_size], right_arr[r_size];

    /* Copy data to temp arrays L[] and R[] */
    for (int i = 0; i < l_size; i++)
        left_arr[i] = arr[left + i];

    for (int j = 0; j < r_size; j++)
        right_arr[j] = arr[mid + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray
    while (i < l_size && j < r_size)
    {
        if (left_arr[i] < right_arr[j])
        {
            arr[k] = left_arr[i++];
        }
        else
        {
            arr[k] = right_arr[j++];
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < l_size)
        arr[k++] = left_arr[i++];

    /* Copy the remaining elements of R[], if there are any */
    while (j < r_size)
        arr[k++] = right_arr[j++];
}

void merge_sort(int arr[], int left, int right)
{
    if (left >= right) // base condition to exit recursion
        return;

    int mid = left + (right - left) / 2; // calculating mid, same as (left + right)/2

    merge_sort(arr, left, mid);      // perform mergesort on left half
    merge_sort(arr, mid + 1, right); // perform mergesort on right half
    merge(arr, left, right, mid);   // Merge the sorted arrays
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
    {
        largest = left;
    }
    if (right < n && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
		swap(&a[i], &a[largest]);
		heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
		swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void display(int *arrr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arrr[i]);
	}
	printf("\n");
}

int main()
{
    int arr[100];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

	// create two copy arrays
	int temp1[n], temp2[n], temp3[n];
	memcpy(temp1, arr, n * sizeof(int));
	memcpy(temp2, arr, n * sizeof(int));
	memcpy(temp3, arr, n * sizeof(int));

    quicksort(temp1, 0, n - 1);
    merge_sort(temp2, 0, n - 1);
    heap_sort(temp3, n);

	int choice;
	while(1)
	{
		printf("\n1. Quick sort\n2. Merge sort\n3. Heap sort\n4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d" , &choice);
		printf("\n");

		switch(choice)
		{
			case 1:
				printf("Quick sort: ");
				display(temp1, n);
				break;
			case 2:
				printf("Merge sort: ");
				display(temp2, n);
				break;
			case 3:
				printf("Heap sort: ");
				display(temp3, n);
				break;
			case 4:
				printf("Exiting...\n");
				exit(0);
			default:
				printf("Invalid choice\n");
		}
	}

    printf("\n");
    return 0;
}