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
	while(1)
	{
		int temp=p;
		while(1)
		{
			int lc=2*p+1;
			int rc;
			int max1;
			int flag;
			if(2*p+2<=x-1)
			{
				rc=2*p+2;
				max1=(arr[lc]<arr[rc])?rc:lc;
				if(max1==rc)
					flag=2;
				else
					flag=1;
			}
			else
			{
				rc=-1;
				max1=lc;
				flag=1;
			}
			if(arr[p]>=arr[max1])
				flag=0;
			else
				swap(arr,p,max1);
			if(flag==0)
				break;
			else if(flag==1)
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
int main()
{
	int arr[MAX];
	int x=firstfill(arr);
	printf("Number of elements:%d\n",x);
	printf("Before swaps:\n");
	for(int i=0;i<x;i++)
		printf("%d\n",arr[i]);
	construction(arr,x);
	printf("After construction\n");
	for(int i=0;i<x;i++)
		printf("%d\n",arr[i]);
	return 0;
}
