/*
Write a menu driven program for performing the following operations on a Linked List:
    Display
    Insert at Beginning
    Insert at End
    Insert at a specified Position 12.5.Delete from Beginning 12.6.Delete from End
    Delete from a specified Position
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void display(node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node *insert_at_beginning(node *head, int data)
{
    node *new_node = create_node(data);
    if(head == NULL)
        return new_node;
    new_node->next = head;
    return new_node;
}

node *insert_at_end(node *head, int data)
{
    node *new_node = create_node(data);
    if(head == NULL)
        return new_node;
    node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    return head;
}

node *insert_at_position(node *head, int data, int pos)
{
    node *new_node = create_node(data);
    if(head == NULL)
        return new_node;
    if(pos == 1)
    {
        new_node->next = head;
        return new_node;
    }
    node *temp = head;
    for(int i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;
    if(temp == NULL)
    {
        printf("Invalid position\n");
        return head;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

node *delete_from_beginning(node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

node *delete_from_end(node *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }
    node *temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
    return head;
}

node *delete_from_position(node *head, int pos)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return NULL;
    }
    if(pos == 1)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    node *temp = head;
    for(int i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;
    if(temp == NULL || temp->next == NULL)
    {
        printf("Invalid position\n");
        return head;
    }
    node *temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);
    return head;
}

int main()
{
    node *head = NULL;
    int choice, data, pos;
    while(1)
    {
        printf("1. Display\n2. Insert at Beginning\n3. Insert at End\n");
        printf("4. Insert at a specified Position\n5. Delete from Beginning\n");
        printf("6. Delete from End\n7. Delete from a specified Position\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice)
        {
            case 1:
                display(head);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insert_at_beginning(head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insert_at_end(head, data);
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insert_at_position(head, data, pos);
                break;
            case 5:
                head = delete_from_beginning(head);
                break;
            case 6:
                head = delete_from_end(head);
                break;
            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = delete_from_position(head, pos);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
        printf("\n");
    }
    return 0;
}
