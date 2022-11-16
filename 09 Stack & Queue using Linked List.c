// Write a program to implement stack and queue using a linked list.

/*
ALGORITHM

Algorithm for main
1. Start
2. Declare variables
3. Display menu
4. Read choice
5. If choice is push
    5.1. Call push()
    5.2. Display stack
6. Else if choice is pop
    6.1. Call pop()
    6.2. Display stack
7. Else if choice is display stack
    7.1. Call display_stack()
8. Else if choice is enqueue
    8.1. Call enqueue()
    8.2. Display queue
9. Else if choice is dequeue
    9.1. Call dequeue()
    9.2. Display queue
10. Else if choice is display queue
    10.1. Call display_queue()
11. Else if choice is exit
    11.1. Exit
12. Else
    12.1. Display invalid choice
13. Stop

Algorithm for push
1. Start
2. Create a new node
3. Set new node -> data = data
4. Set new node -> next = NULL
5. If stack is empty
    5.1. Set head = new node
6. Else
    6.1. Set new node -> next = head
    6.2. Set head = new node
7. Stop

Algorithm for pop
1. Start
2. If stack is empty
    2.1. Display stack is empty
3. Else
    3.1. Set temp = head
    3.2. Set head = head -> next
    3.3. Free temp
4. Stop

Algorithm for displaying stack
1. Start
2. If stack is empty
    2.1. Display stack is empty
3. Else
    3.1. Set temp = head
    3.2. While temp is not NULL
        3.2.1. Display temp -> data
        3.2.2. Set temp = temp -> next
4. Stop

Algorithm for enqueue
1. Start
2. Create a new node
3. Set new node -> data = data
4. Set new node -> next = NULL
5. If queue is empty
    5.1. Set front = new node
    5.2. Set rear = new node
6. Else
    6.1. Set rear -> next = new node
    6.2. Set rear = new node
7. Stop

Algorithm for dequeue
1. Start
2. If queue is empty
    2.1. Display queue is empty
3. Else
    3.1. Set temp = front
    3.2. Set front = front -> next
    3.3. Free temp
4. Stop

Algorithm for displaying queue
1. Start
2. If queue is empty
    2.1. Display queue is empty
3. Else
    3.1. Set temp = front
    3.2. While temp is not NULL
        3.2.1. Display temp -> data
        3.2.2. Set temp = temp -> next
4. Stop
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head = NULL;
node *front = NULL;
node *rear = NULL;

void push(int data);
void pop();
void enqueue(int data);
void dequeue();
void display_stack();
void display_queue();

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display Stack\n");
        printf("4. Enqueue\n5. Dequeue\n6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            push(data);
            printf("Data pushed successfully\n");
            display_stack();
            break;
        case 2:
            pop();
            printf("Data popped successfully\n");
            display_stack();
            break;
        case 3:
            display_stack();
            break;
        case 4:
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(data);
            printf("Data enqueued successfully\n");
            display_queue();
            break;
        case 5:
            dequeue();
            printf("Data dequeued successfully\n");
            display_queue();
            break;
        case 6:
            display_queue();
            break;
        case 7:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

void push(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void pop()
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        node *temp = head;
        head = head->next;
        free(temp);
    }
}

void enqueue(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    if (front == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        node *temp = front;
        front = front->next;
        free(temp);
    }
}

void display_stack()
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");

    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void display_queue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");

    node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}