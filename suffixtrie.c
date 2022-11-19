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
structure* insertstruct(trienode* ptr,char token)
{
        structure *new=malloc(sizeof(structure));
        //new->parent=malloc(sizeof(trienode*)*26);
        new->parent=ptr;
        new->token=token;
        return new;
}
int search(trienode* ptr,char* token)
{
        trienode* start=ptr;
        while(1)
        {
                //printf("%c\n",*token);
                int index=(int)(*token)-(int)('A');
                //printf("%d,%p\n",index,start->child[index]);

                        if(*token=='\0' && start->eow==1)
                                return 1;
                        else if(*token=='\0' && start->eow==0)
                                return -1;//return -1 if it has to search only if that word is inserted like if integer inserted and int should show not found
                        else if(start->child[index]==NULL)                        return 0;//goes out of trie branching
                else
                {
                        start=start->child[index];
                        *(token++);
                }
        }
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
                                else
					 break;
                        }
                        else
                                break;

                }

        }
}


trienode* insert(trienode* pos,char token)
{
        int index=(int)token-(int)('A');
        //printf("index,token%d,%c,%d\n",index,token,pos->eow);
        if(pos->child[index]==NULL)
        {
                trienode* newnode=calloc(1,sizeof(trienode));
                for(int i=0;i<26;i++)
			newnode->child[i]=NULL;
		newnode->eow=0;
                pos->child[index]=newnode;
                return newnode;
        }
        else
        {
                return pos->child[index];
        }
}
void showtrie(trienode* root,int pos,char* a)
{
	//printf("showing%s,%d\n",a,root->eow); 
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
char* getsuffix(int i,char *pattern_init,int len)
{
	char* temp=malloc(sizeof(char)*len+1);
	int k=0;
	//sprintf(temp,pattern_init+(len-i),pattern_init+i);
	for(int j=i;j<len;j++)
	{
		temp[k]=pattern_init[j];
		k++;
	}
	temp[k]='\0';
	//printf("suffix:%s\n",temp);
	return temp;
}
int main()
{
        trienode* root;
        root=malloc(sizeof(trienode));
        char pattern_init[100];
        int n;
	char* pattern=malloc(sizeof(char)*100);
        printf("Enter the number of strings to enter\n");
        scanf("%d",&n);
        for(int j=0;j<n;j++)
        {
                scanf("%s",pattern_init);
		int nn=strlen(pattern_init);
                for(int k=0;k<nn;k++)
		{
			pattern=getsuffix(k,pattern_init,nn);
			//printf("SUFFIX:%s\n",pattern);
			trienode* pos=root;
                	int i=0;
                	char token=pattern[i];
                	while(token!='\0')
                	{
				//printf("stoken%c\n",token);
                        	pos=insert(pos,token);
                       		token=pattern[++i];
                	}
                	if(token=='\0')
                	{
                	        //printf("eow");
                	        pos->eow=1;
                	}
		}
	}
	char a[100];
        printf("Printing trie\n");
	showtrie(root,0,a);
        printf("Enter number of strings to search(found(0 if not found, 1 if found and -1 if it is a substring))\n");
        char key[100];
	scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
                scanf("%s",key);
                int ser=search(root,key);
                printf("found:%d\n",ser);
        }
	printf("Enter string to delete");
        scanf("%s",key);
        delete(root,key);
 printf("Enter number of strings to search\n");
       
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
                scanf("%s",key);
                int ser=search(root,key);
                printf("found:%d\n",ser);
        }
	return 0;
}

