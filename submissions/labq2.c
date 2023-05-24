//write a c program to write multiple lines in a text file
#include <stdio.h>
int main()
{
FILE *fp=fopen("text.txt","a");
char ch;
while((ch=getc(stdin))!=EOF)
{
fputc(ch,fp);
}
fclose(fp);
FILE *fp1=fopen("text.txt","r");
while((ch=fgetc(fp1))!=EOF)
{
printf("%c",ch);
}
fclose(fp1);
return 0;
}

