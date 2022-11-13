#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node* link;
};
typedef struct node node;
node* allocnode(int key)
{
	node* new=malloc(sizeof(node));
	new->key=key;
	new->link=NULL;
	return new;
}
void insert_order(node** head,int key)
{
	node* newnode=allocnode(key);
	if((*head)==NULL)
		*head=newnode;
	else
	{
		node* dhead=(*head);
		node* prev=NULL;
		while(dhead!=NULL && (dhead->key)<key)
		{
			prev=dhead;
			dhead=dhead->link;
		}
		if(prev==NULL)
		{
			newnode->link=dhead;
			(*head)=newnode;
		}
		else
		{
			newnode->link=dhead;
			prev->link=newnode;
		}
	}
}
void display(node* head)
{
	while(head!=NULL)
	{
		printf("%d ",head->key);
		head=head->link;
	}
}
void destroy(node** head)
{
	while(*head!=NULL)
	{
		node* temp=*head;
		*head=(*head)->link;
		free(temp);
	}
}	
int main()
{
	node* head=malloc(sizeof(node));
	head=NULL;
	int key;
	scanf("%d",&key);
	while(key!=-1)
	{
		insert_order(&head,key);		
		scanf("%d",&key);
	}
	display(head);
	destroy(&head);
	printf("Destroyed%p\n",head);
	//head=NULL;
	return 0;
}

