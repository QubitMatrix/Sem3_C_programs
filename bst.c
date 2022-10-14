#include<stdio.h>
#include<stdlib.h>
struct tnode
{
	struct tnode* left;
	int data;
	struct tnode* right;
};
typedef struct tnode tnode;
void createBST(tnode*,int);
void inorder(tnode* root);
tnode* inp()
{
	tnode *root=malloc(sizeof(tnode));
	scanf("%d",&(root->data));
	root->left=NULL;
	root->right=NULL;
	while(1)
	{
		int ele;
		scanf("%d",&ele);
		if(ele==-1)
			break;
		createBST(root,ele);
		//printf("aa\n");
	//inorder(root);
	//printf("bb\n");
	}
	
	return root;
}

void createBST(tnode *root,int ele)
{
	tnode* newnode=malloc(sizeof(tnode));
	//printf("a%d\n",root->data);
	if(ele<root->data)
	{
		if(root->left!=NULL)
			createBST(root->left,ele);
		else
		{
			//printf("x%d\n",root->data);
			newnode->left=newnode->right=NULL;
			newnode->data=ele;
			root->left=newnode;
		}
	}
	else if(ele>root->data)
	{
		if(root->right!=NULL)
			createBST(root->right,ele);
		else//without else it gets excuted for each iteration therefore newnode added to main root at the end of function      
		{
			//printf("xx%d\n",root->data);
		        newnode->left=newnode->right=NULL;
			newnode->data=ele;
		 	root->right=newnode;
		}
	}
	
}
void inorder(tnode* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->data);//(*root).data
		inorder(root->right);
	}
}
void delete(tnode **root,int key)
{
	tnode* prev;
	tnode* replacement;
	prev=NULL;
	tnode* droot;
	droot=*root;
	//printf("a");

	while(droot!=NULL)
	{

		
		if(key<(droot)->data)
		{
			prev=droot;
			droot=(droot)->left;
		}
		else if(key>(droot)->data)
		{
			prev=droot;
			droot=(droot)->right;
		}
		else//if(key==(droot)->data)
		{	
			break;
		}
	}
	if(droot==NULL)
		printf("Missing key");
	else
	{
		if(droot->left==NULL && droot->right==NULL)
		{
			replacement=NULL;
		}
		else if(droot->left==NULL && droot->right!=NULL)
		{
			replacement=droot->right;
		}
		else if(droot->right==NULL && droot->left!=NULL)
		{
			replacement=droot->left;
		}
		else
		{
			tnode* temp;
			temp=droot->right;
			while(temp->left!=NULL)
			{
				temp=temp->left;
			}
			temp->left=droot->left;
			replacement=droot->right;
		}
		if(prev==NULL)
		{
			*root=replacement;
			free(droot);
		}
		else if(droot->data>prev->data)
		{
			prev->right=replacement;
	                free(droot);
		}
		else if(droot->data<prev->data)
		{
			prev->left=replacement;
	        	free(droot);
		}
		//printf("%d,%p\n",droot->data,droot);
		//free(droot);
		//droot=NULL;
		//printf("%p",prev);
	}
}

int main()
{
	tnode* root;
	printf("Enter the elements\n");
	root=inp();
	printf("Tree:\n");
	inorder(root);
	//tnode *ptr;
	//ptr=&root;
	int del;
	printf("Enter element to delete");
	scanf("%d",&del);
	delete(&root,del);
	printf("Tree after deletion:\n");
	inorder(root);
	return 0;
}

