/*
Implement a Priority Queue using arrays with the operations
    Insert elements to the Priority Queue.
    Delete elements from the Priority Queue.
    Display the contents of the Priority Queue after each operation.
*/

/*
ALGORITHM

Global Declarations:
    pq array of size 10
    size = -1

is_full function
1. Start
2. if size = MAX - 1 return 1
4. else return 0
5. Stop

is_empty function
1. Start
2. if size = -1 return 1
4. else return 0
5. Stop

enqueue function
1. Start
2. if is_full returns 1 then
    2.1 Display "Queue is full"
3. Else
    3.1 Increment size
    3.2 Set pq[size].data = data
    3.3 Set pq[size].priority = priority
    3.4 Sort the queue using priority
4. Stop

dequeue function
1. Start
2. if is_empty returns 1 then
    2.1 Display "Queue is empty"
3. Else
    3.1 Display "Deleted element is " pq[size].data
    3.2 Decrement size
4. Stop

display function
1. Start
2. if is_empty returns 1 then
    2.1 Display "Queue is empty"
3. Else
    3.1 Display "Queue is "
    3.2 for i = 0 to size
        3.2.1 Display pq[i].data and pq[i].priority
4. Stop

Main function
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
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct item pq[MAX];
int size = -1;

int is_full();
int is_empty();
void enqueue(int data, int priority);
void dequeue();
void display();

struct item 
{
    int data;
    int priority;
};

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
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &priority);
                enqueue(data, priority);
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

void enqueue(int data, int priority)
{
    if (is_full())
    {
        printf("Queue is full\n");
        return;
    }
    size++;
    pq[size].data = data;
    pq[size].priority = priority;

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
        printf("Queue is empty\n");
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
