#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int  *ptr_s;
	int size;
	int top;
};
typedef struct stack stack;
void createstack(stack* ptr)
{
	ptr->ptr_s=malloc(sizeof(int)*ptr->size);
	ptr->top=-1;
	//printf("%p",ptr->ptr_s);
} 
void push(stack* ptr,int ele)
{
	if(ptr->top==(ptr->size)-1)
	printf("Queue is full(overflow)");
	else
	{
		ptr->ptr_s[++(ptr->top)]=ele;
	}
}	
void copystack(stack *ptr1,stack *ptr2)
{
	int top1=ptr1->top;
	int top2=ptr2->top;
	while(top1!=-1)
	{
		top2+=1;
		ptr2->ptr_s[top2]=ptr1->ptr_s[top1];
		top1-=1;
		//printf("%d,%d,%d",ptr2->ptr_s[top2],top2,top1);
	}
	ptr1->top=-1;
	//printf("%d",top2);
	ptr2->top=top2;
}
int pop(stack* ptr1,stack*ptr)
{
	
	int ele;
	if(ptr1->top==-1)
	{
		ele= -1;
	}
	
	else
	{
		copystack(ptr1,ptr);
		ele=ptr->ptr_s[ptr->top--];
		copystack(ptr,ptr1);
	}
	
	return ele;
}
void display(stack* st1,stack* st2)
{
	copystack(st1,st2);
	printf("Queue display:\n");
	if(st2->top==-1)
	printf("Empty queue\n");
	else
	{
	int top2=st2->top;
	while(top2!=-1)
	{
		printf("%d\n",st2->ptr_s[top2]);
		top2-=1;
	}
	}
	printf("top pointers:%d,%d\n",st1->top,st2->top);
	//copystack(st2,st1);
}
int main()
{
	stack* ptr_st1;
	stack *ptr_st2;
	ptr_st1=malloc(sizeof(stack));
	ptr_st1=malloc(sizeof(stack));
	printf("Enter the size of the queue");
	scanf("%d",&ptr_st1->size);
	createstack(ptr_st1);
	createstack(ptr_st2);
	int choice;
	int ele,res;
	printf("Enter 1 for push 2 for pop 3 for display and 4 to exit\n");
	while(1)
	{
	printf("\nEnter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("Enter the element\n");
		scanf(" %d",&ele);
		push(ptr_st1,ele);
		break;
		case 2:res=pop(ptr_st1,ptr_st2);
		if(res==-1)
		printf("Empty queue(underflow)\n");
		else
		printf("Element popped=%d\n",res);
		break;
		case 3:
		display(ptr_st1,ptr_st2);
		break;
		case 4:exit(0);
		break;
		default:printf("Wrong choice\n");
	}
	}
	return 0;
}
	
	
	
