//stack stores operators
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
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
void destroy(stack *ptr_st)
{
	free(ptr_st->ptr_s);
	ptr_st->ptr_s=NULL;
	ptr_st->size=0;
	ptr_st->top=-1;	
}
int isp (char ele)//in stack power
{
	switch(ele)
	{
		case ')':return 5;
		break;//even if not htere it is fine
		case '$':return 30;//'^'
		case '*':
		case '%':
		case '/':return 20;
		case '+':
		case '-':return 10;
		case '#':return -1;
	}
}
int icp(char ele)//incoming power
{
	switch(ele)
	{
		case ')':return 40;
		break;//even if not htere it is fine
		case '$':return 30;//'^'
		case '*':
		case '%':
		case '/':return 20;
		case '+':
		case '-':return 10;
	}
}

void infixtoprefix(char *in_exp,char *out_exp_n)
{
	stack st;
	st.size=strlen(in_exp);
	createstack(&st);
	push(&st,'#');//push dummy symbol into stack
	char token;
	int k=0,count=0;//i for i/p k for o/p
	int len =strlen(in_exp);
	//printf("%d",len);
	int i=len-1;
	token=in_exp[i--];
	char out_exp[50];
	while(count<len)
	{
		if(isalnum(token))
			out_exp[k++]=token;
		else 
			if(token=='(')
			{
				while(st.ptr_s[st.top]!=')')//peek
				{
					out_exp[k++]=pop(&st);
				}
				pop(&st);//pops '('
			}
		else//operator or (
		{
			while(icp(token)<=isp(st.ptr_s[st.top]))
			{
				out_exp[k++]=pop(&st);
			}
			push(&st,token);
		}
		token=in_exp[i--];
		count++;
	}
	//to add symbols till hash 
	while(st.ptr_s[st.top]!='#')
		out_exp[k++]=pop(&st);
	out_exp[k++]='\0';//explicit ending string
	//return out_exp;//if second method
	
	int len2=strlen(out_exp)-1;
	count=0;
	int j=0;
	//printf("%d",len2);
	while(len2!=-1)
	{	
		//printf("%d,%c",j,out_exp[len2]);
		out_exp_n[j++]=out_exp[len2--];
	}
	//printf("%s",out_exp_n);

}
					
		
int main()
{
	char in_exp[50],out_exp[50];
	printf("Enter the infix expression to convert it to prefix\n");
	scanf("%s",in_exp);
	infixtoprefix(in_exp,out_exp);//out_exp=infixtopostfix(in_exp);
	printf("Prefix:%s\n",out_exp);
	return 0;
}
	
	
	
