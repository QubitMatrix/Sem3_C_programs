struct Sample
{ int a; 
 int *b; 
};
#include<stdio.h> 
int main()
{
struct Sample s;
s.a = 100;
s.b = &(s.a);
printf("%d %d",s.a,*(s.b)); 
struct Sample s1;
s1.a = 100;
s1.b = &(s1.a);
printf("%d %d\n",s1.a,*(s1.b)); 
struct Sample s2 = s1; 
printf("%p %p\n",s1.b,s2.b);
printf("%d %d\n",s2.a,*(s2.b)); 
s2.a = 200;
printf("%p %p\n",s1.b,s2.b);
printf("%d %d\n",s1.a,*(s1.b));
printf("%d %d\n",s2.a,*(s2.b)); // very imp
*(s2.b) = 300;
printf("%p %p\n",s1.b,s2.b);
printf("%d %d\n",s1.a,*(s1.b));
printf("%d %d\n",s2.a,*(s2.b)); 
s2.b = &(s2.a);
*(s2.b) = 400;
printf("%p %p\n",s1.b,s2.b);
printf("%d %d\n",s1.a,*(s1.b));
printf("%d %d\n",s2.a,*(s2.b));
return 0;
}
