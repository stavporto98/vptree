#include <stdlib.h>
#include <stdio.h>


int counter = 0;



typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} node;

node *create(int x)
{
	node *p;

    p=(node*)malloc(sizeof(node));
    p->data=x;
	int half  = (int)(x/2);
    if(half==0)
    	return NULL;
	p->left=create(half);
	p->right=create(x-half);

	return p;
}

void preorder(node *t)		//address of root node is passed in t
{
	if(t!=NULL)
	{
		printf("\n%d",t->data);		//visit the root
		preorder(t->left);		//preorder traversal on left subtree
		preorder(t->right);		//preorder traversal om right subtree
	}
  else{
    printf("\n");
  }
}


int main()
{

  printf("Enter data(-1 for no data):");
  int x;
	scanf("%d", &x);

  node *root;
	root=create(x);
	printf("\nThe preorder traversal of tree is:\n");
	preorder(root);

	return 0;
}
