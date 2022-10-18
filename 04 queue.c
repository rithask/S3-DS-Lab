/*
Write a program to Implement a queue using arrays with the operations:
1. Insertion of an element at the rear of the queue.
2. Deletion of an element from the front of the queue.
3. Display the elements of the queue.
The program should display the queue elements after each operation

ALGORITHM
1. Start
2. Declare the array queue[50], front, rear, choice, item
3. Initialize front = rear = -1
4. Read size of the queue from the user
6. Display the menu
7. Read the choice from the user
8. If choice is insert
    8.1 Read the item from the user
    8.2 If rear == size - 1
        8.2.1 Display "Queue is full"
        8.2.2 Goto step 6
    8.3 Else
        8.3.1 If front == -1
        8.3.2 front = 0
        8.3.3 rear = rear + 1
        8.3.4 queue[rear] = item
    8.4 Display the queue elements
    8.5 Goto step 6
9. Else if choice is delete
    9.1 If front == -1 or front > rear
        9.1.1 Display "Queue underflow"
        9.1.2 Goto step 6
    9.2 Else
        9.2.1 item = queue[front]
        9.2.2 If front == rear
    9.3 Display queue elements
    9.4 Goto step 6
10. Stop
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