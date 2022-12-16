/*
Write a program to enter two matrices in normal form.
Write a function to convert two marices to tuple form and display it.
Also find the transpose of the two matrices represented in tuple form and display it.
Find the sum of the two matrices in tuple form and display the sum in tuple form.
*/  

/*
ALGORITHM

Algorithm for main
1. Start
2. Declare two matrices, two tuples, two transposed tuples and one sum tuple
3. Declare n1, m1 and n2, m2
4. Read two matrices using the read matrix function
5. Display a menu
    5.1 If the user enters 1
        5.1.1 Display the matrices
    5.2 Else if the user enters 2
        5.2.1 Convert the matrices to tuples using the convert matrix to tuple function
        5.2.2 Display the tuples
    5.3 Else if the user enters 3
        5.3.1 Find the transpose of the tuples using the transpose tuple function
        5.3.2 Display the transposed tuples
    5.4 Else if the user enters 4
        5.4.1 Add the tuples using the add tuple function
        5.4.2 Display the sum tuple
    5.5 Else if the user enters 5
        5.5.1 Exit
6. Stop

Algorithm to read a matrix in normal form
1. Start
2. Read the number of rows and columns
3. Iterate from 0 to number of rows
    3.1 Iterate from 0 to number of columns
        3.1.1 Read the element
        3.1.2 Store the element in the array
4. Stop

Algorithm to print a matrix in normal form
1. Start
2. Iterate from 0 to number of rows
    2.1 Iterate from 0 to number of columns
        2.1.1 Print the element
    2.2 Print a new line
3. Stop

Algorithm to convert a matrix to tuple form
1. Start
2. Declare and initialize k to 1
3. Iterate from 0 to number of rows
    3.1 Iterate from 0 to number of columns
        3.1.1 If the element is not 0
            3.1.1.1 Store the row number, column number and element in the tuple array
            3.1.1.2 Increment k
4. Store the number of rows, number of columns and k in the tuple array
5. Stop

Algorithm to print a matrix in tuple form
1. Start
2. Store array[0][2] in n
3. Iterate from 0 to n
    3.1 Print the row number, column number and element
4. Stop

Algorithm to find the transpose of a matrix in tuple form
1. Start
2. Store array1[0][0] in array2[0][1]
3. Store array1[0][1] in array2[0][0]
4. Store array1[0][2] in array2[0][2]
5. Iterate from 1 to array1[0][2]
    5.1 Store array1[i][1] in array2[i][0]
    5.2 Store array1[i][0] in array2[i][1]
    5.3 Store array1[i][2] in array2[i][2]
6. Sort the array2 using the bubble sort algorithm
7. Stop

Algorithm to add two matrices in tuple form
1. Start
2. If rows and columns of array1 and array2 are not equal
    2.1 Print "Addition not possible"
    2.2 Exit
3. Declare and initialize i, j, k to 1
4. While i < array1[0][2] and j < array2[0][2]
    4.1 if array1[i][0] < array2[j][0]
        4.1.1 Store array1[i][0] in array3[k][0]
        4.1.2 Store array1[i][1] in array3[k][1]
        4.1.3 Store array1[i][2] in array3[k][2]
        4.1.4 Increment i and k
    4.2 Else if array1[i][0] > array2[j][0]
        4.2.1 Store array2[j][0] in array3[k][0]
        4.2.2 Store array2[j][1] in array3[k][1]
        4.2.3 Store array2[j][2] in array3[k][2]
        4.2.4 Increment j and k
    4.3 Else if array1[i][0] == array2[j][0]
        4.3.1 If array1[i][1] < array2[j][1]
            i. Store array1[i][0] in array3[k][0]
            ii. Store array1[i][1] in array3[k][1]
            iii. Store array1[i][2] in array3[k][2]
            iv. Increment i and k
        4.3.2 Else if array1[i][1] > array2[j][1]
            i. Store array2[j][0] in array3[k][0]
            ii. Store array2[j][1] in array3[k][1]
            iii. Store array2[j][2] in array3[k][2]
            iv. Increment j and k
        4.3.3 Else if array1[i][1] == array2[j][1]
            i. Store array1[i][0] in array3[k][0]
            ii. Store array1[i][1] in array3[k][1]
            iii. Store array1[i][2] + array2[j][2] in array3[k][2]
            iv. Increment i, j and k
5. If i < array1[0][2]
    5.1 Store array1[i][0] in array3[k][0]
    5.2 Store array1[i][1] in array3[k][1]
    5.3 Store array1[i][2] in array3[k][2]
    5.4 Increment i and k
6. If j < array2[0][2]
    6.1 Store array2[j][0] in array3[k][0]
    6.2 Store array2[j][1] in array3[k][1]
    6.3 Store array2[j][2] in array3[k][2]
    6.4 Increment j and k
7. Store array1[0][0] in array3[0][0]
8. Store array1[0][1] in array3[0][1]
9. Store k - 1 in array3[0][2]
10. Stop
*/

#include <stdio.h>
#include <stdlib.h>

void read_matrix(int a[][10], int *m, int *n);
void print_matrix(int a[][10], int m, int n);
void to_tuple(int a[][10], int b[][3], int m, int n);
void to_transpose(int b[][3], int c[][3]);
void print_tuple(int b[10][3]);
void add_tuple(int a[][3], int b[][3], int sum[][3]);

int main(void)
{
    int a[10][10], b[10][10];
    int tp1[20][3], tp2[20][3];
    int trans1[20][3], trans2[20][3];
    int sum[20][3];
    int m1, n1, m2, n2;
    int choice;

    printf("Matrix 1:\n");
    read_matrix(a, &m1, &n1);
    printf("Matrix 2:\n");
    read_matrix(b, &m2, &n2);

    to_tuple(a, tp1, m1, n1);
    to_tuple(b, tp2, m2, n2);

    to_transpose(tp1, trans1);
    to_transpose(tp2, trans2);

    add_tuple(tp1, tp2, sum);

    while (1)
    {
        printf("1. Print matrices\n2. Print tuples\n3. Print transposed tuples\n4. Print sum of tuples\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nMatrix 1...\n");
                print_matrix(a, m1, n1);
                printf("\nMatrix 2...\n");
                print_matrix(b, m2, n2);
                break;
            case 2:
                printf("\nTuple 1...\n");
                print_tuple(tp1);
                printf("\nTuple 2...\n");
                print_tuple(tp2);
                break;
            case 3:
                printf("\nTransposed tuple 1...\n");
                print_tuple(trans1);
                printf("\nTransposed tuple 2...\n");
                print_tuple(trans2);
                break;
            case 4:
                printf("\nSum of tuples...\n");
                print_tuple(sum);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

// Read the matrix from the user
void read_matrix(int a[][10], int *m, int *n)
{
    printf("Enter the number of rows: ");
    scanf("%d", m);
    printf("Enter the number of columns: ");
    scanf("%d", n);
    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < *m; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

// Print the matrix
void print_matrix(int a[][10], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

// Convert the matrix to 3-tuple form
void to_tuple(int mat[][10], int t[][3], int m, int n)
{
    // First element of the tuple is the number of non-zero elements
    int k = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // If the element is non-zero, store it in the tuple
            if (mat[i][j] != 0)
            {
                t[k][0] = i;
                t[k][1] = j;
                t[k][2] = mat[i][j];
                k++;
            }
        }
    }

    // Store the number of rows, columns and non-zero elements in the tuple
    t[0][0] = m;
    t[0][1] = n;
    t[0][2] = k - 1;
}

void to_transpose(int b[][3], int c[][3])
{
    // First element of the tuple is the number of non-zero elements
    int k = b[0][2];
    c[0][0] = b[0][1];
    c[0][1] = b[0][0];
    c[0][2] = k;
    int x = 1;

    // Store the transpose of the tuple in the new tuple
    for (int i = 1; i <= k; i++)
    {
        c[x][0] = b[i][1];
        c[x][1] = b[i][0];
        c[x][2] = b[i][2];
        x++;
    }

    // Sort tuple form using bubble sort algorithm
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k - i; j++)
        {
            // If the row number of the current element is greater than the row number of the next element
            if (c[j][0] > c[j + 1][0])
            {
                // Swap the elements
                int temp = c[j][0];
                c[j][0] = c[j + 1][0];
                c[j + 1][0] = temp;

                temp = c[j][1];
                c[j][1] = c[j + 1][1];
                c[j + 1][1] = temp;

                temp = c[j][2];
                c[j][2] = c[j + 1][2];
                c[j + 1][2] = temp;
            }
        }
    }
}

// Print the tuple
void print_tuple(int b[10][3])
{
    int k = b[0][2];
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= k; i++)
    {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}

// Add two tuples
void add_tuple(int a[][3], int b[][3], int sum[][3])
{
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1])
    {
        printf("The matrices cannot be added.\n");
        return;
    }

    // First element of the tuple is the number of non-zero elements
    int i = 1, j = 1, k = 1;
    while (i <= a[0][2] && j <= b[0][2])
    {
        // If the row number of the current element of tuple 1 is equal to the row number of the current element of tuple 2
        if (a[i][0] == b[j][0])
        {
            // If the column number of the current element of tuple 1 is equal to the column number of the current element of tuple 2
            if (a[i][1] == b[j][1])
            {
                // Add the values of the elements and store it in the sum tuple
                sum[k][0] = a[i][0];
                sum[k][1] = a[i][1];
                sum[k][2] = a[i][2] + b[j][2];
                i++;
                j++;
                if (sum[k][2] == 0) continue;
                k++;
            }
            // If the column number of the current element of tuple 1 is less than the column number of the current element of tuple 2
            else if (a[i][1] < b[j][1])
            {
                // Copy the element of tuple 1 to the sum tuple
                sum[k][0] = a[i][0];
                sum[k][1] = a[i][1];
                sum[k][2] = a[i][2];
                i++;
                k++;
            }
            // If the column number of the current element of tuple 1 is greater than the column number of the current element of tuple 2
            else
            {
                // Copy the element of tuple 2 to the sum tuple
                sum[k][0] = b[j][0];
                sum[k][1] = b[j][1];
                sum[k][2] = b[j][2];
                j++;
                k++;
            }
        }
        // If the row number of the current element of tuple 1 is less than the row number of the current element of tuple 2
        else if (a[i][0] < b[j][0])
        {
            // Copy the element of tuple 1 to the sum tuple
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2];
            i++;
            k++;
        }
        // If the row number of the current element of tuple 1 is greater than the row number of the current element of tuple 2
        else
        {
            // Copy the element of tuple 2 to the sum tuple
            sum[k][0] = b[j][0];
            sum[k][1] = b[j][1];
            sum[k][2] = b[j][2];
            j++;
            k++;
        }
    }
    // Copy the remaining elements of tuple 1 to the sum tuple
    while (i <= a[0][2])
    {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2];
        i++;
        k++;
    }
    // Copy the remaining elements of tuple 2 to the sum tuple
    while (j <= b[0][2])
    {
        sum[k][0] = b[j][0];
        sum[k][1] = b[j][1];
        sum[k][2] = b[j][2];
        j++;
        k++;
    }

    // Store the number of rows, columns and non-zero elements in the sum tuple
    sum[0][0] = a[0][0];
    sum[0][1] = a[0][1];
    sum[0][2] = k - 1;
}