/*
Implement a circular queue using arrays with the operations:
    1.Insert an element to the queue.
    2.Delete an elements from the queue.
    3.Display the contents of the queue after each operation.
*/

/*
ALGORITHM
1. Start
2. Declare and initialise the front and rear to -1 globally
3. Declare the array globally
4. Define the function enqueue()
    4.1 If the queue is full, display Queue is full
    4.2 Else
        4.2.1 If the queue is empty, increment front and rear by 1
        4.2.2 Else, increment rear by 1
        4.2.3 Insert the element at the rear
5. Define the function dequeue()
    5.1 If the queue is empty, display Queue is empty
    5.2 Else
        5.2.1 If front and rear are equal, set front and rear to -1
        5.2.2 Else, increment front by 1
6. Define the function print_queue()
    6.1 If the queue is empty, display Queue is empty
    6.2 Else
        6.2.1 Set i to front
        6.2.2 Repeat until i is equal to rear
        6.2.3 Print the element at i
        6.2.4 Increment i by 1
7. Display the menu
    7.1 Read the choice
    7.2 If the choice is insert
        7.2.1 Read the element
        7.2.2 Call the function enqueue()
    7.3 Else if the choice is delete
        7.3.1 Call the dequeue function
    7.3 Else if the choice is exit
        7.3.1 Exit
8. Repeat from step 7
9. Stop
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
        printf("\n1. Insert an element\n2. Delete element\n3. Exit\n");
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
    print_queue();
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
    print_queue();
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