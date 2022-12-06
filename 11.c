// Binary tree creation and traversals for a given expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *create(char data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int main()
{
    // display menu
    int choice;
    char exp[20];
    printf("Enter the expression: ");
    scanf("%s", exp);
    struct node *root = create(exp[0]);
    struct node *temp = root;
    for (int i = 1; i < strlen(exp); i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            temp->left = create(exp[i]);
            temp = temp->left;
        }
        else
        {
            temp->right = create(exp[i]);
            temp = temp->right;
        }
    }
    while(1)
    {
        printf("1. Inorder traversal\n2. Preorder traversal\n3. Postorder traversal\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}