// Write a program to read two polynomials and store them using a linked list.
// Find the product of two polynomials and store the result using a linked list.
// Display the resultant polynomial

/*
ALGORITHM

Algoritm for main
1. Start
2. Read the first polynomial
3. Read the second polynomial
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff;
    int exp;
    struct node *next;
}node;

node *head1 = NULL;
node *head2 = NULL;
node *head3 = NULL;

void insert(node **head, int coeff, int exp)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;
    if (*head == NULL)
        *head = new_node;
    else
    {
        node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

void read_poly(node **head, int n)
{
    int coeff, exp;
    for (int i = 0; i < n; i++)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &coeff);
        printf("Enter the exponent: ");
        scanf("%d", &exp);
        insert(head, coeff, exp);
    }
}

void print_poly(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->coeff);
        if (temp->exp != 0)
            printf("x^%d", temp->exp);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

void sort_poly(node **head)
{
    node *temp1 = *head;
    node *temp2 = NULL;
    while (temp1 != NULL)
    {
        temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if (temp1->exp < temp2->exp)
            {
                int coeff = temp1->coeff;
                int exp = temp1->exp;
                temp1->coeff = temp2->coeff;
                temp1->exp = temp2->exp;
                temp2->coeff = coeff;
                temp2->exp = exp;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

void multiply_poly(node *head1, node *head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    while (temp1 != NULL)
    {
        temp2 = head2;
        while (temp2 != NULL)
        {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            insert(&head3, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    sort_poly(&head3);
}

void add_poly(node *head1, node *head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    int coeff, exp;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->exp == temp2->exp)
        {
            coeff = temp1->coeff + temp2->coeff;
            exp = temp1->exp;
            insert(&head3, coeff, exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp)
        {
            coeff = temp1->coeff;
            exp = temp1->exp;
            insert(&head3, coeff, exp);
            temp1 = temp1->next;
        }
        else
        {
            coeff = temp2->coeff;
            exp = temp2->exp;
            insert(&head3, coeff, exp);
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        coeff = temp1->coeff;
        exp = temp1->exp;
        insert(&head3, coeff, exp);
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        coeff = temp2->coeff;
        exp = temp2->exp;
        insert(&head3, coeff, exp);
        temp2 = temp2->next;
    }
}

void add_like_terms(node **head)
{
    node *temp1 = *head;
    node *temp2 = NULL;
    int coeff, exp;
    while (temp1 != NULL)
    {
        temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if (temp1->exp == temp2->exp)
            {
                coeff = temp1->coeff + temp2->coeff;
                exp = temp1->exp;
                temp1->coeff = coeff;
                temp1->exp = exp;
                temp2->coeff = 0;
                temp2->exp = 0;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

int main()
{
    int n1, n2;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    printf("Enter the first polynomial:\n");
    read_poly(&head1, n1);
    printf("\n");

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    printf("Enter the second polynomial:\n");
    read_poly(&head2, n2);
    printf("\n");

    sort_poly(&head1);
    sort_poly(&head2);

    printf("The first polynomial is: ");
    print_poly(head1);
    printf("The second polynomial is: ");
    print_poly(head2);
    printf("\n");
    
    multiply_poly(head1, head2);
    add_like_terms(&head3);
    printf("The product of the two polynomials is: ");
    print_poly(head3);
    return 0;
}