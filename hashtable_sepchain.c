#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node* link;
};
typedef struct node node;
struct hashtable
{
	struct node **htable;
	int size;
	int count;
};
typedef struct hashtable hashtable;
node* allocnode()
{
	node* newnode;
	newnode=malloc(sizeof(node));
	newnode->key=0;
	newnode->link=NULL;
	return newnode;
}
void insert(hashtable* ptr_H,int key)
{
	int index;
	index=key%ptr_H->size;
	node* newnode;
	newnode=allocnode();
	newnode->key=key;
	if(ptr_H->htable[index]==NULL)
		ptr_H->htable[index]=newnode;
	else
	{
		node * start;
		start=ptr_H->htable[index];
		while(start->link!=NULL)
		{
			start=start->link;
		}
		start->link=newnode;
	}
}
node* searchhash(hashtable *ptr_H,int search)
{
	/*for(int i=0;i<ptr_H->size;i++)
	{
		node* start=ptr_H->htable[i];
		while(start!=NULL)
		{
			if(start->key==search)
				return start;
			start=start->link;
		}
	}if without hash*/
	int index=search%ptr_H->size;
	node* start=ptr_H->htable[index];
	while(start!=NULL)
	{
		if(start->key==search)
			return start;//return index if search used in delete
		start=start->link;
	}
	return NULL;
}
int delhash(hashtable* ptr_H,int key)
{
	node *temp;
	/*for(int i=0;i<ptr_H->size;i++)
	{
		node* start=ptr_H->htable[i];
		temp=start;
		while(start!=NULL)
		{
			if(start->key==key)
			{
				temp->link=start->link;
				if(temp==start)
					ptr_H->htable[i]=start->link;
				
				free(start);
				ptr_H->count--;
				start=temp;
				return key;
			}
			temp=start;
			start=start->link;
		}
	}if no hashing*/
	int index=key%ptr_H->size;//use from search also right
	if(ptr_H->htable[index]==NULL)
	return -999;
	else
	{

		node* start=ptr_H->htable[index];
		temp=start;
		while(start!=NULL)
		{
			if(start->key==key)
			{
				temp->link=start->link;
				if(temp==start)
					ptr_H->htable[index]=start->link;
				
				free(start);
				ptr_H->count--;
				start=temp;
				return key;
			}
			temp=start;
			start=start->link;
		}
		if(start==NULL)
			return -999;
	}
}
void destroyhash(hashtable* ptr_H)
{
	node*temp;
	for(int i=0;i<ptr_H->size;i++)
	{
		node* start=ptr_H->htable[i];
		while(start!=NULL)
		{
			temp=start;
			start=start->link;
			free(temp);
		}
	}
	free(ptr_H->htable);
	free(ptr_H);
}
			
int main()
{
	hashtable* ptr_H;
	ptr_H=malloc(sizeof(hashtable));
	ptr_H->size=0;
	ptr_H->count=0;
	printf("Enter size of table\n");
	scanf("%d",&ptr_H->size);
	ptr_H->htable=calloc(ptr_H->size,sizeof(node*));
	int key;
	printf("Enter the keys(-1 to end)\n"); 
	while(key!=-1)
	{
		scanf("%d",&key);
		if(key==-1)
			break;
		insert(ptr_H,key);
	}
	for(int i=0;i<ptr_H->size;i++)
	{
		node* start=ptr_H->htable[i];
		while(start!=NULL)
		{
			printf("%d ",start->key);
			start=start->link;
		}
		printf("\n");
	}
	int search;
	printf("Enter key to be searched\n");
	scanf("%d",&search);
	node* searchnode=searchhash(ptr_H,search);
	if(searchnode!=NULL)
		printf("search:%d\n",searchnode->key);
	else
		printf("Not found\n");
	int del;
	printf("Enter key to be deleted\n");
	scanf("%d",&del);
	int delkey=delhash(ptr_H,del);
	printf("%d is deleted\n",delkey);
	for(int i=0;i<ptr_H->size;i++)
	{
		node* start=ptr_H->htable[i];
		while(start!=NULL)
		{
			printf("%d ",start->key);
			start=start->link;
		}
		printf("\n");
	}
	destroyhash(ptr_H);
	return 0;
}
