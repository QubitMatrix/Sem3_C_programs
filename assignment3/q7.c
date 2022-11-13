#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node* left;
	struct node* right;
};
typedef struct node node;
node* read_tree()
{
	int key;
	node* newnode;
	scanf("%d",&key);
	if(key==-1)
		return NULL;
	else
	{
		newnode=malloc(sizeof(node));
		newnode->key=key;
		printf("Enter the left child of %d\n",newnode->key);
		newnode->left=read_tree();
		printf("Enter the right child of %d\n",newnode->key);
		newnode->right=read_tree();
		return newnode;
	}
}
void display(node *root)
{
	if(root!=NULL)
	{
		display(root->left);
		printf("%d ",root->key);
		display(root->right);
	}
}
int height(node* root)
{
	if(root==NULL)
		return -1;
	else
	{
		int lh=height(root->left);
		int rh=height(root->right);
		//printf("%d %d %d\n",lh,rh,root->key);
		return(1+(lh>rh?lh:rh));//1+lh>rh>lh:rh is wrong
	}
}
int countnodes(node* root,int count)
{
	if(root!=NULL)
	{
		count++;
		count=countnodes(root->left,count);
		count=countnodes(root->right,count);//if count not returned to count then wrong i.e countnodes(...) is wrong
	}
	return count;
}

int main()
{
	node* root=malloc(sizeof(node));
	root=read_tree();
	display(root);
	printf("height:%d\n",height(root));
	int count=0;
	printf("No of nodes:%d\n",countnodes(root,count));
	return 0;
}
