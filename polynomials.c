#include <stdio.h>

// Define a structure to store the polynomial
struct Poly
{
    int e;
    int c;
};

// Function prototypes
void readPoly(struct Poly *p, int *n);
void printPoly(struct Poly *p, int n);
void sortPoly(struct Poly *p, int n);
int addPoly(struct Poly *p1, struct Poly *p2, struct Poly *res, int n1, int n2);

int main(void)
{
    struct Poly p1[10], p2[10], res[20];
    int n1, n2, n3;

    readPoly(p1, &n1);
    readPoly(p2, &n2);

    sortPoly(p1, n1);
    sortPoly(p2, n2);

    printf("Polynomial 1: ");
    printPoly(p1, n1);
    printf("Polynomial 2: ");
    printPoly(p2, n2);

    n3 = addPoly(p1, p2, res, n1, n2);
    printf("Resultant polynomial: ");
    printPoly(res, n3);
    
    return 0;
}

// Read polynomials
void readPoly(struct Poly *p, int *n)
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
void printPoly(struct Poly *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i].e == 0)
        {
            printf("%d\n", p[i].c);
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
void sortPoly(struct Poly *p, int n)
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
int addPoly(struct Poly *p1, struct Poly *p2, struct Poly *res, int n1, int n2)
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