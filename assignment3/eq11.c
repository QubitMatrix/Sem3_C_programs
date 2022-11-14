#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node* rlink;
	struct node* llink;
};
typedef struct node node;
void find_pairs(node* s1,node* s2,int x)
{
	
	node*ds2=s2;
	while(s1!=NULL)
	{
		while(ds2!=NULL)
		{
			if(s1->data+ds2->data==x)
				printf("%d %d\n",s1->data,ds2->data);
			ds2=ds2->rlink;
		}
		s1=s1->rlink;
		ds2=s2;
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
        printf("Enter the elements in list 2(-1 to end");
        scanf("%d",&key);
        while(key!=-1)
        {
                node *newnode=malloc(sizeof(node));
                newnode->data=key;
                newnode->rlink=newnode->llink=NULL;
                if(s2==NULL)
                {
                        s2=newnode;
                        ds2=s2;
                        ds2_=s2;
                }
                else
                {
                        ds2->rlink=newnode;
			newnode->llink=ds2;
                         ds2=ds2->rlink;
                }
                scanf("%d",&key);
        }
	printf("List1:\n");
        while(ds1_!=NULL)
        {
		printf("%d\n",ds1_->data);
                ds1_=ds1_->rlink;
        }
	printf("List2:\n");
        while(ds2_!=NULL)
        {
                printf("%d\n",ds2_->data);
                ds2_=ds2_->rlink;
        }
	int x;
	printf("Valus of x\n");
	scanf("%d",&x);
	find_pairs(s1,s2,x);
	return 0;
}

