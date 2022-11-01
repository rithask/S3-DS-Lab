/*
Implement a Double-Ended Queue (DEQUEUE) with the operations
    Insert elements to the Front of the queue.
    Insert elements to the Rear of the queue
    Delete elements from the Front of the queue.
    Delete elements from the Rear of the queue.
    Display the queue after each operation.
*/

/*
ALGORITHM

Global Declarations:
    dq array of size 10
    front = -1
    rear = -1

is_full function
1. Start
2. if front = 0 and rear = MAX - 1 or front = rear + 1 return 1
4. else return 0
5. Stop

is_empty function
1. Start
2. if front = -1 return 1
4. else return 0
5. Stop

insert_front function
1. Start
2. if is_full returns 1 then
    2.1 Display "Queue is full"
3. Else
    3.1 if front = -1 then
        3.1.1 Set front = 0
        3.1.2 Set rear = 0
    3.2 Else if front = 0 then
        3.2.1 Set front = MAX - 1
    3.3 Else
        3.3.1 Decrement front
    3.4 Set dq[front] = data
4. Stop

insert_rear function
1. Start
2. if is_full returns 1 then
    2.1 Display "Queue is full"
3. Else
    3.1 if front = -1 then
        3.1.1 Set front = 0
        3.1.2 Set rear = 0
    3.2 Else if rear = MAX - 1 then
        3.2.1 Set rear = 0
    3.3 Else
        3.3.1 Increment rear
    3.4 Set dq[rear] = data
4. Stop

delete_front function
1. Start
2. if is_empty returns 1 then
    2.1 Display "Queue is empty"
3. Else
    3.1 Display "Deleted element is " dq[front]
    3.2 if front = rear then
        3.2.1 Set front = -1
        3.2.2 Set rear = -1
    3.3 Else if front = MAX - 1 then
        3.3.1 Set front = 0
    3.4 Else
        3.4.1 Increment front
4. Stop

delete_rear function
1. Start
2. if is_empty returns 1 then
    2.1 Display "Queue is empty"
3. Else
    3.1 Display "Deleted element is " dq[rear]
    3.2 if front = rear then
        3.2.1 Set front = -1
        3.2.2 Set rear = -1
    3.3 Else if rear = 0 then
        3.3.1 Set rear = MAX - 1
    3.4 Else
        3.4.1 Decrement rear
4. Stop

display function
1. Start
2. if is_empty returns 1 then
    2.1 Display "Queue is empty"
3. Else
    3.1 Display "Queue is "
    3.2 if front <= rear then
        3.2.1 for i = front to rear
            3.2.1.1 Display dq[i]
    3.3 Else
        3.3.1 for i = front to MAX - 1
            3.3.1.1 Display dq[i]
        3.3.2 for i = 0 to rear
            3.3.2.1 Display dq[i]
4. Stop

main function
1. Start
2. Declare choice, data
3. Display a menu
    3.1 Insert element to the front
    3.2 Insert element to the rear
    3.3 Delete element from the front
    3.4 Delete element from the rear
    3.5 Display the queue
    3.6 Exit
4. Repeat until choice = 6
    4.1 Read choice
    4.2 if choice = 1 then
        4.2.1 Read data
        4.2.2 Call insert_front function
        4.2.3 Call display function
    4.3 Else if choice = 2 then
        4.3.1 Read data
        4.3.2 Call insert_rear function
        4.3.3 Call display function
    4.4 Else if choice = 3 then
        4.4.1 Call delete_front function
        4.4.2 Call display function
    4.5 Else if choice = 4 then
        4.5.1 Call delete_rear function
        4.5.2 Call display function
    4.6 Else if choice = 5 then
        4.6.1 Call display function
5. Stop
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int dq[MAX];
int front = -1;
int rear = -1;

int is_full();
int is_empty();
void insert_front(int data);
void insert_rear(int data);
void delete_front();
void delete_rear();
void display();

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Insert element to the front\n2. Insert element to the rear\n");
        printf("3. Delete element from the front\n4. Delete element from the rear\n");
        printf("5. Display the queue\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                insert_front(data);
                display();
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                insert_rear(data);
                display();
                break;
            case 3:
                delete_front();
                display();
                break;
            case 4:
                delete_rear();
                display();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}

int is_full()
{
    if (front == 0 && rear == MAX - 1 || front == rear + 1)
        return 1;
    else
        return 0;
}

int is_empty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

void insert_front(int data)
{
    if (is_full())
        printf("Queue is full\n");
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0)
            front = MAX - 1;
        else
            front--;
        dq[front] = data;
    }
}

void insert_rear(int data)
{
    if (is_full())
        printf("Queue is full\n");
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else if (rear == MAX - 1)
            rear = 0;
        else
            rear++;
        dq[rear] = data;
    }
}

void delete_front()
{
    if (is_empty())
        printf("Queue is empty\n");
    else
    {
        printf("Deleted element is %d\n", dq[front]);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
}

void delete_rear()
{
    if (is_empty())
        printf("Queue is empty\n");
    else
    {
        printf("Deleted element is %d\n", dq[rear]);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
            rear = MAX - 1;
        else
            rear--;
    }
}

void display()
{
    int i;
    if (is_empty())
        printf("Queue is empty\n");
    else
    {
        printf("\nQueue is\n");
        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
                printf("%d ", dq[i]);
        }
        else
        {
            for (i = front; i <= MAX - 1; i++)
                printf("%d ", dq[i]);
            for (i = 0; i <= rear; i++)
                printf("%d ", dq[i]);
        }
        printf("\n");
    }
}