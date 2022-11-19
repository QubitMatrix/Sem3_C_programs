// mirrorify a tree(flip the same tree i.e it should be in same address)
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
void mirrorcopy(node* root)
{
	
	
	/*
	(*copy)=malloc(sizeof(node));	
	(*copy)->data=root->data;
	(*copy)->right=(*copy)->left=NULL;
	*/
	if(root!=NULL)
	{	printf("a%d\n",root->data);
		mirrorcopy(root->left);
		mirrorcopy(root->right);
		node* temp;
		temp=root->left;
		root->left=root->right;
		root->right=temp;
	}
}
int main()
{
	node* root=malloc(sizeof(node));
        node* copy=malloc(sizeof(node));
	root=createBST();
        int* arr=malloc(sizeof(int)*100);
        printf("Inorder\n");
        int count=inorder(root,arr);
        printf("count:%d\n",count);
	printf("%p\n",root);
	mirrorcopy(root);
	printf("%p\n",root);
	inorder(root,arr);
	return 0;
}
	
