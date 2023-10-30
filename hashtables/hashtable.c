//hash function:H(key)=key%table size
//collisions:open addressing and close addressing
//Open addressing:
#include<stdio.h>
#include<stdlib.h>
struct data
{
	int key;//record unique field is key( can have more details)
	int marker;//
};
typedef struct data data;
struct hashtable
{
	int size;//max size
	int count;//actuall elements
	struct data* H;
};
typedef struct hashtable hashtable;
void insert(hashtable *Htable,int key)
{
	int index;
	
	index=key%Htable->size;
	//printf("abc%d",index);
	if(Htable->H[index].marker==0)
	{
		Htable->H[index].marker=1;
		Htable->H[index].key=key;
		Htable->count++;
	}
	else
	{
		int probevalue=1;
		int checkcounter=1;
		int newindex=index;
		int index2=7-key%7;
		while(Htable->H[newindex].marker==1)
		{
			//newindex=(index+probevalue)%Htable->size;//linear
			//newindex=(index+probevalue*probevalue)%Htable->size;//quadratic
			newindex=(index+probevalue*index2)%Htable->size;//double hashing
			probevalue++;
			//checkcounter++;
		}
		Htable->H[newindex].key=key;
		Htable->H[newindex].marker=1;
		Htable->count++;
		
	}
	/*
	for(int i=0;i<Htable->size;i++)
		printf("xx%d ",Htable->H[i].key);
	printf("\n");
	*/
}
int prime(int n)
{
	int count=0;
	for(int i=n;i<2*n;i++)
	{
		count=0;
		for(int j=2;j<i;j++)
		{
			if(i%j==0)
				count++;
		}
		if(count==0)
			return i;
	}
}
void rehash(hashtable *Htable)
{
	int* arr=malloc(sizeof(int)*Htable->size);
	int len1=Htable->size;
	for(int i=0;i<Htable->size;i++)
		arr[i]=Htable->H[i].key;
	int newsize=prime(Htable->size*2);
	printf("New size:%d\n",newsize);
	Htable->H=realloc(Htable->H,sizeof(data)*newsize);
	Htable->size=newsize;
	Htable->count=0;
	for(int i=0;i<Htable->size;i++)
	{
		Htable->H[i].key=0;
		Htable->H[i].marker=0;
	}
	printf("rehash%d\n",Htable->size);
	for(int i=0;i<len1;i++)
	{
		printf("Reinserting:%d\n",arr[i]);
		insert(Htable,arr[i]);
	}
}
int search(hashtable*Htable,int ser)
{
	int index=ser%Htable->size;
	if(Htable->H[index].key==ser)
		return index;
	else
	{
		int counter=0;
		int probevalue=1;
		int newindex;
		while(counter<Htable->size)
		{
			newindex=index+probevalue*(7-ser%7);
		        if(Htable->H[newindex].key==ser)
				return newindex;
			probevalue++;
			counter++;
		}
		return -1;
	}
}
int delete(hashtable *Htable,int key)
{
	int index=search(Htable,key);
	Htable->H[index].key=0;
	Htable->H[index].marker=0;
}
int main()
{
	hashtable* Htable;
	Htable=malloc(sizeof(hashtable));//works in gcc without this as gcc oversees it 
	printf("%d",sizeof(malloc));
	Htable->count=0;
	Htable->H=NULL;
	int size;
	scanf("%d",&size);
	Htable->size=size;
	Htable->H=malloc(sizeof(data)*size);
	int key;
	for(int i=0;i<size;i++)
		Htable->H[i].marker=0;
	while(key!=-1)
	{
		scanf("%d",&key);
		printf("count%d\n",Htable->count);
		if(key==-1)
			break;
		if(Htable->count<Htable->size)
			insert(Htable,key);
		else
		{
			rehash(Htable);
			for(int i=0;i<size;i++)
				printf("%d ",Htable->H[i].key);
			insert(Htable,key);
		}
	}
        for(int i=0;i<Htable->size;i++)
	printf("%d ",Htable->H[i].key);	
	int serkey;
	printf("\nEnter key to search\n");
	scanf("%d",&serkey);
	int ser=search(Htable,serkey);
	printf("search:%d\n",ser);
        int delkey;
	printf("Enter key to delete\n");
	scanf("%d",&delkey);
	int del=delete(Htable,delkey);
	for(int i=0;i<Htable->size;i++)
	printf("%d ",Htable->H[i].key);	
	return 0;
}
