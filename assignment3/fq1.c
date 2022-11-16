#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;


node* createLinkedList(int n, int *arr){
    node *head = NULL, *iter = NULL, *newNode = NULL;
    
    node* dummyhead = (node*)malloc(sizeof(node));
    dummyhead->next = NULL;
    dummyhead->data = 0;
    head = dummyhead;
    iter = head;

    for(int i = 0; i < n; i++){
        newNode = (node*)malloc(sizeof(node));
        newNode->data = arr[i];
        newNode->next = NULL;
        iter->next = newNode;
        iter = iter->next;
    }

    return head->next;
}


void insert(node *head, int pos, int data){
    // TODO: Insert the data at given pos in the linked list
    pos=pos+1;
    node* prev=NULL;
    node* newnode=malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    if(pos==1)
    {
	   // newnode->data=data;
	   // newnode->next=head;
	    head=newnode;
    }
    else
    {
	    int i=1;
	    while(head!=NULL && i<pos)
	    {
		    prev=head;
		    head=head->next;
		    i++;
    	    }
   	    if(i==pos)
	    {
		   // printf("%d %d\n",prev->data,newnode->data);
		    prev->next=newnode;
		    newnode->next=head;
	    }
    }
}


void delete(node *head){
    // TODO: Delete alternate nodes starting at index 1
    node* dhead=malloc(sizeof(node));
    dhead=head->next;
    node* temp;
    node* prev=head;
    while(dhead!=NULL)
    {
	    temp=dhead->next;
		    prev->next=dhead->next;
		    prev=dhead->next;
		    free(dhead);
		    if(temp!=NULL)
			    dhead=temp->next;
		    else
			    dhead=NULL;
//		    printf("%d %d %d %d\n",prev->data,head->data,temp->data,dhead->data);
	   
    }
    
}


int countNodes(node *head){
    // TODO: Count the number of nodes in the given list
    int count=0;
    while(head!=NULL)
    {
	    count++;
	    head=head->next;
    }
    return count;

}


void printList(node *head){
    if(head == NULL){
        printf("List empty!\n");
    }
    node *iter = head;
    while(iter != NULL){
        printf("%d ", iter->data);
        iter = iter->next;
    }
    printf("\n");
}


int main(){

    int no_of_nodes;
    scanf("%d",&no_of_nodes);

    int *arr = (int *)malloc(no_of_nodes*sizeof(int));
    for(int i=0;i<no_of_nodes;i++){
        scanf("%d",&arr[i]);
    }   

    node *head = createLinkedList(no_of_nodes, arr);

    int testcases;
    scanf("%d",&testcases);
    int position, data;

    for(int i = 0; i < testcases; i++){
        int operation;
        scanf("%d",&operation);
        switch(operation){
            case 1:
                // Insert at the given position 
                scanf("%d %d", &position, &data);
                insert(head, position, data);
                break;
            case 2:
                // Delete alternate nodes, starting from the node at index position 1
                delete(head);
                break;
            case 3:
                // Count the number of nodes
                no_of_nodes = countNodes(head);
                printf("%d \n", no_of_nodes);
                break;
            case 4:
                // Print the list
                printList(head);
                break;
        }
    }
    return 0;
}
