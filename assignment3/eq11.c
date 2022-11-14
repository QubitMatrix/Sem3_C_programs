//consider a sorted doubly linked list with two pointers head and tail pointer, write a c function to find all the pairs form this list which add up to the given value x
#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node* rlink;
	struct node* llink;
};
typedef struct node node;
void find_pairs(node* s1,node* tail,int x)
{
	
	node* ds1=s1;
	node* ds2=tail;
	while(ds1!=NULL)
	{
		while(ds2!=ds1->llink)
		{
			if(ds1->data+ds2->data==x)
				printf("%d %d\n",ds1->data,ds2->data);
			ds2=ds2->llink;
		}
		ds1=ds1->rlink;
		ds2=tail;
	}
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
	node* tail=calloc(1,sizeof(node));
	tail=NULL;
        printf("Enter the elements in list 1 (-1 to end)");
        int key;
        scanf("%d",&key);
        while(key!=-1)
        {
                node *newnode=malloc(sizeof(node));
                newnode->data=key;
                newnode->llink=newnode->rlink=NULL;
                if(s1==NULL)
                {
                        s1=newnode;
                        ds1=s1;
                        ds1_=s1;
                }
                else
                {
			ds1->rlink=newnode;
			newnode->llink=ds1;
                        ds1=ds1->rlink;
                }
                scanf("%d",&key);
        }
	printf("List1:\n");
        while(ds1_!=NULL)
        {
		printf("%d\n",ds1_->data);
		tail=ds1_;
                ds1_=ds1_->rlink;
        }

	int x;
	printf("Value of x\n");
	scanf("%d",&x);
	find_pairs(s1,tail,x);
	return 0;
}

