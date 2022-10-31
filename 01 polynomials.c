/*
Write a program to read two polynomials and store them in an array.
Calculate the sum of the two polynomials and
display the first polynomial, second polynomial and
the resultant polynomial.
*/

/*
ALGORITHM

Read function
1. Start
2. Read the number of terms in the polynomial
3. Iterate from 0 to number of terms
    3.1 Read the coefficient and exponent of the term
    3.2 Store the coefficient and exponent in the array
4. End

Print function
1. Start
2. Iterate from 0 to number of terms
    2.1 If the coefficient is 0, skip the termt
    2.2 If the exponent is 0, print coefficient
    2.3 Else print coefficient and exponent
3. End

Sort function
1. Start
2. Iterate from 0 to number of terms
    2.1 Iterate from 0 to number of terms - 1
        2.1.1 If the exponent of the term is less than the exponent of the next term
            2.1.1.1 Swap the coefficients and exponents of the two terms
3. End

Add function
1. Start
2. Declare and initialize i, j, k to 0
3. While i < n1 and j < n2
    3.1 If the exponent of the first polynomial is greater than the exponent of the second polynomial
        3.1.1 Store the coefficient and exponent of the first polynomial in the result array
        3.1.2 Increment i and k
    3.2 Else if the exponent of the first polynomial is less than the exponent of the second polynomial
        3.2.1 Store the coefficient and exponent of the second polynomial in the result array
        3.2.2 Increment j and k
    3.3 Else
        3.3.1 Store the sum of the coefficients and exponent of the first polynomial in the result array
        3.3.2 Increment i, j and k
4. While i < n1
    4.1 Store the coefficient and exponent of the first polynomial in the result array
    4.2 Increment i and k
5. While j < n2
    5.1 Store the coefficient and exponent of the second polynomial in the result array
    5.2 Increment j and k
6. End

Main function
1. Start
2. Declare n1, n2, n3
3. Read the first and second polynomial using the read function
4. Sort the first and second polynomial using the sort function
5. Add the first and second polynomial using the add function
6. Print the first polynomial and the second polynomial using the print function
7. Print the result polynomial using the print function
8. End
*/

#include <stdio.h>

// Define a structure to store the polynomial
struct Poly
{
    int e;
    int c;
};

// Function prototypes
void read_poly(struct Poly *p, int *n);
void print_poly(struct Poly *p, int n);
void sort_poly(struct Poly *p, int n);
int add_poly(struct Poly *p1, struct Poly *p2, struct Poly *res, int n1, int n2);

int main(void)
{
    struct Poly p1[10], p2[10], res[20];
    int n1, n2, n3;

    read_poly(p1, &n1);
    read_poly(p2, &n2);

    sort_poly(p1, n1);
    sort_poly(p2, n2);

    printf("\nPolynomial 1: ");
    print_poly(p1, n1);
    printf("Polynomial 2: ");
    print_poly(p2, n2);

    n3 = add_poly(p1, p2, res, n1, n2);
    printf("Resultant polynomial: ");
    print_poly(res, n3);
    
    return 0;
}

// Read polynomials
void read_poly(struct Poly *p, int *n)
{
    printf("\nEnter the number of terms: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &p[i].c);
        printf("Enter the degree: x^");
        scanf("%d", &p[i].e);
    }
}

// Print polynomial
void print_poly(struct Poly *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i].c == 0)
            continue;
        if (p[i].e == 0)
        {
            printf("%d", p[i].c);
        }
        else
        {
            printf("%dx^%d", p[i].c, p[i].e);
        }
        if (i != n - 1)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

// Sort polynomial in descending order
void sort_poly(struct Poly *p, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].e < p[j + 1].e)
            {
                struct Poly temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

// Add two polynomials and return the number of terms in the resultant polynomial
int add_poly(struct Poly *p1, struct Poly *p2, struct Poly *res, int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (p1[i].e > p2[j].e)
        {
            res[k++] = p1[i++];
        }
        else if (p1[i].e < p2[j].e)
        {
            res[k++] = p2[j++];
        }
        else
        {
            res[k].e = p1[i].e;
            res[k++].c = p1[i++].c + p2[j++].c;
        }
    }
    while (i < n1)
    {
        res[k++] = p1[i++];
    }
    while (j < n2)
    {
        res[k++] = p2[j++];
    }

    return k;
}