#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap MinHeap;
struct MinHeap {
    int* arr;
    int size;  //size of the heap
};


MinHeap* init_minheap(int size) {
    MinHeap* minheap = (MinHeap*)calloc(1, sizeof(MinHeap));
    minheap->size = size;
    minheap->arr = (int*)calloc(size, sizeof(int));
    return minheap;
}

void create_minheap(MinHeap *heap) 
{   
    //IMPLEMENT HERE
	int p=heap->size/2-1;
	while(1)//n/2-1 to 0 
	{
		if(heap->size==1||heap->size==0)
        break;
        int temp=p;
		while(1)//each parent swap should check if it caused any invalid furhter occurances till last child
		{
			int lc=2*p+1;
			//printf("%d %d\n",heap->arr[p],heap->arr[lc]);
			int rc;
			int min1;
			int flag;
			if(2*p+2<=(heap->size)-1)//check if right child exists,if parent then left def exists
			{
				rc=2*p+2;
				min1=((heap->arr)[lc]<=(heap->arr)[rc])?lc:rc;//choose max child
				if(min1==rc)
					flag=2;//1 means left 2 is right
				else
					flag=1;
			}
			else
			{
				rc=-1;
				min1=lc;
				flag=1;
			}
			if((heap->arr)[p]<(heap->arr)[min1])//check if parent lesser than max child
				flag=0;
			else
			{
				int temp1=heap->arr[p];
				heap->arr[p]=heap->arr[min1];
				heap->arr[min1]=temp1;//swap((heap->arr),p,min1);
			}
			if(flag==0)//if no swap then no changes so break
				break;
			else if(flag==1)//check till last child, if left was swapped pass through left subtree
			{
				if(2*lc+1<=(heap->size)-1)
				{
		 			p=lc;
		 			continue;
		 		}
		 		else
		 			break;
			}
			else
			{
				if(2*rc+1<=(heap->size)-1)
				{
					p=rc;
					continue;
				}
				else
		 			break;
			}
		}
		p=temp-1;
		if(p==-1)
			break;
	}
}



void print_minheap(MinHeap* heap) {
    // IMPLEMENT HERE
    for(int i=0;i<heap->size;i++)
			printf("%d ",(heap->arr)[i]);
}

void free_minheap(MinHeap* heap) {
    if (!heap)
        return;
    free(heap->arr);
    free(heap);
}

int main() {

    int capacity; 
    scanf("%d", &capacity);
    MinHeap* heap = init_minheap(capacity); //number of elements 
    int i=0;
    while(i < capacity){
        scanf("%d", &heap->arr[i++]);

    }
    create_minheap(heap);
    print_minheap(heap);
    free_minheap(heap);
    return 0;
}
