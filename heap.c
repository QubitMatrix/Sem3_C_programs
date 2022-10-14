#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int firstfill(int *arr)
{
	int ele;
	printf("Enter:");
	scanf("%d",&ele);
	int x=0;
	while(ele!=-1)
	{
		arr[x]=ele;
		x++;
		printf("Enter:");
		scanf("%d",&ele);
		//printf("Enter:-%d",ele);
		
	}
	return x;
}
void swap(int * arr,int p,int c)
{
	int temp=arr[p];
	arr[p]=arr[c];
	arr[c]=temp;
}
void construction(int *arr,int x)
{
	int p=x/2-1;
	while(1)//x/2-1 to 0 
	{
		int temp=p;
		while(1)//each parent swap should check if it caused any invalid furhter occurances till last child
		{
			int lc=2*p+1;
			//printf("%d %d\n",arr[p],arr[lc]);
			int rc;
			int min1;
			int flag;
			if(2*p+2<=x-1)//check if right child exists,if parent then left def exists
			{
				rc=2*p+2;
				min1=(arr[lc]<=arr[rc])?lc:rc;//choose min child
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
			if(arr[p]<=arr[min1])//check if parent lesser than min child
				flag=0;
			else
				swap(arr,p,min1);
			if(flag==0)//if no swap then no changes so break
				break;
			else if(flag==1)//check till last child, if left was swapped pass through left subtree
			{
				if(2*lc+1<=x-1)
				{
		 			p=lc;
		 			continue;
		 		}
		 		else
		 			break;
			}
			else
			{
				if(2*rc+1<=x-1)
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
int delete(int *arr,int *len)
{
	int res=arr[0];
	arr[0]=arr[(*len)-1];//replace head with last element
	int p=0;
	/*can find parent of element that replaced head
	int del=*len-1;
	int del_p;
	if(del%2==0)
	del_p=(del-2)/2;
	else
	del_p=(del-1)/2;
	*/
	(*len)--;
	while(1)
		{
			int lc=2*p+1;
			int rc;
			int min1;
			int flag;
			if(2*p+2<=(*len)-1)
			{
				rc=2*p+2;
				min1=(arr[lc]<arr[rc])?lc:rc;
				if(min1==rc)
					flag=2;
				else
					flag=1;
			}
			else
			{
				rc=-1;
				min1=lc;
				flag=1;
			}
			if(arr[p]<=arr[min1])
				flag=0;
			else
				swap(arr,p,min1);
			if(flag==0)
				break;
			else if(flag==1)
			{
				if(2*lc+1<=(*len)-1)
				{
		 			p=lc;
		 			continue;
		 		}
		 		else
		 			break;
			}
			else
			{
				if(2*rc+1<=(*len)-1)
				{
					p=rc;
					continue;
				}
				else
		 			break;
			}
	}
	return res;
}

int main()
{
	int arr[MAX];
	int len=firstfill(arr);
	printf("Number of elements:%d\n",len);
	printf("Before swaps:\n");
	for(int i=0;i<len;i++)
		printf("%d\n",arr[i]);
	construction(arr,len);
	printf("After construction\n");
	for(int i=0;i<len;i++)
		printf("%d\n",arr[i]);
	while(len!=0)//gives descending order
	{
		int del=delete(arr,&len);
		printf("Deleted element:%d\n",del);
		printf("Heap after deletion\n");
		for(int i=0;i<len;i++)
			printf("%d\n",arr[i]);
	}
	return 0;
}
