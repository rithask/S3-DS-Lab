// Binary tree creation and traversals for a given expression

/*
ALGORITHM

1. Start
2. Read the expression
3. Create a root node with the first character of the expression
4. Create a temporary node and assign it to the root node
5. Traverse the expression from the second character
6. If the character is an operator, create a new node with the character and assign it to the left child of the temporary node
7. If the character is an operand, create a new node with the character and assign it to the right child of the temporary node
8. Repeat steps 5 to 7 until the end of the expression
9. Display the menu
10. Read the choice
11. If the choice is inorder traversal
	11.1 call the inorder function
12. Else if the choice is preorder traversal
	12.1 call the preorder function
13. Else if the choice is postorder traversal
	13.1 call the postorder function
14. Else if the choice is exit
	14.1 exit the program
15. Else
	15.1 display invalid choice
16. Repeat steps 9 to 15 until the choice is exit
17. Stop

Algorithm for creating a node
1. Start
2. Create a new node
3. Set the data of the new node to the character
4. Set the left child of the new node to NULL
5. Set the right child of the new node to NULL
6. Return the new node

Algorithm for inorder traversal
1. Start
2. if the root node is NULL
	2.1 return
3. call the inorder function and pass the left child of the root node as the argument
4. display the data of the root node
5. call the inorder function and pass the right child of the root node as the argument
6. Stop

Algorithm for preorder traversal
1. Start
2. If the root node is NULL
	2.1 return
3. display the data of the root node
4. call the preorder function and pass the left child of the root node as the argument
5. call the preorder function and pass the right child of the root node as the argument
6. Stop

Algorithm for postorder traversal
1. Start
2. If the root node is NULL
	2.1 return
3. call the postorder function and pass the left child of the root node as the argument
4. call the postorder function and pass the right child of the root node as the argument
5. display the data of the root node
6. Stop
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char data;
	struct node *left;
	struct node *right;
}node;

node *create(char data);
void inorder(node *root);
void preorder(node *root);
void postorder(node *root);


int main()
{
	int choice;
	char exp[20];
	printf("Enter the expression: ");
	scanf("%s", exp);
	node *root = create(exp[0]);
	node *temp = root;
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
		printf("\n");

		switch(choice)
		{
			case 1:
				printf("Inorder traversal: ");
				inorder(root);
				printf("\n\n");
				break;
			case 2:
				printf("Preorder traversal: ");
				preorder(root);
				printf("\n\n");
				break;
			case 3:
				printf("Postorder traversal: ");
				postorder(root);
				printf("\n\n");
				break;
			case 4:
				printf("Exiting...\n");
				exit(0);
			default:
				printf("Invalid choice\n");
		}
	}
}

node *create(char data)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void inorder(node *root)
{
	if (root == NULL) return;

	inorder(root->left);
	printf("%c ", root->data);
	inorder(root->right);
}

void preorder(node *root)
{
	if (root == NULL) return;

	printf("%c ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(node *root)
{
	if (root == NULL) return;

	postorder(root->left);
	postorder(root->right);
	printf("%c ", root->data);
}