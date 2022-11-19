#include <stdio.h>
#include <stdlib.h>

// Graph structure to store number
// of vertices and edges and
// Adjacency matrix
struct Graph {
	int V;
	int E;
	int** Adj;
};

//add edges in the adjacency matrix
void addEdges(int **amat,int x,int y)
{
	amat[x][y]=1;
	amat[y][x]=1;
}

//return the Graph structure with filled values
struct Graph* adjMatrix(int edges,int vert,int arr[][2])
{
	
	struct Graph* G = (struct Graph*)
	malloc(sizeof(struct Graph));
	if (!G) {
		return NULL;
	}
	G->E=edges;
	G->V=vert;
	G->Adj = (int**)malloc((G->V) * sizeof(int*));
	for (int k = 0; k < G->V; k++) {
		G->Adj[k] = (int*)malloc((G->V) * sizeof(int));
	}

	for (int u = 0; u < G->V; u++) {
		for (int v = 0; v < G->V; v++) {
			G->Adj[u][v] = 0;
		}
	}

	for (int i = 0; i < G->E; i++)
		addEdges(G->Adj,arr[i][0],arr[i][1]);

	return G;
}


// DFS function to print DFS traversal of graph
void dfs(struct Graph* G,int vis[],int s)
{
	//ToDo
	vis[s]=1;
	printf("%d",s);
	for(int i=0;i<G->V;i++)
	{
		if(G->Adj[s][i]==1 && vis[i]==0)
		{
			dfs(G,vis,i);
		}
	}
}

//BFS function to print BFS traversal of graph
void bfs(struct Graph*G,int visited[],int s) 
{
	//ToDo
	int q[G->V];
	int rear,front;
	rear=front=-1;
	visited[s]=1;
	q[++rear]=s;
	front++;
	int ele;
	while(front<=rear)
	{
		ele=q[front++];
		printf("%d",ele);
		for(int i=0;i<G->V;i++)
		{
			if(G->Adj[ele][i]==1 && visited[i]==0)
			{
				visited[i]=1;
				q[++rear]=i;
			}
		}
	}
}


// Driver code
int main()
{
	struct Graph* G;
	//edges stored in a 10x2 matrix
	int arr[10][2];
	int edges,vert,s;
	scanf("%d %d",&vert,&edges);
	
	//used to take the edges as inputs
	for(int i=0;i<edges;i++)
	{
		scanf("%d %d",&arr[i][0],&arr[i][1]);
	}
	
	G = adjMatrix(edges,vert,arr);
	scanf("%d",&s);

	int vis[100];
	for (int i = 0; i < 100; i++) {
		vis[i] = 0;
	}

	dfs(G,vis,s);
	for (int i = 0; i < G->V; i++) {
		if (!vis[i]) {
			dfs(G,vis,i);
		}
	}

	printf("\n");
	int visited[100];
	for (int i = 0; i < 100; i++) {
		visited[i] = 0;
	}

	bfs(G,visited,s);
	for (int i = 0; i < G->V; i++) {
		if (!visited[i]) {
			bfs(G,visited,i);
		}
	}	
	printf("\n");

	return 0;
}
