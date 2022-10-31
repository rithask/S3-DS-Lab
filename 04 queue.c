/*
Write a program to Implement a queue using arrays with the operations:
1. Insertion of an element at the rear of the queue.
2. Deletion of an element from the front of the queue.
3. Display the elements of the queue.
The program should display the queue elements after each operation

ALGORITHM

Global variables:
    size: size of the queue
    queue: array to store the queue elements
    front: index of the front element
    rear: index of the rear element

insert function
1. Start
2. If rear is equal to size - 1, display Queue is full
3. Else
    3.1 If front is equal to -1, set front = 0
    3.2 rear = rear + 1
    3.3 Insert the element at rear
4. Stop

delete function
1. Start
2. If front is equal to -1 or front > rear, display Queue underflow
3. Else
    3.1 Print the element at front
    3.2 front = front + 1
4. Stop

display function
1. Start
2. If front is equal -1, display Queue is empty
3. Else
    3.1 Set i to front
    3.2 Repeat until i is equal to rear
    3.3 Print the element at i
    3.4 Increment i by 1
4. Stop

main function
1. Start
2. Read the size of the queue
3. Display the menu
4. Read the choice
    4.1 If choice is insert
        4.1.1 Read the element to be inserted
        4.1.2 Call the insert function
        4.1.3 Display the queue elements
    4.2 Else if choice is delete
        4.2.1 Call the delete function
        4.2.2 Display the queue elements
    4.3 Else if choice is exit
        4.3.1 Exit
    4.4 Else
        4.4.1 Display Invalid choice
5. Stop
*/

#include <stdio.h>
#include <stdlib.h>

int size;
int queue[50];
int front = -1, rear = -1;

void insert(int);
int delete();
void display();

int main()
{
    printf("Enter the size of the queue: ");
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
    if (rear == size - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear = rear + 1;
    queue[rear] = item;
}

int delete()
{
    int item;
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        exit(0);
    }
    item = queue[front];
    front = front + 1;
    return item;
}

void display()
{
    int i;
    if (front == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue is: ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\nFront = %d, Rear = %d\n", front, rear);
    }
}