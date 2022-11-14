//consider the given figure which consists of two sorted linked list pointed byy start1 and start2. The nde wuth address 3k represents the intersection point.(check which point both point to same address)
#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node* link;
};
typedef struct node node;
node* merge_point(node* s1,node* s2)
{
	node* ds2=malloc(sizeof(node));
	ds2=s2;
	while(s1!=NULL)
	{
		while(ds2!=NULL)
		{
			if(s1==ds2)
				return s1;
			ds2=ds2->link;
		}
		ds2=s2;
		s1=s1->link;
	}
	return NULL;
}
node* search(node* ptr,int key)
{
	int count=0;
	while(ptr!=NULL)
	{
		if(ptr->data==key)
		{
			printf("Count in list1:%d\n",count);
			return ptr;
		}
		count++;
		ptr=ptr->link;
	}
	return NULL;
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
	int merged;
	printf("Enter 1 if to be merge point\n");
	scanf("%d",&merged);
	int count=0;
        while(key!=-1)
        {
                node *newnode=malloc(sizeof(node));
                newnode->data=key;
                newnode->link=NULL;
		if(merged==1)
		{
			node* point=search(ds1_,key);
			if(point==NULL)
				printf("Cannot be merged\n");
			else
			{
				newnode->link=point;
			}
		}
                if(s2==NULL)
                {
                        count++;
			s2=newnode;
                        ds2=s2;
                        ds2_=s2;
                }
                else
                {
                        count++;
			ds2->link=newnode;
                         ds2=ds2->link;
                }
		if(merged==1)
		{
			printf("Count in list2:%d\n",count-1);
			break;
		}
                scanf("%d",&key);
		scanf("%d",&merged);
        }
	printf("1st list\n");
        while(ds1_!=NULL)
        {
                printf("%d\n",ds1_->data);
                ds1_=ds1_->link;
	}
	printf("2nd list\n");
        while(ds2_!=NULL)
        {
                printf("%d\n",ds2_->data);
                ds2_=ds2_->link;
        }
	node* mergepoint=merge_point(s1,s2);
	if(mergepoint==NULL)
		printf("No merge\n");
	else
	{
		printf("Merge at %d %p\n",mergepoint->data,mergepoint);
		printf("Elements common after merge point\n");
		while(mergepoint!=NULL)
		{
			printf("%d ",mergepoint->data);
			mergepoint=mergepoint->link;
		}
	}
	printf("\n");
	return 0;
}
