/*
Write a program to Implement a stack using arrays with the operations:
1. Insertion of an element at the top of the stack.
2. Deletion of an element from the top of the stack.
3. Display the elements of the stack.
The program should display the stack elements after each operation

ALGORITHM
1. Start
2. Declare the array stack[50], top, choice, item
3. Initialize top = -1
4. Read size of the stack from the user
6. Display the menu
7. Read the choice from the user
8. If choice is insert
    8.1 Read the item from the user
    8.2 If top == size - 1
        8.2.1 Display "Stack is full"
        8.2.2 Goto step 6
    8.3 Else
        8.3.1 top = top + 1
        8.3.2 stack[top] = item
    8.4 Display the stack elements
    8.5 Goto step 6
9. Else if choice is delete
    9.1 If top == -1
        9.1.1 Display "Stack underflow"
        9.1.2 Goto step 6
    9.2 Else
        9.2.1 item = stack[top]
        9.2.2 top = top - 1
        9.2.3 Display item
    9.3 Display stack elements
    9.4 Goto step 6
10. Stop
*/

#include <stdio.h>
#include <stdlib.h>

int size;
int stack[50];
int top = -1;

void insert(int);
int delete();
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
            insert(item);
            display();
            break;
        case 2:
            item = delete();
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

void insert(int item)
{
    if (top == size - 1)
    {
        printf("Stack is full\n");
        return;
    }
    top = top + 1;
    stack[top] = item;
}

int delete()
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
