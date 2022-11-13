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
void display(node* head,int *count)
{
        while(head!=NULL)
        {
                printf("%d ",head->key);
                (*count)++;//*count++ is wrong
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
void insert_pos(node** head,int key,int pos)
{
	node* newnode=allocnode(key);
	if(pos==1)
	{
		newnode->link=*head;
		*head=newnode;
	}
	else
	{
		int i=1;
		node *prev=NULL;
		node* dhead=*head;
		while(i<pos && dhead!=NULL)
		{
			prev=dhead;
			dhead=dhead->link;
			i++;
		}
		if(i==pos)
		{
			newnode->link=dhead;
			prev->link=newnode;
		}
		else
		{
			printf("invalid position");
		}
	}
}
void delete_alt(node** head)
{
	node* dhead=*head;
	node* temp=NULL;
	while(dhead!=NULL)
	{
		if(temp!=NULL)
		{
			temp->link=dhead->link;	
		}
		temp=dhead->link;
		//printf("%d\n",dhead->key);
		if(dhead==(*head))
		{
			*head=temp;
			free(dhead);
		}
		else
			free(dhead);
		if(temp==NULL)
			dhead=temp;
		else
			dhead=temp->link;
	}
}
int main()
{
	node* head=malloc(sizeof(node));
        head=NULL;
        int key;
	int pos;
	int count=0;
        scanf("%d",&key);
        while(key!=-1)
        {
                scanf("%d",&pos);
		insert_pos(&head,key,pos);
                scanf("%d",&key);
        }
	printf("List:\n");
	display(head,&count);
	printf("No of nodes=%d\n",count);
	count=0;
	delete_alt(&head);
	printf("\nAfter deleting alternate\n");
	display(head,&count);
	printf("No of nodes=%d\n",count);
	count=0;
	destroy(&head);
	printf("\nDestroyed\n");
	return 0;
}
