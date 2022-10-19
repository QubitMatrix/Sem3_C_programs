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
int main()
{
	int **graph_mat;
	int n;
	
	scanf("%d",&n);
	graph_mat=creategraph(n);readgraph(graph_mat,n);
	int *visited=calloc(sizeof(int),n);
	int source=0;
	dfs(source,graph_mat,visited,n);
	return 0;
}

