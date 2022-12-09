#include<stdio.h>
#include<stdlib.h>
struct node
{
    int coefficient;
    int exp;
    struct node *link;
};
typedef struct node polynode;
struct list
{
    polynode* head;
};
typedef struct list list;
void attachnode(list *poly,polynode* newnode)
{
    if(!(poly->head))
            poly->head=newnode;
            else
            {
            	polynode* temp;
            	temp=poly->head;
            	while(temp->link!=NULL)
            	{
            		temp=temp->link;
            	}
            	temp->link=newnode;
            }
}
void readpoly(list *poly)
{
    int c,e;
    polynode *newnode;
    while(1)
    {
        scanf("%d %d",&c,&e);
        if(c==-1 && e==-1)
        break;
        else
        {
            
            newnode=malloc(sizeof(polynode));
            newnode->coefficient=c;
            newnode->exp=e;
            newnode->link=NULL;
            attachnode(poly,newnode);         
        }
        
        
    }
    
}
void display(list poly)
{
    while(poly.head!=NULL)
    {
        printf("%d %d\n",poly.head->coefficient,poly.head->exp);
        poly.head=poly.head->link;
    }
}
int compare(int a,int b)
{   
    //printf("a%d %d\n",a,b);
    if(a==b)
    return 0;
    if(a>b)
    return 1;
    else
    return -1;
}
list addpoly(list polya,list polyb)
{
    list poly;
    poly.head=NULL;
    polynode* head1;
    polynode *head2;
    head1=polya.head;
    head2=polyb.head;
    while(head1!=NULL && head2!=NULL)
    {
        polynode* newnode;
        switch(compare(head1->exp,head2->exp))
        {
            case 1:
            newnode=malloc(sizeof(polynode));
            newnode->coefficient=head1->coefficient;
            newnode->exp=head1->exp;
            newnode->link=NULL;
            attachnode(&poly,newnode);
            head1=head1->link;
            break;
            case -1:
            newnode=malloc(sizeof(polynode));
            newnode->coefficient=head2->coefficient;
            newnode->exp=head2->exp;
            newnode->link=NULL;
            attachnode(&poly,newnode);
            head2=head2->link;
            break;
            case 0:
            if(head1->coefficient+head2->coefficient)
            {newnode=malloc(sizeof(polynode));
            newnode->coefficient=head1->coefficient+head2->coefficient;
            newnode->exp=head2->exp;
            newnode->link=NULL;
            attachnode(&poly,newnode);
            }
            head2=head2->link;
            head1=head1->link;
            break;
            default:printf("default");
        }
       
    }	
    while(head1!=NULL)
    {
        polynode* newnode;
        newnode=malloc(sizeof(polynode));
        newnode->coefficient=head1->coefficient;
        newnode->exp=head1->exp;
        attachnode(&poly,newnode);
        head1=head1->link;
    }
    while(head2!=NULL)
    {
        polynode* newnode;
        newnode=malloc(sizeof(polynode));
        newnode->coefficient=head2->coefficient;
        newnode->exp=head2->exp;
        attachnode(&poly,newnode);
        head2=head2->link;
    }
    return poly;
}

int main()
{
    list polya,polyb,polyc;
    polya.head=polyb.head=polyc.head=NULL;
    printf("Enter the first polynomial(coefficent exponent).Enter -1 -1 to end\n");
    readpoly(&polya);
    printf("Displaying first polynomial:\n");
    display(polya);
    printf("Enter the second polynomial(coefficent exponent).Enter -1 -1 to end\n");
    readpoly(&polyb);
    printf("Displaying second polynomial:\n");
    display(polyb);
    polyc=addpoly(polya,polyb);
    printf("Sum of polynomials:\n");
    display(polyc);
}

