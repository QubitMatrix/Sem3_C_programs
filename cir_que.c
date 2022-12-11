#include<stdio.h>
#include<stdlib.h>
void enqueue(int* q,int *front,int *rear,int n,int ele)
{
	if(*front==(*rear+1)%n)
		printf("Full\n");
	else
	{
		*rear=((*rear)+1)%n;
		q[*rear]=ele;
		if(*front==-1)
			*front=0;
	}
}
void dequeue(int *q,int* front,int* rear,int n)
{
	if(*front==-1)
		printf("Empty\n");
	else
	{
		printf("%d %d\n",*front,*rear);
		int ele=q[*front];
		if(*front==*rear)
			*front=-1;
		else
			*front=((*front)+1)%n;
	}
}
int Qmax(int* q,int n,int rear,int front)
{
	int max=0;
	for(int i=front;i!=(rear+1)%n;i=(i+1)%n)
		if(q[i]>max)
			max=q[i];
	return max;
}
int main()
{
	int n;
	scanf("%d",&n);
	int* q=malloc(sizeof(int)*n);
	int front=-1;
	int rear=-1;
	int ele;
	int count=0;
	int inp=0;
	scanf("%d",&inp);
	while(inp!=-1)
	{
		if(inp==1)
		{
			scanf("%d",&ele);
			enqueue(q,&front,&rear,n,ele);
		}
		else if(inp==2)
			dequeue(q,&front,&rear,n);
		else if (inp==3)
		{
			int max=Qmax(q,n,rear,front);
			printf("%d",max);
		}
		scanf("%d",&inp);
	}
	return 0;
}

