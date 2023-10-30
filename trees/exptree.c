#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct tnode
{
	struct tnode* left;
	char data;
	struct tnode* right;
};
typedef struct tnode tnode;
struct stack
{
	tnode* s[MAX];
	int top;
};
typedef struct stack stack;
void push(stack* ptr,tnode* ele)
{
	if(ptr->top==MAX-1)
		printf("Full");
	else
	{
		ptr->s[++(ptr->top)]=ele;
	}
	//printf("t%d",ptr->top);
}
tnode* pop(stack* ptr)
{
	if(ptr->top==-1)
	{
		printf("Empty");
		return NULL;
	}
	else
	{
		return ptr->s[(ptr->top)--];
	}
}	
int isoper(char token)
{
	if(token=='+' || token=='-' || token=='*' || token=='/')
		return 1;
	else
		return 0;
}
tnode* constructexptree(char exp[])
{
	stack st;
	st.top=-1;
	tnode* newnode;
	int i=1;
	char token;
	token=exp[0];
	while(token!='\0')
	{
		newnode=malloc(sizeof(tnode));
		newnode->data=token;
		newnode->left=newnode->right=NULL;
		//printf("%c",token);
		if(isoper(token))
		{
			newnode->right=pop(&st);
			newnode->left=pop(&st);
			//printf("x%c\n",token);
			push(&st,newnode);
		}
		else
		{
			//printf("xx%c\n",token);
			push(&st,newnode);
		}
		token=exp[i];
		i++;
	}
	tnode* x=pop(&st);
	//printf("%d",st.top);
	if(st.top==-1)
		return x;
	else
		return NULL;
}
int postorder(tnode* ptr)
{
	int res=0;
       	int x=0;
	if(isoper(ptr->data))
	{
		printf("entering if\n");
		switch(ptr->data)
		{
			case '+':res=postorder(ptr->left)+postorder(ptr->right);
				 break;
		        case '-':res=postorder(ptr->left)-postorder(ptr->right);
				 break;
			case '*':res=postorder(ptr->left)*postorder(ptr->right);
				 break;
			case '/':res=postorder(ptr->left)/postorder(ptr->right);
				 break;
			default:printf("invalid symbol");
				exit(1);
		}
		printf("rentering if%d\n",res);
		return res;
	}
	else
	{
		printf("entering else");
		printf("Enter value of %c",ptr->data);
		scanf("%d",&x);
		return x;
	}
}
int main()
{
	tnode* root;
	root=NULL;
	//printf("new");
	char postfix_exp[MAX];
	scanf("%s",postfix_exp);
	root=constructexptree(postfix_exp);
	if(root==NULL)
		printf("Wrong expression");
	printf("%p\n",root);
	int res1=postorder(root);
	printf("Evaluated Answer:%d",res1);
	return 0;
}


