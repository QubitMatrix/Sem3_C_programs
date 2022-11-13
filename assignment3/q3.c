#include<stdio.h>
#include<stdlib.h>
struct node
{
        int key;
        struct node* llink;
	struct node* rlink;
};
typedef struct node node;
node* allocnode(int key)
{
        node* new=malloc(sizeof(node));
        new->key=key;
        new->llink=new->rlink=NULL;
        return new;
}
void display(node* head,int *count)
{
        while(head!=NULL)
        {
                printf("%d ",head->key);
                (*count)++;//*count++ is wrong
		head=head->rlink;
        }
}
void destroy(node** head)
{
        while(*head!=NULL)
        {
                node* temp=*head;
                *head=(*head)->rlink;
                free(temp);
        }
}
void insert_pos(node** head,int key,int pos)
{
	node* newnode=allocnode(key);
	if(pos==1)
	{
		newnode->rlink=*head;
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
			dhead=dhead->rlink;
			i++;
		}
		if(i==pos)
		{
			newnode->rlink=dhead;
			if(dhead!=NULL)
				dhead->llink=newnode;
			newnode->llink=prev;
			prev->rlink=newnode;
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
			temp->rlink=dhead->rlink;
			if(dhead->rlink!=NULL)
				dhead->rlink->llink=temp;
		}
		temp=dhead->rlink;
		//printf("%d\n",dhead->key);
		if(dhead==(*head))
		{
			temp->llink=NULL;
			*head=temp;
			free(dhead);
		}
		else
			free(dhead);
		if(temp==NULL)
			dhead=temp;
		else
			dhead=temp->rlink;
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
