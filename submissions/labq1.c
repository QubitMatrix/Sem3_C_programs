//write a c program to merge contents of two files into a third file
#include<stdio.h>
int main()
{
char f1[100];
char f2[100];
char f3[100];
scanf("%s",f1);
scanf("%s",f2);
scanf("%s",f3);
FILE *fp1=fopen(f1,"r");
FILE *fp2=fopen(f2,"r");
FILE *fp3=fopen(f3,"a");
char ch;

while((ch=fgetc(fp1))!=EOF)
{
fputc(ch,fp3);
}
while((ch=fgetc(fp2))!=EOF)
{
fputc(ch,fp3);
}
fclose(fp1);
fclose(fp2);
fclose(fp3);
return 0;
}
