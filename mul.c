//SMA:
#include<stdio.h>
void mul(int c1,int c2;int a[][c1],int b[][c2],int c[][c2],int r1,int c1,int r2,int c2)
{
for(int i=0;i<r1;i++)
{
for(int j=0;j<c2;j++)
{
*(*(c+i)+j)=0;
for(int k=0;k<c1;k++)
{
*(*(c+i)+j)+=*(*(a+i)+k)*(*(*(b+k)+j));
}
}
}
}

void inp(int c;int (*a)[c],int r,int c)
{
for(int i=0;i<r;i++)
{
for(int j=0;j<c;j++)
{
scanf("%d",(*(a+i)+j));
}
}
}
void out(int c;int a[][c],int r,int c)
{
for(int i=0;i<r;i++)
{
for(int j=0;j<c;j++)
{
printf("%d ",*(*(a+i)+j));
}
printf("\n");
}
}
int main()
{

int r1,c1,r2,c2;
int x[]={1,2,3};
int *p=x;
printf("Enter the row1 col1 ro2 col2\n");
scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
int a[r1][c1];int b[r2][c2];int c[r1][c2];
printf("Enter elements of first\n");
inp(a,r1,c1);
//printf("%lu %lu %lu %lu",x[0],*p,x[1],*(p+1));
printf("Enter elements of second\n");
inp(b,r2,c2);
mul(a,b,c,r1,c1,r2,c2);
printf("Multiplied matrix:\n");
out(c,r1,c2);
return 0;
}

