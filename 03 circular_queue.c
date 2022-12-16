/*
Implement a circular queue using arrays with the operations:
    1.Insert an element to the queue.
    2.Delete an elements from the queue.
    3.Display the contents of the queue after each operation.
*/

/*
ALGORITHM

Global variables:
    size: size of the queue
    queue: array to store the queue elements
    front: index of the front element
    rear: index of the rear element

Algorithm for main
1. Start
2. Read the size of the queue
3. Display the menu
4. Read the choice
    4.1 If choice is insert
        4.1.1 Call the enqueue function
    4.2 Else if choice is delete
        4.2.1 Call the dequeue function
    4.3 Else if choice is display
        4.3.1 Call the print_queue function
    4.4 Else if choice is exit
        4.4.1 Exit
    4.5 Else
        4.5.1 Display Invalid choice
5. Stop

Algorithm to check if the queue is full
1. Start
2. If rear is equal to size - 1 and front is equal to 0 or rear is equal to front - 1, return 1
3. Else, return 0
4. Stop

Algorithm to check if the queue is empty
1. Start
2. If front is equal to -1, return 1
3. Else, return 0
4. Stop

Algorithm to enqueue an element to the queue
1. Start
2. If is full function returns 1, display Queue is full
3. Else
    3.1 If front is equal to -1, set front = 0
    3.2 rear = (rear + 1) % size
    3.3 Read element
    3.4 Store element in queue[rear]
4. Stop

Algorithm to dequeue an element from the queue
1. Start
2. If is empty function returns 1, display Queue is empty
3. Else
    3.1 If front is equal to rear, set front = rear = -1
    3.2 Else, front = (front + 1) % size
4. Stop

Algorithm to print the queue
1. Start
2. If is empty function returns 1, display Queue is empty
3. Else
    3.1 Set i to front
    3.2 Repeat until i is equal to rear
    3.3 Print the element at i
    3.4 Increment i by 1
4. Stop
*/

#include <stdio.h>

// Declare global variables
int front = -1, rear = -1;
int size;
int items[100];

int is_full();
int is_empty();
void enqueue();
void dequeue();
void print_queue();

int main(void)
{
    printf("Enter the size of the circular queue: ");
    scanf("%d", &size);

    // Show a menu till the user exits
    int op;
    while(1)
    {
        printf("\n1. Insert an element\n2. Delete element\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);
        printf("\n");

        switch (op)
        {
            case 1:
                enqueue();
                print_queue();
                break;
            case 2:
                dequeue();
                print_queue();
                break;
            case 3:
                print_queue();
                break;
            case 4:
                printf("Exiting...\n");
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
void enqueue()
{
    if (is_full())
    {
        printf("Queue is full.\n");
        return;
    }

    if (front == -1) front = 0;
    rear = (rear + 1) % size;
    
    printf("Enter the element to be inserted: ");
    scanf("%d", &items[rear]);

    printf("Inserted -> %d\n", items[rear]);
}

// Delete element from the queue
void dequeue()
{
    if (is_empty()) return;

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

    printf("Items: ");
    for (i = front; i != rear; i = ((i + 1) % size))
    {
        printf("%d ", items[i]);
    }
    printf("%d\n", items[i]);
}