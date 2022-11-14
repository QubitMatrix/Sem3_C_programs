// a single listis used to represent a long integer, ur given two long integer in linked lists(front insertion), write a c function to return the product of these two as a linked list(sum=sum*10+digit)
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
typedef struct node node;
long int multiply(node *s1,node* s2)
{
	int sum1,sum2;
	sum1=sum2=0;
	while(s1!=NULL)
	{
		sum1=sum1*10+s1->data;
		s1=s1->link;
	}
	while(s2!=NULL)
	{
		sum2=sum2*10+s2->data;
		s2=s2->link;
	}
	printf("%d %d\n",sum1,sum2);
	return sum1*sum2;

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
	long int x=multiply(s1,s2);
	printf("%lu\n",x);
	return 0;
}
