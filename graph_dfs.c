#include<stdio.h>
#include<stdlib.h>
int **creategraph(int n)
{
	int ** graph_mat;
	graph_mat=malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++)
	{
		graph_mat[i]=malloc(sizeof(int)*n);
	}
	return graph_mat;
}
void readgraph(int** graph_mat,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&graph_mat[i][j]);
		}
	}
}
void dfs(int source,int** graph_mat,int* visited,int n)
{
	visited[source]=1;
	printf("%d ",source);
	for(int i=0;i<n;i++)
	{
		if(graph_mat[source][i]==1)//neighbour
			if(visited[i]==0)//not visited
				dfs(i,graph_mat,visited,n);
	}
}
int DFS(int source,int** graph_mat,int* visited,int n)
{
	int comp=1;
	dfs(source,graph_mat,visited,n);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			comp++;
			dfs(i,graph_mat,visited,n);
		}
	}
	return comp;
}
int main()
{
	int **graph_mat;
	int n;
	printf("Enter the number of vertices");
	scanf("%d",&n);
	graph_mat=creategraph(n);readgraph(graph_mat,n);
	int *visited=calloc(sizeof(int),n);
	int source=0;
	int comp=DFS(source,graph_mat,visited,n);//wrapper function
	printf("\nThe number of components in the graph:%d\n",comp);
	if(comp==1)
		printf("Connected graph\n");
	else
		printf("Not connected graph\n");
	printf("Enter the source and destination\n");
	int src,des;
	scanf("%d %d",&src,&des);
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
	dfs(src,graph_mat,visited,n);
	if(visited[des]==1)
		printf("\n%d is connected to %d by a path",src,des);
	else
		printf("\nNo path between %d and %d",src,des);
	return 0;
}

