// write a function to merge two singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node* link;
};
typedef struct node node;
node* merge_list(node* s1,node* s2)
{
	node* s3=malloc(sizeof(node));
	s3=NULL;
	node* ds3=s3;
	
	while(s1!=NULL && s2!=NULL)
	{
		node* newnode=malloc(sizeof(node));
		if(s1->data<s2->data)
		{
			newnode->data=s1->data;
			newnode->link=NULL;
			if(s3==NULL)
			{
				s3=newnode;
				ds3=s3;
			}
			else
			{
				ds3->link=newnode;
				ds3=ds3->link;
			}
			s1=s1->link;
		}
		else
		{
			newnode->data=s2->data;
			newnode->link=NULL;
			if(s3==NULL)
			{
				s3=newnode;
				ds3=s3;
			}
			else
			{
				ds3->link=newnode;
				ds3=ds3->link;
			}
			s2=s2->link;
		}
	}
	while(s1!=NULL)
	{
		node* newnode=malloc(sizeof(node));
		newnode->data=s1->data;
		newnode->link=NULL;
		if(s3==NULL)
		{
			s3=newnode;
			ds3=s3;
		}
		else
		{
			ds3->link=newnode;
			ds3=ds3->link;
		}
		s1=s1->link;
	}
	while(s2!=NULL)
	{
		node* newnode=malloc(sizeof(node));
		newnode->data=s2->data;
		newnode->link=NULL;
		if(s3==NULL)
		{
			s3=newnode;
			ds3=s3;
		}
		else
		{
			ds3->link=newnode;
			ds3=ds3->link;
		}
		s2=s2->link;
	}
	return s3;
}
int main()
{
        node* s1=calloc(1,sizeof(node));
        s1=NULL;
        node* s2=calloc(1,sizeof(node));
        s2=NULL;
        node *ds1=s1;
        node *ds2=s2;
        node *ds1_=s1;
        node* ds2_=s2;
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
        printf("Enter the elements in list 2(-1 to end");
        scanf("%d",&key);
        while(key!=-1)
        {
                node *newnode=malloc(sizeof(node));
                newnode->data=key;
                newnode->link=NULL;
                if(s2==NULL)
                {
                        s2=newnode;
                        ds2=s2;
                        ds2_=s2;
                }
                else
                {
                        ds2->link=newnode;
                         ds2=ds2->link;
                }
                scanf("%d",&key);
        }
        while(ds1_!=NULL)
        {
                printf("%d\n",ds1_->data);
                ds1_=ds1_->link;
		 }
        while(ds2_!=NULL)
        {
                printf("%d\n",ds2_->data);
                ds2_=ds2_->link;
        }
	node* merge1=merge_list(s1,s2);
	printf("Merged list\n");
	while(merge1!=NULL)
	{
		printf("%d\n",merge1->data);
		merge1=merge1->link;
	}
	return 0;
}
