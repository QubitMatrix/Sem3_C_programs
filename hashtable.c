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
		int index2=5-key%5;
		while(Htable->H[newindex].marker==1 && checkcounter<=Htable->size)
		{
			//newindex=(index+probevalue)%Htable->size;//linear
			//newindex=(index+probevalue*probevalue)%Htable->size;//quadratic
			newindex=(index+probevalue*index2)%Htable->size;//double hashing
			probevalue++;
			checkcounter++;
		}
		if(checkcounter==Htable->size)
			printf("Full");
		else
		{
			Htable->H[newindex].key=key;
			Htable->H[newindex].marker=1;
			Htable->count++;
		}
	}

	for(int i=0;i<Htable->size;i++)
		printf("xx%d ",Htable->H[i].key);
	printf("\n");
	
}
int main()
{
	hashtable* Htable;
	Htable=malloc(sizeof(malloc));
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
		insert(Htable,key);
	}
	for(int i=0;i<size;i++)
		printf("%d ",Htable->H[i].key);
	
	
	return 0;
}
