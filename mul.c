//DMA:using double pointer
 #include<stdio.h>
 #include<stdlib.h>
void mul(int **a,int **b,int **c,int r1,int c1,int c2)
{
for(int i=0;i<r1;i++)
{
for(int j=0;j<c2;j++)
{
c[i][j]=0;
for(int k=0;k<c1;k++)
{
*(*(c+i)+j)+=*(*(a+i)+k)*(*(*(b+k)+j));
}
}
}
}
int** allocat(int r,int c)
{
int **ptr;
ptr=malloc(r*sizeof(int*));
for(int i=0;i<c;i++)
{
ptr[i]=malloc(c*sizeof(int));
}
return ptr;
}
void inp(int **ptr,int r,int c)
{
for(int i=0;i<r;i++)
{
for(int j=0;j<c;j++)
{
scanf("%d",(*(ptr+i)+j));
}
}
}
void out(int **ptr,int r,int c)
{
for(int i=0;i<r;i++)
{
for(int j=0;j<c;j++)
{
printf("%d ",*(*(ptr+i)+j));
}
printf("\n");
}
}
int main()
{

int r1,c1,r2,c2;
int **ma,**mb,**mc;
printf("Enter the row1 col1 ro2 col2\n");
scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
ma=allocat(r1,c1);
mb=allocat(r2,c2);
mc=allocat(r1,c2);
printf("Enter elements of first\n");
inp(ma,r1,c1);
printf("Enter elements of second\n");
inp(mb,r2,c2);
mul(ma,mb,mc,r1,c1,c2);
printf("Multiplied matrix:\n");
out(mc,r1,c2);
return 0;
}
