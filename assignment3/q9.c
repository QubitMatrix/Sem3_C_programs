#include<stdio.h>
#include<stdlib.h>
void dfs(int n,int arr[n][n],int src,int* visited)
{
	visited[src]=1;
	printf("%d ",src);
	for(int i=0;i<n;i++)
	{
		if(arr[src][i]==1 && visited[i]==0)
		{
		
	
			dfs(n,arr,i,visited);
		}
	}
}
void DFS(int n,int arr[n][n],int src,int* visited)
{
	dfs(n,arr,src,visited);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
			dfs(n,arr,i,visited);
	}
}
void bfs(int n,int arr[n][n],int src,int *visited)
{
	int rear,front;
	rear=front=-1;
	int q[n];
	q[++rear]=src;
	visited[src]=1;
	front++;
	int ele;

	while(front<=rear)
	{
		ele=q[front++];
		printf("%d ",ele);
		for(int i=0;i<n;i++)
		{
			if(arr[ele][i]==1 && visited[i]==0)
			{
				visited[i]=1;
				q[++rear]=i;
				if(front==-1)
					front=0;
			}
		}
	}
}
void BFS(int n,int arr[n][n],int src,int* visited)
{
	bfs(n,arr,src,visited);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
			bfs(n,arr,i,visited);
	}
}
int main()
{
	int n;
	printf("Enter number of nodes\n");
	scanf("%d",&n);
	int arr[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[i][j]=0;
		}
	}
	int choice;
	printf("Enter if directed(0) or undirected(1)\n");
	scanf("%d",&choice);
	printf("Enter the edges u v(-1 -1 to end)\n");
	int u,v;
	scanf("%d %d",&u,&v);
	while(u!=-1 && v!=-1)
	{
		
		if(choice==1)
			arr[v][u]=1;
		arr[u][v]=1;
		scanf("%d %d",&u,&v);
	}
	int *visited=calloc(n,sizeof(int));
	printf("Matrix:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("Traversal(DFS):\n");
	DFS(n,arr,0,visited);
	free(visited);
	visited=calloc(n,sizeof(int));
	printf("\nTraversal(BFS):\n");
	BFS(n,arr,0,visited);
	return 0;
}

