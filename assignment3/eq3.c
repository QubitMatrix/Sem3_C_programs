//write a recursive function to reverse a singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node* link;
};
typedef struct node node;
void reverse_list(node *ptr,node** new)
{
	if(ptr!=NULL)
	{
		node* newnode=malloc(sizeof(node));
		newnode->data=ptr->data;
		newnode->link=NULL;
		if(*new==NULL)
			*new=newnode;
		else
		{
			newnode->link=*new;
			*new=newnode;
		}
		reverse_list(ptr->link,new);
	}
}
int main()
{
	node* s1=calloc(1,sizeof(node));
        s1=NULL;
	node *ds1=s1;
	node *ds1_=s1;
	 printf("Enter the elements in list 1 (-1 to end)");
        int key;
        scanf("%d",&key);
        while(key!=-1)
        {
                node *newnode=malloc(sizeof(node));
                newnode->data=key;
                newnode->link=NULL;
                if(s1==NULL)
                {
                        s1=newnode;
                        ds1=s1;
                        ds1_=s1;
                }
                else
                {
                        ds1->link=newnode;
                        ds1=ds1->link;
                }
                scanf("%d",&key);
        }
	while(ds1_!=NULL)
        {
                printf("%d\n",ds1_->data);
                ds1_=ds1_->link;
        }
	node* s3=malloc(sizeof(node));
	s3=NULL;
	reverse_list(s1,&s3);
	printf("Reversed list\n");
	while(s3!=NULL)
	{
		printf("%d\n",s3->data);
		s3=s3->link;
	}
	return 0;
}

