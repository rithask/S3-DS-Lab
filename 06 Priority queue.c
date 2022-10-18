/*
Write a program to implement a priority queue using array 
and perform operations on it.
*/

# include <stdio.h>

int front = -1, rear = -1;
int size;
int items[100];

int is_full();
int is_empty();
void enqueue(int element);
void dequeue();
void print_queue();

int main()
{
    int choice, element;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    while (1)
    {
        printf("\n1. Insert an element\n2. Delete element\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
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
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}

int is_full()
{
    if ((rear == size - 1 && front == 0) || (rear == front - 1)) return 1;
    return 0;
}

int is_empty()
{
    if (front == -1) return 1;
    return 0;
}

void enqueue(int element)
{
    if (is_full())
    {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) front = 0;
    if (rear == size - 1) rear = -1;
    items[++rear] = element;
    printf("Element inserted successfully\n");
}

void dequeue()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Element deleted: %d\n", items[front++]);
    if (front == size) front = 0;
    if (front - 1 == rear) front = rear = -1;
}

void print_queue()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", items[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", items[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", items[i]);
    }
    printf("\n");
}