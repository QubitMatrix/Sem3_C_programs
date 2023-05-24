#include<stdio.h>
#include<stdlib.h>
struct stack
{
	char  *ptr_s;
	int size;
	int top;
};
typedef struct stack stack;
void createstack(stack* ptr)
{
	ptr->ptr_s=malloc(sizeof(char)*ptr->size);
	ptr->top=-1;
	//printf("%p",ptr->ptr_s);
} 
void push(stack* ptr,char ele)
{
	if(ptr->top==(ptr->size)-1)
	printf("Stack is full(overflow)");
	else
	{
		ptr->ptr_s[++(ptr->top)]=ele;
	}
}	
char pop(stack* ptr)
{
	char ele;
	if(ptr->top==-1)
	{
		return -1;
	}
	else
	{
		ele=ptr->ptr_s[ptr->top--];
		return ele;
	}
}
void display(stack st)
{
	printf("Stack display:\n");
	if(st.top==-1)
	printf("Empty stack\n");
	else
	{
	while(st.top!=-1)
	{
		printf("%c\n",st.ptr_s[st.top--]);
	}
	}
}
int main()
{
	stack* ptr_st;
	ptr_st=malloc(sizeof(stack));
	printf("Enter the size of the stack");
	scanf("%d",&ptr_st->size);
	createstack(ptr_st);
	int choice;
	char ele,res;
	printf("Enter 1 for push 2 for pop 3 for display and 4 to exit\n");
	while(1)
	{
	printf("\nEnter your choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:printf("Enter the element\n");
		scanf(" %c",&ele);
		push(ptr_st,ele);
		break;
		case 2:res=pop(ptr_st);
		if(res==-1)
		printf("Empty stack(underflow)\n");
		else
		printf("Element popped=%c\n",res);
		break;
		case 3:display(*ptr_st);
		break;
		case 4:exit(0);
		break;
		default:printf("Wrong choice\n");
	}
	}
	return 0;
}
	
	
	
