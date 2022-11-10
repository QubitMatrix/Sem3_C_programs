#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct trienode
{
	struct trienode* child[26];
	int eow;
};
typedef struct trienode trienode;

struct structure
{
	trienode* parent;
	char token;
};
typedef struct structure structure;
struct stack
{
	struct structure** arr;
	int top;
};
typedef struct stack stack;

trienode* insert(trienode* pos,char token)
{
	int index=(int)token-(int)('A');
	printf("index,token%d,%c,%d\n",index,token,pos->eow);
	if(pos->child[index]==NULL)
	{
		trienode* newnode=malloc(sizeof(trienode));
		newnode->eow=0;
		pos->child[index]=newnode;
		return newnode;
	}
	else
	{
		return pos->child[index];
	}
}
int search(trienode* ptr,char* token)
{
	trienode* start=ptr;
	while(1)
	{
		printf("%c\n",*token);
		int index=(int)(*token)-(int)('A');
		printf("%d,%p\n",index,start->child[index]);
		
			if(*token=='\0' && start->eow==1)
				return 1;
			else if(*token=='\0' && start->eow==0)
				return -1;//return -1 if it has to search only if that word is inserted like if integer inserted and int should show not found
			else if(start->child[index]==NULL)
			return 0;//goes out of trie branching
		else
		{
			start=start->child[index];
			*(token++);
		}
	}
}
structure* insertstruct(trienode* ptr,char token)
{
	structure *new=malloc(sizeof(structure));
	//new->parent=malloc(sizeof(trienode*)*26);
	new->parent=ptr;
	new->token=token;
	return new;
}

void push(stack* st,structure* data)
{
	st->arr[++(st->top)]=data;
}
structure* pop(stack *st)
{
	if(st->top!=-1)
		return st->arr[(st->top)--];
	else
		return NULL;
}	
void delete(trienode* root,char* key)
{
	int i=0;
	char token=key[i];
	int ser=search(root,key);
	stack* s=malloc(sizeof(stack));
	s->arr=malloc(sizeof(structure*)*100);
	s->top=-1;
	trienode* cur=root;
	if(ser==0)
		printf("Not found");
	else
	{
		cur=root;
		structure* structure1;
		while(token!='\0')
		{
			structure1=insertstruct(cur,token);
			printf("push%c\n", token);
			push(s,structure1);
			cur=cur->child[token-'A'];
			token=key[++i];
		}
		cur->eow=0;
		int count=0;
		while(s->top!=-1)
		{
			structure* popstruct;
			popstruct=pop(s);
			int index2=popstruct->token-'A';
			if((popstruct->parent)->child[index2]!=NULL && (popstruct->parent->child[index2])->eow==0)
			{
				count=0;
				trienode* del=popstruct->parent->child[index2];
				for(int x=0;x<26;x++)
				{
					if(del->child[x]!=NULL)
					{
						count=1;
						break;
					}
						
				}
				if(count!=1)
				{
					free(del);
					popstruct->parent->child[index2]=NULL;
				}
			}
			else
				break;

		}

	}
}
void showtrie(trienode* root,int pos,char* a)
{
	
	for(int i=0;i<26;i++)
	{
		if(root->child[i]!=NULL)
		{
			a[pos]=i+'A';
			/*if(root->eow==1)
				printf("%s\n",a);
			*/
			pos++;
			showtrie(root->child[i],pos,a);
			pos--;
		}
	}
	if(root->eow==1)
	{
		char *s1=malloc(sizeof(char)*pos);
		s1=strncpy(s1,a,pos);
		printf("%s,%d\n",s1,pos);
	}
}
void autofill(trienode* root,int pos,char* a)
{

        for(int i=0;i<26;i++)
        {
                if(root->child[i]!=NULL)
                {
                        a[pos]=i+'A';
                        /*if(root->eow==1)
                                printf("%s\n",a);
                        */
                        pos++;
                        showtrie(root->child[i],pos,a);
                        pos--;
                }
        }
        if(root->eow==1)
        {
                char *s1=malloc(sizeof(char)*pos);
                s1=strncpy(s1,a,pos);
                printf("%s,%d\n",s1,pos);
        }
}
int main()
{
	trienode* root;
	root=malloc(sizeof(trienode));
	char pattern[100];
	int n;
	printf("Enter the number of strings to enter\n");
	scanf("%d",&n);
	for(int j=0;j<n;j++)
	{
		scanf("%s",pattern);
		trienode* pos=root;
		int i=0;
		char token=pattern[i];
		while(token!='\0')
		{
			pos=insert(pos,token);
			token=pattern[++i];
		}
		if(token=='\0')
		{
			printf("eow");
			pos->eow=1;
		}
	}
	char key[100];
	printf("Enter number of strings to search\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",key);
		int ser=search(root,key);
		printf("found(0 if not found, 1 if found and -1 if it is a substring(only prefix substring)):%d\n",ser);
	}
	printf("Enter string to delete");
	scanf("%s",key);
	delete(root,key);
	//printf("%d\n",search(root,key));
	printf("Enter number of strings to search\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",key);
		int ser=search(root,key);
		printf("found(0 if not found, 1 if found and -1 if it is a substring(only prefix substring)):%d\n",ser);
	}char a[100];
	showtrie(root,0,a);
	printf("Enter string for autofill\n");
	scanf("%s",key);
	char tok;
	int i=0;
	tok=key[i];
	int index=0;
	trienode* droot=root;
	while(i<strlen(key))
	{
		index=tok-'A';
		droot=droot->child[index];
		tok=key[++i];
	}

	autofill(droot,strlen(key),key);
	return 0;
}

