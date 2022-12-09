 #include<stdio.h>
 #include<stdlib.h>
 typedef struct node
 {
 	int data;
 	struct node* link;
 }node;
// typedef struct node node;
 node* allocatenode(int ele)
 {
 	node* newnode;
 	newnode=malloc(sizeof(node));
 	newnode->data=ele;
 	newnode->link=NULL;
 	return newnode;
 }
 void insert(node **ptrhead,int ele)
 {
 	node* newnode;
 	newnode=allocatenode(ele);
 	if(!(*ptrhead))
 	*ptrhead=newnode;
 	else
 	{
 		node *dhead;
 		dhead=*ptrhead;
 		while(dhead->link!=NULL)
 			dhead=dhead->link;
 		dhead->link=newnode;
 	}
 }
 void display(node *head)
 {
 	if(!head)
 		printf("Empty");
 	else
 	{
 		node *dhead;
 		dhead=head;
 		while(dhead!=NULL)
 		{
 			printf("%d\n",dhead->data);
 			dhead=dhead->link;
 		}
 	}
 }
 int cmp(int a,int b)

{
if(a>b)
return 1;
else if(a<b)
return -1;
else 
return 0;
} 
void copy(node **copy,node *head)
{
	while(head!=NULL)
	{
		*copy=head;
		*copy=(*copy)->link;
		head=head->link;
	}
}
 void concatenate(node **head1,node *head2)
 {
 	node *dhead;
 	dhead=*head1;
 	while(dhead->link!=NULL)
 	{
 		dhead=dhead->link;
 	}
 	dhead->link=head2;
 }		
 node* concatenatenew(node *head1,node* head2)
 {
 	node *temp;
 	node *newnode;
 	temp=NULL;
 	node *dhead;
 	dhead=head1;
 	while(dhead!=NULL)
 	{
 		insert(&temp,dhead->data);
 		dhead=dhead->link;
 	}
 	dhead=head2;
 	while(dhead!=NULL)
 	{
 		insert(&temp,dhead->data);
 		dhead=dhead->link;
 	}
 	return temp;
 }
 		
 node* mergenew(node *head1,node *head2)
 {
 	node *newnode;
 	newnode=NULL;
 	while(head1!=NULL && head2!=NULL)
 	{
 		switch(cmp(head1->data,head2->data))
 		{
 			case 1:
 			insert(&newnode,head2->data);
 			head2=head2->link;
 			break;
 			case -1:insert(&newnode,head1->data);
 			head1=head1->link;
 			break;
 			case 0:insert(&newnode,head1->data);
 			//insert(&newnode,head1->data);//to include duplicates
 			head1=head1->link;
 			head2=head2->link;
 			break;
 			default:printf("a");
 		}
 	}
 	while(head1!=NULL)
 	{
 		insert(&newnode,head1->data);
 		head1=head1->link;
 	}
 	while(head2!=NULL)
 	{
 		insert(&newnode,head2->data);
 		head2=head2->link;
 	}
 	return newnode;
 }

void merge(node **head1,node* head2)
{
	//printf("a");
	node *dhead,*newnode;
	dhead=*head1;
	node *prev;
	prev=NULL;
	//printf("a");
	while(dhead!=NULL && head2!=NULL)
	{
		//printf("a");
		switch(cmp(dhead->data,head2->data))
		{
			case -1://printf("a1");
			prev=dhead;
			dhead=dhead->link ;
			break;
			case 0://printf("a1");
			prev=dhead;
			dhead=dhead->link ;
			break;
			case 1 ://printf("a3%d",head2->data);
			newnode=allocatenode(head2->data);
			head2=head2->link;
			newnode->link=dhead;
			if(prev)
			{prev->link=newnode;
			prev=newnode;}
			else
			{prev=newnode;
			*head1=newnode;
			}
			break;
			default:printf("in default case");	
		}
	}
	while(head2)
	{
		insert(head1,head2->data);
		head2=head2->link;
	}
}
			
 			
 		
 int main()
 {
 	printf("Enter values to be stored in first list (-1 to end)");
 	int input;
 	scanf("%d",&input);
 	node* head1;
 	head1=NULL;
 	while(input!=-1)
 	{
 		insert(&head1,input);
 		scanf("%d",&input);
 	}
 	printf("First\n");
 	display(head1);
 	printf("Enter values to be stored in second list (-1 to end)");
 	scanf("%d",&input);
 	node* head2;
 	head2=NULL;
 	while(input!=-1)
 	{
 		insert(&head2,input);
 		scanf("%d",&input);
 	}
 	printf("Second\n");
 	display(head2);
 	//concatenate(&head1,head2);
 	//printf("Concatenate into first\n");
 	//display(head1);
 	printf("Concatenate into new\n");
 	node *head3=concatenatenew(head1,head2);
 	display(head3);
 	printf("Merge into new\n");
 	node* head_3=mergenew(head1,head2);
 	display(head_3);
 	printf("Merge into first\n");
 	merge(&head1,head2);
 	display(head1);
 	return 0;
 }
 		
 	
 	
 
