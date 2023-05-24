//implementation of queue
#include<stdio.h>
#include<stdlib.h>
struct queue
{
int front;
int rear;
int *ptr_s;
int size;
};
typedef struct queue queue;
void create_queue(queue * ptr_Q)
{
ptr_Q->front=-1;
ptr_Q->rear=-1;
ptr_Q->ptr_s=malloc(sizeof(int)*ptr_Q->size);
}
void insertQ(queue *ptr_Q,int ele)
{
if(ptr_Q->rear!=ptr_Q->size-1)//queue is not full
{
ptr_Q->rear+=1;
ptr_Q->ptr_s[ptr_Q->rear]=ele;
if(ptr_Q->front==-1)
{
ptr_Q->front+=1;
}
}
else
printf("Queue full\n");
}

int deleteQ(queue *ptr_Q)
{
int ele;
if(ptr_Q->front==-1)//reseting option
return -999;
else
{
ele=ptr_Q->ptr_s[ptr_Q->front];
ptr_Q->front=ptr_Q->front+1;
if(ptr_Q->front==ptr_Q->rear+1)//last element deletion
ptr_Q->front=ptr_Q->rear=-1;
return ele;
}
}
void display(queue ptr)
{
//printf("%d,%d",ptr.front,ptr.rear);
if(ptr.front==-1)
printf("Empty queue\n");
else
{
while(ptr.front!=ptr.rear+1)
{
printf("%d\n",ptr.ptr_s[ptr.front]);
ptr.front=ptr.front+1;
}
}
}
int main()
{
queue Q;
printf("Enter the size of the queue\n");
scanf("%d",&Q.size);
create_queue(&Q);
int choice;
int del;
int ele;
while(1)
{
printf("Enter:\n1. for insert\n2. for delete\n3. for display\n4. to exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("Enter the element\n");
scanf("%d",&ele);
insertQ(&Q,ele);
break;
case 2:del=deleteQ(&Q);
if(del!=-999)
printf("Deleted element:%d\n",del);
else
printf("Cannot delete empty queue\n");
break;
case 3:printf("The Queue display:\n");
display(Q);
break;
case 4:exit(0);
break;
default:printf("Wrong choice\n");
}
}
return 0;
}

