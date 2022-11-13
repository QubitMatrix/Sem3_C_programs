#include<stdio.h>
#include<stdlib.h>
#define SIZE 11
void insert(int *arr,int key)
{
	int index=key%SIZE;
	static int counter=0;
	int prob=1;
	while(arr[index]!=-1 && counter<SIZE)
	{
		index=(index+prob)%SIZE;
		prob++;
	}
	if(arr[index]==-1)
	{
		arr[index]=key;
		counter++;
	}
	else
		printf("rehash\n");
}
int search(int* arr,int key)
{
	int index=key%SIZE;
	int count=0;
	int prob=1;
	int newindex=index;
	while(count<SIZE)
	{
		if(arr[newindex]==key)
			return newindex;
		else
		{
			newindex=(index+prob)%SIZE;
			prob++;
		}
		count++;
	}
	return -1;
}


int main()
{
	int n;
	int key;
	scanf("%d",&n);
	int *arr=malloc(sizeof(int)*SIZE);
	for(int i=0;i<SIZE;i++)
		arr[i]=-1;
	for(int i=0;i<n;i++)
	{

		scanf("%d",&key);	
		insert(arr,key);
	}
	printf("Hash table:\n");
	for(int i=0;i<SIZE;i++)
		printf("%d\n",arr[i]);
	printf("Enter key to search\n");
	int ser;
	scanf("%d",&ser);
	int ind=search(arr,ser);
	printf("Search:%d\n",ind);
	int del;
	printf("Enter key to delete\n");
	scanf("%d",&del);
	int delind=search(arr,del);
	if(delind==-1)
		printf("not found\n");
	else
		arr[delind]=-1;

	printf("Hash table:\n");
	for(int i=0;i<SIZE;i++)
		printf("%d\n",arr[i]);
	return 0;
}


