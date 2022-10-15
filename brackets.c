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
void traverse(char inp[100],stack* st)
{
	char token=inp[0];
	int count=0;
	int k=1;
	while(token!='\0')
	{
		if(token=='(' || token=='[' ||token=='{')
			push(st,token);
		else if(token==')' || token=='}' || token==']')
		{
	
			if(st->top==-1)
			{
				printf("Extra closing brackets\n");
				count=1;
				break;
			}
			char ch=st->ptr_s[st->top];
		        if((ch=='(' && token==')') ||(ch=='[' && token==']')||(ch=='{' && token=='}'))
			{	
					int x=pop(st);
			}
			else
			{
				printf("Mismatch\n");
				count=1;
				break;
			}
		}
		token=inp[k];
		k++;
	}
	if(st->top!=-1 && count==0)
		printf("Extra opening brackets\n");
	else
	{
		if(count==0)
		printf("Balanced parenthesis\n");
	}

}
int main()
{
	stack* ptr_st;
	ptr_st=malloc(sizeof(stack));
	printf("Enter the size of the stack");
	scanf("%d",&ptr_st->size);
	char str[ptr_st->size];
	createstack(ptr_st);
	printf("enter the string");
	scanf("%s",str);
	traverse(str,ptr_st);
	return 0;
}
	
