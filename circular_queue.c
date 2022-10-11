/*
Implement a circular queue using arrays with the operations:
    1.Insert an element to the queue.
    2.Delete an elements from the queue.
    3.Display the contents of the queue after each operation.
*/

#include <stdio.h>

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

    dequeue(1);
    print_queue();
    
    enqueue(1);
    print_queue();

    enqueue(4);
    print_queue();
    enqueue(5);
    print_queue();
    enqueue(2);
    print_queue();
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
        printf("Queue is full.\n");
        return;
    }
    
    if (front == -1) front = 0;
    rear = (rear + 1) % size;
    items[rear] = element;
    printf("Inserted -> %d\n", element);
}

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