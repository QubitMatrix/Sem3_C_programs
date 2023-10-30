#include<stdlib.h>
#include<stdio.h>

/*edge list structure for each edge */
typedef struct{
    unsigned int first;
    unsigned int second;
}edge;
void dfs(int source, const edge *edges,unsigned int n,unsigned int order,int* visited,int* parent,int *cycle)
{
	visited[source]=1;
	if((*cycle)!=1)
	{
		for(int i=0;i<n;i++)
		{
			if((*cycle)!=1)
			{
				if(edges[i].first==source)//first vertex found
				{
					if(visited[edges[i].second]==1)
					{
						if(parent[edges[i].first]!=edges[i].second)
							*cycle=1;
					}
					else
					{
						parent[edges[i].second]=edges[i].first;
						dfs(edges[i].second,edges,n,order,visited,parent,cycle);
					}
				}
			}
		}
	}
}



int DFS(int source, const edge *edges,unsigned int n,unsigned int order,int* visited,int* parent,int *cycle)
{
	parent[source]=-1;
	dfs(source,  edges,n,order,visited,parent,cycle);
	for(int i=0;i<order;i++)
	{
		if(visited[i]!=1)
			dfs(i,edges,n,order,visited,parent,cycle);
	}
	return *cycle;
}

unsigned int cycle_finder(const edge *edges , unsigned int n, unsigned int order)
{
	int *visited=calloc(sizeof(int),order);
	int *parent=calloc(sizeof(int),order);
	int source=0;
	int cycle=0;
	DFS(source,edges,n,order,visited,parent,&cycle);
	return cycle;
}
 
/* DO NOTE THAT THE GRAPH TRAVERSAL IN THIS QUESTION ALWAYS STARTS WITH NODE 0  so you need not take any input for starting node */
int main(void)
{
    unsigned int order;  /* number of vertices */
    unsigned int n; /* number of edges */
    scanf("%d", &n);
    scanf("%d", &order);
    edge *edges;
    unsigned int ans;
    edges = malloc(n*sizeof(edge));
    if(edges==NULL)
    {
        return 1;
    }
    for(int i=0;i<n;++i)
    {
        scanf("%d", &edges[i].first);
        scanf("%d", &edges[i].second);
    }
        
    ans= cycle_finder(edges, n, order);
    printf("\n");
    printf(ans? "cyclic":"acyclic");
    printf("\n");
    free(edges);
    return 0;

}
