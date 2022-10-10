/*
Write a program to enter two matrices in normal form.
Write a function to convert two marices to tuple form and display it.
Also find the transpose of the two matrices represented in tuple form and display it.
Find the sum of the two matrices in tuple form and display the sum in tuple form.
*/

#include <stdio.h>

void read_matrix(int m[][10], int r, int c);
void print_matrix(int m[][10], int r, int c);
void to_tuple(int m[][10], int tp[][3], int r, int c);
void print_tuple(int tup[][3], int num);
void to_transpose(int tp[][3], int num);

int main(void)
{
    int a[10][10], b[10][10];
    int tp1[50][3], tp2[50][3];
    int r1, c1, r2, c2;

    printf("Enter the order of the first matrix: ");
    scanf("%d %d", &r1, &c1);
    read_matrix(a, r1, c1);

    printf("\nEnter the order of the second matrix: ");
    scanf("%d %d", &r2, &c2);
    read_matrix(b, r2, c2);

    printf("\nFirst matrix is...\n");
    print_matrix(a, r1, c1);
    printf("\nSecond matrix is...\n");
    print_matrix(b, r2, c2);

    to_tuple(a, tp1, r1, c1);
    printf("\nTuple form of first matrix:\n");
    print_tuple(tp1, tp1[0][2]);
    to_tuple(b, tp2, r2, c2);
    printf("\nTuple form of second matrix:\n");
    print_tuple(tp2, tp2[0][2]);

    to_transpose(tp1, tp1[0][2]);
    printf("\nTranspose of tuple form of first matrix is:\n");
    print_tuple(tp1, tp1[0][2]);

    to_transpose(tp2, tp2[0][2]);
    printf("\nTranspose of tuple form of second matrix is:\n");
    print_tuple(tp2, tp2[0][2]);

    return 0;
}

// Read matrix from the user
void read_matrix(int m[][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("Enter the element %d, %d: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

// Print the matrix
void print_matrix(int m[][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

// Convert the matrix to 3-tuple form
void to_tuple(int m[][10], int tp[][3], int r, int c)
{
    // Starts from 1st row since the 0th row stores the order and non-zero elements
    int x = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // Skip the element with 0 as it's value
            if(m[i][j] == 0) continue;

            tp[x][0] = i;
            tp[x][1] = j;
            tp[x][2] = m[i][j];
            x++;
        }
    }
    
    // Store the order and number of non-zero elements in the 0th row
    tp[0][0] = r;
    tp[0][1] = c;
    tp[0][2] = x - 1;
}

// Print the matrix in 3-tuple form
void print_tuple(int tup[][3], int num)
{
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i <= num; i++)
    {
        printf("%d\t%d\t%d\n", tup[i][0], tup[i][1], tup[i][2]);
    }
}

// Find the transpose of 3-tuple forn
void to_transpose(int tp[][3], int num)
{
    for (int i = 0; i <= num; i++)
    {
        int temp = tp[i][0];
        tp[i][0] = tp[i][1];
        tp[i][1] = temp;
    }

    // Sorting the transpose 3-tuple form using bubble sort algorithm
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num - i; j++)
        {
            if (tp[j][0] > tp[j + 1][0])
            {
                int temp = tp[j][0];
                tp[j][0] = tp[j + 1][0];
                tp[j + 1][0] = temp;

                temp = tp[j][1];
                tp[j][1] = tp[j + 1][1];
                tp[j + 1][1] = temp;

                temp = tp[j][2];
                tp[j][2] = tp[j + 1][2];
                tp[j + 1][2] = temp;
            }
        }
    }
}