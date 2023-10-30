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
void dfs(int source,int* parent,int** graph_mat,int* visited,int n,int *cycle)
{
	visited[source]=1;	
	//printf("%d ",source);
	if((*cycle)!=1)
	{
		for(int i=0;i<n;i++)
		{
			if(*cycle==1)
				break;
			if(graph_mat[source][i]==1)//neighbour
			{
				if(visited[i]==0)//not visited
				{
					parent[i]=source;
					dfs(i,parent,graph_mat,visited,n,cycle);
				}
				else
				{
					if(parent[source]!=i)
					{
						printf("cycle found\n");
						*cycle=1;
						break;
					}
				}
	
			}
		}
	}
}
void DFS(int source,int* parent,int** graph_mat,int* visited,int n,int *cycle)
{
	parent[source]=-1;
	dfs(source,parent,graph_mat,visited,n,cycle);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
				dfs(i,parent,graph_mat,visited,n,cycle);
		}
	}
}
int main()
{
	int **graph_mat;
	int n;
	scanf("%d",&n);
	graph_mat=creategraph(n);
	readgraph(graph_mat,n);
	int *visited=calloc(sizeof(int),n);
	int *parent=calloc(sizeof(int),n);
	int source=0;
	int cycle=0;
	DFS(source,parent,graph_mat,visited,n,&cycle);//wrapper function
	if(cycle==0)
		printf("cycle not found\n");
	return 0;
}
