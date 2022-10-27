#include<stdio.h>
#include<stdlib.h>
int count=0;
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
void dfs(int source,int** graph_mat,int* visited,int n,int des,int* path)
{
	//static int count=0;
	visited[source]=1;
	printf("%d ",source);
	if(source!=des){
	for(int i=0;i<n;i++)
	{
		if(source==des)
		{
			path[count]=source;
			count++;
			break;
		}
		if(graph_mat[source][i]==1)//neighbour
			if(visited[i]==0)//not visited
			{
				path[count]=source;
				count++;
				dfs(i,graph_mat,visited,n,des,path);		
			}
	}
	if(visited[des]==0)
		count=0;
	}
	else if(source==des)
	{
		path[count]=source;
		count++;
	}
	
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
	printf("Enter the source and destination\n");
	int src,des;
	int* path;
	scanf("%d %d",&src,&des);
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
	dfs(src,graph_mat,visited,n,des,path);
	printf("Path:\n");
	for(int i=0;i<count;i++)
		printf("%d ",path[i]);
	if(visited[des]==1)
		printf("\n%d is connected to %d by a path",src,des);
	else
		printf("\nNo path between %d and %d",src,des);
	return 0;
}
