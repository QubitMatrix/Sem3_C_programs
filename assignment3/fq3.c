#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct cache
{
        int capacity;
        // declare some additional data-structure(s) here if necessary
        int lru;
	int *hash;
	int *lru_arr;
	int access_count;
	int ptr;
} cache_t;
  
int search(cache_t* cache,unsigned data)
{
	int count=0;
	int index=data%cache->capacity;
	while(count<cache->capacity  && cache->hash[index]!=data)
	{
		count++;
		index=(index+1)%cache->capacity;
	}
	if(cache->hash[index]==data)
		return index;
	else
		return -1;
}
void access(cache_t* cache, unsigned data)
{
        // TODO
	int index=data%cache->capacity;
	if(cache->lru==-1)
	{
		cache->lru_arr[cache->access_count++]=data;
		cache->lru=data;
		cache->ptr=1;
	}
	if(cache->hash[index]==data || (search(cache,data)!=-1))
	{
		if(cache->lru==data)
		{
			cache->lru=cache->lru_arr[++(cache->ptr)];
			cache->lru_arr[cache->access_count++]=data;
//			printf("lru%d %d %d\n",cache->lru,cache->ptr,cache->lru_arr[cache->ptr+1]);
		}
		else
		{
			int* temp=calloc(cache->capacity,sizeof(int));
			int x=0;
			int xx=0;
			while(cache->lru_arr[x]!=data)
			{
				temp[xx]=cache->lru_arr[x];
				x++;
				xx++;
			}
			while(cache->lru_arr[x]!=0)
			{
				temp[xx]=cache->lru_arr[x];
				x++;
				xx++;
			}
			 x=0;
			while(x<xx)
			{
				cache->lru_arr[x]=temp[x];
				x++;
			}

		}
	}
	else{
	if(cache->hash[index]==0)
	{

		cache->hash[index]=data;
		cache->lru_arr[cache->access_count++]=data;
	}
	else
	{
		int count=1;
		int newindex=index;
		while(count<=cache->capacity &&  cache->hash[newindex]!=0)
		{
			count++;
			newindex=(index+count)%cache->capacity;
		}
		if(cache->hash[index]==0)
			cache->hash[newindex]=data;
		else
		{
			cache->hash[search(cache,cache->lru)]=data;
		}
		cache->ptr++;
		cache->lru=cache->lru_arr[cache->ptr];
		cache->lru_arr[cache->access_count++]=data;
	}
	
	}



}


int LRU(cache_t* cache)
{
        // TODO
	return cache->lru;
}


cache_t* init_cache(int capacity)
{
        cache_t* c = (cache_t*)malloc(sizeof(cache_t));  // 1st line
        c->capacity = capacity;                                // 2nd line
        // TODO
        // if cache_t structure was added with more data-structure(s), initialize them here
        c->lru=-1;
	c->access_count=0;
	c->ptr=0;
	c->lru_arr=calloc(100,sizeof(int));
	c->hash=calloc(capacity,sizeof(int));
	return c;
}


void free_cache(cache_t* c)
{
        // TODO
        // if cache_t structure was added with more data-structure(s), free the heap space it consumes, if any, here
        free(c->hash);
	free(c->lru_arr);
	free(c); // last line
}


// Driver program to test above functions
int main()
{
        int capacity;
        scanf("%d", &capacity);
        int T;
        scanf("%d", &T);
        char op[10];
        int data;
        cache_t* cache = init_cache(capacity);
        
        while(T--)
        {        
                scanf("%s", op);
                if(!strcmp(op, "access"))
                {
                        scanf("%d", &data);
                        access(cache, data);
                }
                else
                {
                        printf("%d\n", LRU(cache));
                }        
        }
        
        free_cache(cache);
  
            return 0;
}
