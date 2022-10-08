#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct tnode
{
	struct tnode *left;
	int data;
	int level;
	struct tnode* right;
};
typedef struct tnode tnode;
struct queue
{
	int front;
	int rear;
	tnode **ptr_s;//even with single can work
	int size;
};
typedef struct queue queue;
void create_queue(queue * ptr_Q)
{
	ptr_Q->front=-1;
	ptr_Q->rear=-1;
	ptr_Q->ptr_s=malloc(sizeof(tnode*)*ptr_Q->size);
}
void insertQ(queue *ptr_Q,tnode *ele)
{
	if(ptr_Q->rear!=ptr_Q->size-1)//queue is not full
	{
		ptr_Q->rear+=1;
		
		ptr_Q->ptr_s[ptr_Q->rear]=ele;
		if(ptr_Q->front==-1)
		{
			ptr_Q->front+=1;	
		}
	}
	else
		printf("Queue full\n");
}
int deleteQ(queue *ptr_Q)
{
	static int count=1;
	tnode* ele;
	if(ptr_Q->front==-1)//reseting option
		return -999;
	else
	{
		ele=ptr_Q->ptr_s[ptr_Q->front];
		ptr_Q->front=ptr_Q->front+1;
		if(ptr_Q->front==ptr_Q->rear+1)//last element deletion
			ptr_Q->front=ptr_Q->rear=-1;
		printf("Level:%d Data:%d\n",ele->level,ele->data);
		if(ele->left!=NULL)
		{
			(ele->left)->level=ele->level+1;
			insertQ(ptr_Q,ele->left);
		}
		if(ele->right!=NULL)
		{
			(ele->right)->level=ele->level+1;
			insertQ(ptr_Q,ele->right);
		}
		deleteQ(ptr_Q);
		return 1;
	}
}

tnode* createBT()
{
	int ele;
	tnode* newnode;
scanf("%d",&ele);
	if(ele==-1)
		return NULL;
	else
	{
		newnode=malloc(sizeof(tnode));
		newnode->data=ele;
		newnode->level=0;
		printf("Enter the left child of %d:",newnode->data);
		newnode->left=createBT();
		printf("Enter the right child of %d:",newnode->data);
		newnode->right=createBT();
		return newnode;
	}
}

int count(tnode* root)
{
	static int nodes=0;
	if(root!=NULL)
	{
		nodes+=1;
		count(root->left);
		count(root->right);
	}
	return nodes;
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
void preorder(tnode* root)
{
	if(root!=NULL)
	{
		printf("%d\n",root->data);
		preorder(root->left);
		preorder(root->right);
	}

}
void postorder(tnode* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\n",root->data);
	}
}
void levelorder(tnode* root)
{
	if(root!=NULL)
	{
		queue Q;
		Q.size=100;
		create_queue(&Q);
		insertQ(&Q,root);
		deleteQ(&Q);
	}
	/*while(Q.front!=-1)
	{
		newnode=deleteQ(&Q);
		printf("%d",newnode.data);
		insertQ(&Q,*(newnode.left));
		insertQ(&Q,*(newnode.right));
	}
	*/	
	//display(Q);
}
void destroy(tnode* root)
{
	if(root!=NULL)
	{
		destroy(root->left);
		destroy(root->right);
		free(root);
	}
}
int main()
{
	tnode* root;
	root=NULL;
	printf("Enter the root element:");
	root=createBT();
	int choice;
	printf("Enter 1.for preorder \n2. for inorder\n3. for postorder \n4. for level order\n5.to count number of nodes in tree\n6. to destroy tree\n7. exit\n");
       	if(root==NULL)
	{
		printf("Empty tree");
		exit(1);
	}
	while(1)
	{
	int nodes;
	printf("Enter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("Preorder traversal:\n");
		       preorder(root);
		       break;
		case 2:printf("Inorder traversal:\n");
		       inorder(root);
		       break;
		case 3:printf("Postorder traversal:\n");
		       postorder(root);
		       break;
		case 4:printf("Level order traversal:\n");
		       levelorder(root);
		       break;
		case 5:if(root==NULL)
			       nodes=0;
		       else
			       nodes=count(root);
		       printf("Number of nodes=%d\n",nodes);
		       break;
		case 6:destroy(root);
		       root=NULL;
		       break;
		case 7:exit(0);

		default:printf("Wrong Choice");
	}
	}
	return 0;
}

	
