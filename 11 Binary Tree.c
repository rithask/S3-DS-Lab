// Binary tree creation and traversals for a given expression

/*
ALGORITHM

1. Start
2. Read the expression
3. Create a root node with the first character of the expression
4. Build the expression tree
5. Display a menu
6. Read the choice
7. If the choice is inorder
	7.1 Display the inorder traversal
8. Else if the choice is preorder
	8.1 Display the preorder traversal
9. Else if the choice is postorder
	9.1 Display the postorder traversal
10. Else if the choice is exit
	10.1 Exit the program
11. Else
	11.1 Display "Invalid choice"
12. Repeat from step 5
13. Stop

Algorithm for creating a node
1. Start
2. Create a new node
3. Set the data of the new node to the character
4. Set the left child of the new node to NULL
5. Set the right child of the new node to NULL
6. Return the new node

Algorithm for building the expression tree
1. Start
2. Create a stack
3. Set the top of the stack to -1
4. For each character in the expression
	4.1 If the character is an operand
		4.1.1 Create a new node with the character as the data
		4.1.2 Push the new node onto the stack
	4.2 Else
		4.2.1 Create a new node with the character as the data
		4.2.2 Set the right child of the new node to the top of the stack
		4.2.3 Pop the top of the stack
		4.2.4 Set the left child of the new node to the top of the stack
		4.2.5 Pop the top of the stack
		4.2.6 Push the new node onto the stack
5. Return the top of the stack
6. Stop

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
#include <ctype.h>

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
node* build_expression_tree(char postfix[]);

int main()
{
	int choice;
	char exp[20];
	printf("Enter the expression: ");
	scanf("%s", exp);
	node *root = build_expression_tree(exp);

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

node* build_expression_tree(char postfix[])
{
	node *stack[100];
	int top = -1;

	for (int i = 0; i < strlen(postfix); i++)
	{
    	// If the character is an operand, create a new tree node and push it onto the stack
    	if (isalnum(postfix[i]))
		{
			stack[++top] = create(postfix[i]);
    	}
		else 
		{
			// If the character is an operator, pop two operands from the stack, create a new tree node
			// with the operator as its data, and set the left and right children to the operands.
			// Then push the new tree node back onto the stack.
			node *node = create(postfix[i]);
			node->right = stack[top--];
			node->left = stack[top--];
			stack[++top] = node;
		}
    }

	// The final node on the stack is the root of the expression tree
	return stack[top];
}