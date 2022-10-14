/*
Write a program to enter two matrices in normal form.
Write a function to convert two marices to tuple form and display it.
Also find the transpose of the two matrices represented in tuple form and display it.
Find the sum of the two matrices in tuple form and display the sum in tuple form.
*/  

#include <stdio.h>

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

    printf("Matrix 1:\n");
    read_matrix(a, &m1, &n1);
    printf("Matrix 2:\n");
    read_matrix(b, &m2, &n2);

    printf("\nMatrix 1: \n");
    print_matrix(a, m1, n1);
    printf("\nMatrix 2: \n");
    print_matrix(b, m2, n2);

    to_tuple(a, tp1, m1, n1);
    to_tuple(b, tp2, m2, n2);
    printf("\nTuple form of matrix 1:\n");
    print_tuple(tp1);
    printf("\nTuple form of matrix 2:\n");
    print_tuple(tp2);

    to_transpose(tp1, trans1);
    to_transpose(tp2, trans2);
    printf("\nTranspose of tuple form of matrix 1:\n");
    print_tuple(trans1);
    printf("\nTranspose of tuple form of matrix 2:\n");
    print_tuple(trans2);

    add_tuple(tp1, tp2, sum);
    printf("\nSum of tuple form of matrix 1 and matrix 2:\n");
    print_tuple(sum);

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
    for (int i = 0; i < b[0][1]; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            c[x][0] = b[j][1];
            c[x][1] = b[j][0];
            c[x][2] = b[j][2];
            x++;
        }
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