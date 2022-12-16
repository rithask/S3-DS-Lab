/*
Write a program to Implement a stack using arrays with the operations:
1. Insertion of an element at the top of the stack.
2. Deletion of an element from the top of the stack.
3. Display the elements of the stack.
The program should display the stack elements after each operation

ALGORITHM

Global variables:
    size: size of the stack
    stack: array to store the stack elements
    top: index of the top element

Algorithm for main
1. Start
2. Read the size of the stack
3. Display the menu
4. Read the choice
    4.1 If choice is push
        4.1.1 Read the element to be pushed
        4.1.2 Call the push function
        4.1.3 Display the stack elements
    4.2 Else if choice is pop
        4.2.1 Call the pop function
        4.2.2 Display the stack elements
    4.3 Else if choice is exit
        4.3.1 Exit
    4.4 Else
        4.4.1 Display Invalid choice
5. Stop

Algorithm for push
1. Start
2. If top is equal to size - 1, display Stack is full
3. Else
    3.1 top = top + 1
    3.2 Insert the element at top
4. Stop

Algorithm for pop
1. Start
2. If top is equal to -1, display Stack underflow
3. Else
    3.1 Print the element at top
    3.2 top = top - 1
4. Stop

Algorithm for display
1. Start
2. If top is equal -1, display Stack is empty
3. Else
    3.1 Set i to 0
    3.2 Repeat until i is equal top
    3.3 Print the element at i
    3.4 Increment i by 1
4. Stop
*/

#include <stdio.h>
#include <stdlib.h>

int size;
int stack[50];
int top = -1;

void push(int);
int pop();
void display();

int main()
{
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    int choice, item;
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the item to be inserted: ");
            scanf("%d", &item);
            push(item);
            display();
            break;
        case 2:
            item = pop();
            if (item != -1)
                printf("\nDeleted item is %d\n", item);
            display();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}

void push(int item)
{
    if (top == size - 1)
    {
        printf("Stack is full\n");
        return;
    }
    top = top + 1;
    stack[top] = item;
}

int pop()
{
    if (top == -1)
    {
        printf("\nStack underflow\n");
        return -1;
    }
    int item = stack[top];
    top = top - 1;
    return item;
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\nTop = %d\n", top);
}
