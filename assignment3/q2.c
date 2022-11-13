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
               {
		       printf("a\n");
		       *head=newnode;
	       }
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
void reverse(node** head)
{
	node *dhead=*head;
	node* prev=malloc(sizeof(node));
	prev=NULL;
	node* temp;
	while(dhead!=NULL)
	{
		temp=dhead->link;
		dhead->link=prev;
	//printf("%p\n",prev);
	
		prev=dhead;
		dhead=temp;
	}
	//printf("%d",prev->key);
	*head=prev;
}

int main()
{
	int key;
	node* head=malloc(sizeof(node));
	head=NULL;//without this extra 0 added
	scanf("%d",&key);
	while(key!=-1)
	{
		insert_order(&head,key);
		scanf("%d",&key);
	}
	//printf("%d",(head)->link->key);
	reverse(&head);
	display(head);
	destroy(&head);
	printf("Destroyed\n");
	return 0;
}
