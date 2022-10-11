/*
Implement a circular queue using arrays with the operations:
    1.Insert an element to the queue.
    2.Delete an elements from the queue.
    3.Display the contents of the queue after each operation.
*/

#include <stdio.h>

// Declare global variables
int front = -1, rear = -1;
int size;
int items[100];

int is_full();
int is_empty();
void enqueue(int element);
void dequeue();
void print_queue();

int main(void)
{
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Show a menu till the user exits
    while(1)
    {
        int op, element;
        printf("\n1. Insert an element\n2. Delete element\n3. Display the queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            print_queue();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

// Check if queue is full
int is_full()
{
    if ((rear == size - 1 && front == 0) || (rear == front - 1)) return 1;
    return 0;
}

// Check if queue is empty
int is_empty()
{
    if (front == -1) return 1;
    return 0;
}

// Add element to the queue
void enqueue(int element)
{
    if (is_full())
    {
        printf("Queue is full.\n");
        return;
    }
    
    if (front == -1) front = 0;
    rear = (rear + 1) % size;
    items[rear] = element;
    printf("Inserted -> %d\n", element);
}

// Delete element from the queue
void dequeue()
{
    if (is_empty())
    {
        printf("Queue is empty.\n");
        return;
    }

    int element = items[front];

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }

    printf("Deleted -> %d\n", element);
}

// Display the queue
void print_queue()
{
    int i;
    if (is_empty())
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Front = %d\n", front);
    printf("Items: ");
    for (i = front; i != rear; i = ((i + 1) % size))
    {
        printf("%d ", items[i]);
    }
    printf("%d", items[i]);
    printf("\nRear = %d\n", rear);
}