// write a c function to check if given tree is a bst or not
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node node;
node* createBST()
{
	int key;
	node *root=malloc(sizeof(node));
	scanf("%d",&key);
	root->data=key;
	if(key==-1)
		return NULL;
	else
	{
		printf("Enter left child of %d\n",root->data);
		root->left=createBST();
		root->data=key;
		printf("Enter right child of %d\n",root->data);
		root->right=createBST();
		return root;
	}
}
int inorder(node* root,int *arr)
{
	static int count=0;
	if(root!=NULL)
	{
		count=inorder(root->left,arr);
		printf("%d\n",root->data);
		arr[count++]=root->data;
		count=inorder(root->right,arr);
	}
	return count;
}
int main()
{
	node* root=malloc(sizeof(node));
	root=createBST();
	int* arr=malloc(sizeof(int)*100);
	printf("Inorder\n");
	int count=inorder(root,arr);
	printf("count:%d\n",count);
	int i=0;
	for(i=0;i<count-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			printf("Not bst\n");
			break;
		}
	}
	if(i==count-1)
		printf("Bst\n");
	return 0;
}


		
