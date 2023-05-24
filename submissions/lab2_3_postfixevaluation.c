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
struct stack
{
	double  *ptr_s;
	int size;
	int top;
};
typedef struct stack stack;
void createstack(stack* ptr)
{
	ptr->ptr_s=malloc(sizeof(double)*ptr->size);
	ptr->top=-1;
	//printf("%p",ptr->ptr_s);
} 
void push(stack* ptr,double ele)
{
	
	if(ptr->top==(ptr->size)-1)
	printf("Stack is full(overflow)");
	else
	{
		ptr->ptr_s[++(ptr->top)]=ele;
	}
}	
double pop(stack* ptr)
{
	double ele;
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
		printf("%0.2lf\n",st.ptr_s[st.top--]);
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
		case '(':return 5;
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
		case '(':return 40;
		break;//even if not htere it is fine
		case '$':return 30;//'^'
		case '*':
		case '%':
		case '/':return 20;
		case '+':
		case '-':return 10;
	}
}
void postfixeval(char *out_exp)
{
	stack st;
	st.size=strlen(out_exp);
	createstack(&st);
	int i=0,k=0;
	char token=out_exp[i++];
	double sec,fir,eval;
	char sym;
	while(token!='\0')
	{
		if(isalnum(token))
			push(&st,(double)((int)(token)-(int)('0')));
		else
		{
			fir=pop(&st);
			sec=pop(&st);
			if(fir==-1|| sec==-1)
			printf("Extra symbols found\n");
			else
			{
			sym=token;
			switch(sym)
			{
				case '+':eval=sec+fir;
				printf("%0.2lf+%0.2lf=%0.2lf\n",sec,fir,eval);
				push(&st,eval);
				break;
				case '-':eval=sec-fir;
				printf("%0.2lf-%0.2lf=%0.2lf\n",sec,fir,eval);
				push(&st,eval);
				break;
				case '*':eval=sec*fir;
				printf("%0.2lf*%0.2lf=%0.2lf\n",sec,fir,eval);
				push(&st,eval);
				break;
				case '/':eval=sec/fir;
				printf("%0.2lf/%0.2lf=%0.2lf\n",sec,fir,eval);
				push(&st,eval);
				break;
				case '%':eval=(int)sec%(int)fir;
				printf("%0.2lfmod%0.2lf=%0.2lf\n",sec,fir,eval);
				push(&st,eval);
				break;
				case '^':eval=pow(sec,fir);
				printf("%0.2lf^%0.2lf=%0.2lf\n",sec,fir,eval);
				push(&st,eval);
				break;
			}
			}
		}
		display(st);
		token=out_exp[i++];
	}
	if(st.top==0)
	printf("Answer:%lf\n",st.ptr_s[st.top]);
	else
	printf("Wrong expression");
}

int main()
{
	char out_exp[50];
	printf("Enter the postfix expression which is to be evaluated\n");
	scanf("%s",out_exp);
	//char out_exp[50]="123*+673*+-68---";
	postfixeval(out_exp);
	return 0;
}
	
	
	
