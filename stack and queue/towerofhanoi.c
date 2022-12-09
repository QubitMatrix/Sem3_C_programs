#include <stdio.h>
int count=0;
void toi(int n,int A,int B,int C)
{
	if(n==1)
	{
		count+=1;
		printf("Move disk from %d -> %d\n",A,C);
	}
	else
	{
		toi(n-1,A,C,B);
		toi(1,A,B,C);
		toi(n-1,B,A,C);
	}
}

int main()
{
	int n;
	printf("Enter the number of disks\n");
	scanf("%d",&n);
	toi(n,1,2,3);
	return 0;
}
