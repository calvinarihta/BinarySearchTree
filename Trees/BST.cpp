#include <stdio.h>
#include <malloc.h>

struct node {
	int value;
	struct node *left, *right;
};

struct node *createNode(int value)
{
	struct node *newNode = (struct node*)malloc( sizeof(struct node) );
	newNode -> value = value;
	newNode -> left = newNode -> right = NULL;
	return newNode;
}

struct node *insert( struct node *node, int value )
{
	if( node == NULL )
		return createNode( value );
		
	value < node -> value ? 
	node -> left = insert( node -> left, value ) : 
	node -> right = insert( node -> right, value ); 

	return node;
}

void printAll( struct node *root )
{
	if ( root == NULL )
		return;
	
	// Inorder
	printAll( root -> left );
	printf("%d -> ", root -> value );
	printAll( root -> right );
}

void searchNode( struct node *node, int value )
{
	if ( node == NULL )
	{
		printf("Value not found!\n");
		return;
	}
	
	if ( node -> value == value )
		printf("Value found!\n");
	
	if ( value < node -> value )
		searchNode( node -> left, value );
		
	else if ( value > node -> value  )
		searchNode( node -> right, value ); 
}

int main() {
	
	int input;
	struct node *root = NULL;
	
	root = insert( root, 105 );
	insert( root, 50 );
	insert( root, 40 );
	insert( root, 20 );
	insert( root, 100 );
	insert( root, 200 );
	
	printAll( root );
	
	printf("\n\n");
	printf("Insert value to be searched : ");
	
	scanf("%d", &input); 
	getchar();
	searchNode( root, input );
	getchar();
	
	return 0;
}
