#include <stdio.h>
#include<stdlib.h>
#define SIZE 13

void insertIntoHash(int key, int *hashtable)
{
    // TODO
    int index=key%SIZE;
    if(hashtable[index]==0)
    {
	    hashtable[index]=key;
    }
    else
    {
	    int newindex=index;
	    int count=0;
	    int prob=1;
	    while(hashtable[newindex]!=0 && count<13)
	    {
		newindex=index+prob*(11-(key%11))%13;
	    	prob++;
		count++;
	    }
	    if(count==SIZE)
		    printf("-1\n");
	    else
		    hashtable[newindex]=key;
    }
}

void printHashTable(int *hashtable)
{
    // TODO
    for(int i=0;i<13;i++)
	    printf("%d ",hashtable[i]);
    printf("\n");
}

int main()
{
    int i;
    int h[SIZE]={0};

    int n;
    scanf("%d", &n);

    int stk[n];
    for(int k=0;k<n;k++){
        scanf("%d", &stk[k]);
    }

    for(int i=0;i<n;i++){
        insertIntoHash(stk[i], h);
    }

    printHashTable(h);

    return 0;
}
