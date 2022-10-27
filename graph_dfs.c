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
void dfs(int source,int** graph_mat,int* visited,int n,int comp,int* vorder,int* dorder,int* parent)
{
	static int count=0,countd=0;
	visited[source]=comp;
	vorder[count]=source;
	printf("Vertice:%d,Component id:%d\n",source,visited[source]);
	for(int i=0;i<n;i++)
	{
		if(graph_mat[source][i]==1)//neighbour
			if(visited[i]==0)//not visited
			{	parent[i]=source;
				count++;
				dfs(i,graph_mat,visited,n,comp,vorder,dorder,parent);
	printf("dead end order(postorder):\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",dorder[i]);
	}
			}		
	}
	dorder[countd]=source;
	countd++;
	//printf("%d ",source);
}
void DFS(int source,int** graph_mat,int* visited,int n,int *vorder,int *dorder,int* parent)
{
	int comp=1;
	parent[source]=source;
	dfs(source,graph_mat,visited,n,comp,vorder,dorder,parent);
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			comp++;
			dfs(i,graph_mat,visited,n,comp,vorder,dorder,parent);
		}
	}
}
int main()
{
	int **graph_mat;
	int n;
	scanf("%d",&n);
	graph_mat=creategraph(n);readgraph(graph_mat,n);
	int *visited=calloc(sizeof(int),n);
	int *vorder=malloc(sizeof(int)*n);
	int *dorder=malloc(sizeof(int)*n);
	int *parent=malloc(sizeof(int)*n);
	int source=0;
	DFS(source,graph_mat,visited,n,vorder,dorder,parent);//wrapper function
	printf("visited order(preorder):\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",vorder[i]);
	}
	printf("dead end order(postorder):\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",dorder[i]);
	}
	printf("(inorder):\n");
	free(visited);
	visited=calloc(sizeof(int),n);
	for(int i=0;i<n;i++)
	{
		if(visited[dorder[i]]==0)
		{
			printf("%d\n",dorder[i]);
			visited[dorder[i]]=1;
		}
		if(visited[parent[dorder[i]]]==0)
		{
			visited[parent[dorder[i]]]=1;
			//printf("a%d\n",parent[dorder[i]]);	
			printf("%d\n",parent[dorder[i]]);
		}
	}
	return 0;
}

