#include<stdio.h>
#include<stdlib.h>
int read_bst(int *arr,int *nodes)
{
	int key;
	scanf("%d",&key);
	int p=0;
	int count=1;
	arr[p]=key;
	int max1=0;
	while(key!=-1)
	{
		scanf("%d",&key);
		if(key==-1)
			break;
		p=0;
		while(1)
		{
			if(arr[p]>key)
				p=2*p+1;
			else if(arr[p]<key)
				p=2*p+2;
			if(arr[p]==0)
			{
				count++;
				if(p>max1)
					max1=p;
				arr[p]=key;
				break;
			}
		}
	}
	*nodes=count;
	return max1;
}
void level_order(int *arr,int count)
{
	for(int i=0;i<count;i++)
	{
		if(arr[i]!=0)
			printf("%d ",arr[i]);
	}
}
void inorder(int* arr,int p,int count)
{
	if(p<=count)
	{
		inorder(arr,2*p+1,count);
		if(arr[p]!=0)
			printf("%d ",arr[p]);
		inorder(arr,2*p+2,count);
	}
}
void preorder(int* arr,int p,int count)
{
	if(p<=count)
	{
		if(arr[p]!=0)
			printf("%d ",arr[p]);
		preorder(arr,2*p+1,count);
		preorder(arr,2*p+2,count);
	}
}
void postorder(int* arr,int p,int count)
{
	if(p<=count)
	{
		postorder(arr,2*p+1,count);
		postorder(arr,2*p+2,count);	
		if(arr[p]!=0)
			printf("%d ",arr[p]);
	}
}
int main()
{
	int* arr=calloc(100,sizeof(int));
	int nodes=0;
	int count=read_bst(arr,&nodes);
	printf("max,count:%d,%d\n",count,nodes);
	count=count+1;
	printf("Levelorder\n");
	level_order(arr,count);
	printf("\nInorder\n");
	inorder(arr,0,count);
	printf("\nPreorder\n");
	preorder(arr,0,count);
	printf("\nPostorder\n");
	postorder(arr,0,count);
	printf("\n");
	return 0;
}
