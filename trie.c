#include<stdio.h>
#include<stdlib.h>
struct trienode
{
	struct trienode* child[26];
	int eow;
};
typedef struct trienode trienode;
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
		printf("%d\n",index);
		
			if(*token=='\0' && start->eow==1)
				return 1;
			else if(*token=='\0' && start->eow==0)
				return 1;//return -1 if it has to search only if that word is inserted like if integer inserted and int should show not found
			else if(start->child[index]==NULL)
			return 0;
		else
		{
			start=start->child[index];
			*(token++);
		}
	}
}
int main()
{
	trienode* root;
	root=malloc(sizeof(trienode));
	char pattern[100];
	for(int j=0;j<5;j++)
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
	scanf("%s",key);
	int ser=search(root,key);
	printf("found:%d\n",ser);
	return 0;
}

