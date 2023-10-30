/**
1,2,3,+,*
1,2+3,*->1,5,*->1*5=5**/
//stack stores operands
//if numbers then coverted using ascii-> char 'num'-char'0'
//finally one number in stack that is the naswer if more than one number then the expression was wrong
//1+2*3-(6+7*3)-(6-8),convert to postfix and evaluate it

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include"infix.h"
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
	printf("Stack is full(overflow)");
	else
	{
		ptr->ptr_s[++(ptr->top)]=ele;
	}
}	
int pop(stack* ptr)
{
	int ele;
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
		printf("%d\n",st.ptr_s[st.top--]);
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
		case '$':
		case '^':return 30;//'^'
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
		case '(':return 40;
		break;//even if not htere it is fine
		case '$':
		case '^':return 30;//'^'
		case '*':
		case '%':
		case '/':return 20;
		case '+':
		case '-':return 10;
	}
}
void prefixeval(char *out_exp)
{
	stack st;
	st.size=strlen(out_exp);
	createstack(&st);
	int len=strlen(out_exp);
	int k=len-1;
	char token=out_exp[k--];
	int eval;
	int sec,fir;
	char sym;
	int count=0;
	while(count<len)
	{
		
		if(isalnum(token))
			push(&st,(int)(token)-(int)('0'));
		else
		{
			fir=pop(&st);
			sec=pop(&st);
			if(fir==-1|| sec==-1)
			{
			printf("Extra symbols found\n");
			exit(0);
			}
			else
			{
			sym=token;
			switch(sym)
			{
				case '+':eval=fir+sec;
				printf("%d+%d=%d\n",fir,sec,eval);
				push(&st,eval);
				break;
				case '-':eval=fir-sec;
				printf("%d-%d=%d\n",fir,sec,eval);
				push(&st,eval);
				break;
				case '*':eval=fir*sec;
				printf("%d*%d=%d\n",fir,sec,eval);
				push(&st,eval);
				break;
				case '/':eval=fir/sec;
				printf("%d/%d=%d\n",fir,sec,eval);
				push(&st,eval);
				break;
				case '%':eval=fir%sec;
				printf("%dmod%d=%d\n",fir,sec,eval);
				push(&st,eval);
				break;
				case '^':
				case '$':eval=pow(fir,sec);
				printf("%d^%d=%d\n",fir,sec,eval);
				push(&st,eval);
				break;
			}
			}
		}
		count++;
		display(st);
		token=out_exp[k--];
	}
	if(st.top==0)
	printf("Answer:%d\n",st.ptr_s[st.top]);
	else
	printf("Wrong expression");
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
			while((icp(token)<isp(st.ptr_s[st.top])) || (icp(token)==isp(st.ptr_s[st.top]) && (isp(st.ptr_s[st.top])==30)))
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
		out_exp_n[j++]=out_exp[len2--];
	}
	out_exp_n[j]='\0';


}
		
int main()
{
	
	printf("Enter size and the infix expression which is to be evaluated\n");
	int size;
	scanf("%d",&size);
	char in_exp[size],out_exp[size];
	scanf("%s",in_exp);
	infixtoprefix(in_exp,out_exp);//out_exp=infixtopostfix(in_exp);
	printf("Prefix:%s\n",out_exp);
	prefixeval(out_exp);
	return 0;
}
	
	
	
