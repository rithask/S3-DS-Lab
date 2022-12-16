/*
Implement a Priority Queue using arrays with the operations
    Insert elements to the Priority Queue.
    Delete elements from the Priority Queue.
    Display the contents of the Priority Queue after each operation.
*/

/*
ALGORITHM

Global Declarations:
    pq array of size 100
    size = -1

Algorithm for main
1. Start
2. Declare choice, data, priority
3. Display a menu
4. Read choice
5. If choice is insert
    5.1 Read data and priority
    5.2 Call enqueue function
    5.3 Call display function
6. Else if choice is delete
    6.1 Call dequeue function
    6.2 Call display function
7. Else if choice is display
    7.1 Call display function
8. Else if choice is exit
    8.1 Exit
9. Else
    9.1 Display "Invalid choice"
10. Goto step 3
11. Stop

Algorithm to check if the priority queue is full
1. Start
2. if size = MAX - 1 return 1
4. else return 0
5. Stop

Algorithm to check if the priority queue is empty
1. Start
2. if size = -1 return 1
3. else return 0
4. Stop

Algorithm to enqueue an element to the priority queue
1. Start
2. if is_full returns 1 then
    2.1 Display "Queue is full"
3. Else
    3.1 Read element
    3.2 Read priority
    3.3 size++
    3.4 Store element and priority in pq[size]
    3.5 Sort the array in ascending order of priority
4. Stop

Algorithm to dequeue an element from the priority queue
1. Start
2. if is_empty returns 1 then
    2.1 Return
3. Else
    3.1 Display "Deleted element is " pq[size].data
    3.2 Decrement size
4. Stop

Algorithm to display the contents of the priority queue
1. Start
2. if is_empty returns 1 then
    2.1 Display "Queue is empty"
3. Else
    3.1 Display "Queue is "
    3.2 for i = 0 to size
        3.2.1 Display pq[i].data and pq[i].priority
4. Stop
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int size = -1;

int is_full();
int is_empty();
void enqueue();
void dequeue();
void display();

struct item 
{
    int data;
    int priority;
}pq[MAX];

int main()
{
    int choice, data, priority;
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
            case 1:
                enqueue();
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

int is_full()
{
    if (size == MAX - 1)
        return 1;
    else
        return 0;
}

int is_empty()
{
    if (size == -1)
        return 1;
    else
        return 0;
}

void enqueue()
{
    if (is_full())
    {
        printf("Queue is full\n");
        return;
    }
    size++;

    printf("Enter data and priority: ");
    scanf("%d %d", &pq[size].data, &pq[size].priority);

    int i, j;
    struct item temp;
    for (i = 0; i <= size; i++)
    {
        for (j = i + 1; j <= size; j++)
        {
            if (pq[i].priority > pq[j].priority)
            {
                temp = pq[i];
                pq[i] = pq[j];
                pq[j] = temp;
            }
        }
    }
}

void dequeue()
{
    if (is_empty())
    {
        return;
    }
    printf("Deleted item is %d\n", pq[size].data);
    size--;
}

void display()
{
    if (is_empty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("\nData\tPriority\n");
    for (int i = 0; i <= size; i++)
    {
        printf("%d\t%d\n", pq[i].data, pq[i].priority);
    }
}