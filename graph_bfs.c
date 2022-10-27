#include<stdio.h>
#include <stdlib.h>
struct queue
{
	int* arr;
	int rear;
	int front;
};
typedef struct queue queue;
int ** create_graph(int n)
{
	int** ptr=malloc(n*sizeof(int*));
	if(ptr==NULL)
		printf("full\n");
	for(int i=0;i<n;i++)
	{
		ptr[i]=malloc(sizeof(int)*n);
	if(ptr[i]==NULL)
		printf("full\n");
	}
	return ptr;
}
void read_graph(int **ptr,int n)
{
	printf("Enter 1 if edge present else 0\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			scanf("%d",&ptr[i][j]);
	}
}
queue* create_queue(int n)
{
	queue* q=malloc(sizeof(queue));
	if(q==NULL)
		printf("full\n");
	q->arr=malloc(sizeof(int)*n);
	q->rear=q->front=-1;
	if(q->arr==NULL)
		printf("full\n");
	return q;
}
void push(queue *Q,int ele)
{
	if(Q->rear==-1)
	{
		Q->front=Q->rear=0;
		Q->arr[Q->rear]=ele;
	}
	else
		Q->arr[++(Q->rear)]=ele;
}
int pop(queue* Q)
{
	int ele;
	if(Q->front==Q->rear)
	{
		ele=Q->arr[Q->front];
		Q->front=-1;
		Q->rear=-1;
	}
	else if(Q->front!=-1)
		ele=Q->arr[(Q->front)++];
	else
		ele= -1;
	return ele;
}
int isEmpty(queue Q)
{
	if(Q.front==-1)
		return 1;
	else
		return 0;
}

void bfs(int source,int **ptr,int n,int *visited,int* parent,queue *Q)
{
	visited[source]=1;
	parent[source]=source;
	push(Q,source);
	while(!isEmpty(*Q))
	{
		int ele=pop(Q);
		if(ele==-1)
			continue;
		printf("%d\n",ele);
		for(int i=0;i<n;i++)
		{
			//printf("%d\n",ptr[ele][i]);
			if(ptr[ele][i]==1 && visited[i]==0)
			{
				parent[i]=ele;
				visited[i]=1;
				push(Q,i);
			}
		}
	}
}

int main()
{
	printf("Enter n\n");
	int n;
	scanf("%d",&n);
	int **ptr=create_graph(n);
	read_graph(ptr,n);
	int source=0;
	int *visited=calloc(n,sizeof(int));
	int *parent=calloc(n,sizeof(int));
	queue *Q=create_queue(n);
	printf("Traversal\n");
	bfs(source,ptr,n,visited,parent,Q);
	int i;
	printf("Enter des\n");
	scanf("%d",&i);
	int des=i;
	//printf("x%d",des);
	int *stack=malloc(sizeof(int)*n);
	int top=-1;
	stack[++top]=des;
	if(des>n || visited[des]!=1)
		printf("no path\n");
	else
	{
		while(i!=source)
		{
			//printf("x%d %d\n",parent[i],i);
			stack[++top]=parent[i];
			i=parent[i];
		}
	}
	printf("Shortest path\n");
	for(int i=top;i>=0;i--)
		printf("%d ",stack[i]);

	for(int i=0;i<n;i++)
	{
		free(ptr[i]);
	}
	free(visited);
	free(parent);
	free(ptr);
	free(Q->arr);
	free(stack);
	return 0;
}
