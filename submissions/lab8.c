
#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 50
#define INFINITY 9999

typedef struct graph 
{
	int n; /* Number of vertices in graph */
	int adj[MAX_NODES][MAX_NODES]; /* Adjacency matrix */
} Graph;

//creates the graph
void create_graph(Graph * adj_mat)
    {
        
        int i, j;
        for (int i = 0; i < adj_mat->n; ++i)
        {
            for (int j = 0; j < adj_mat->n; ++j)
            {
                adj_mat->adj[i][j] = 0;
            }
        }
        while (1)
        {
            //edge between two vertex
            scanf("%d %d\n", &i, &j);
            if (i < 0 && j <= 0 || i >= adj_mat->n || j >= adj_mat->n)
            {
                break;
            }
            adj_mat->adj[i][j] = 1;
        }
    }
//helper functions for inserting an element into a queue 
void append(int *queue, int v, int *pqr)
{
    ++(*pqr);
    queue[*pqr] = v;
}
//helper function to delete from a queue 
int delete (int *queue, int *pqr)
{
    int res = queue[0];
    for (int i = 0; i < *pqr; ++i)
    {
        queue[i] = queue[i + 1];
    }
    --(*pqr);
    return res;
}

//bfs function to calculate the minimum distance 
//You are required to complete this function
int find_dist(Graph * adj_mat, int source, int dest)
{
	int *queue=calloc(adj_mat->n,sizeof(int));
	int* ptr=malloc(sizeof(int));
	*ptr=-1;
	int *visited=calloc(adj_mat->n,sizeof(int));
	int *parent=calloc(adj_mat->n,sizeof(int));
	visited[source]=1;	
	parent[source]=source;
	append(queue,source,ptr);
	while(*ptr!=-1)
	{
		int res=delete(queue,ptr);
		for(int i=0;i<adj_mat->n;i++)
		{
			if(adj_mat->adj[res][i]==1 && visited[i]==0)
			{
				visited[i]=1;
				parent[i]=res;
				append(queue,i,ptr);
			}
		}
	}
	int count=0;
	printf("The shortest distance:");
	if(visited[dest]==0)
		return -1;
	while(dest!=source)
	{
		count++;
		dest=parent[dest];
	}

   	return count; 
}

int main()
{
    Graph adj_mat;

    int source, dest;

    //number of vertex
    scanf("%d\n", &adj_mat.n);
    // creates adj matrix
    create_graph(&adj_mat);

    //source vertex
    scanf("%d\n", &source);

    //destination vertex
    scanf("%d", &dest);
    
    int result = find_dist(&adj_mat, source, dest);
    printf("%d\n",result);
    return 0;
}
