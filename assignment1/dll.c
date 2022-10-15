#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
 
list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
{
	node_t* newnode;
	newnode=malloc(sizeof(node_t));
	newnode->next=newnode->prev=NULL;
	newnode->data=data;
	if(list->head==NULL)
	{
		list->head=list->tail=newnode;
	}
	else
	{
		newnode->next=list->head;
		list->head->prev=newnode;
		list->head=newnode;
	}
	list->size=list->size+1;

}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
	node_t* newnode;
	newnode=malloc(sizeof(node_t));
	newnode->next=newnode->prev=NULL;
	newnode->data=data;
	if(list->head==NULL)
	{
		list->head=list->tail=newnode;
		list->size=list->size+1;
	}
	else
	{
		list->tail->next=newnode;
		newnode->prev=list->tail;
		list->tail=newnode;
	}
	list->size=list->size+1;
}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
	node_t* dhead;
	dhead=list->head;
	while(dhead!=NULL)
	{
		if(dhead->data==prev)
		{
			node_t *newnode;
			newnode=malloc(sizeof(node_t));
			newnode->next=newnode->prev=NULL;
			newnode->data=data;
			if(dhead->next!=NULL)
			{
				newnode->next=dhead->next;
				dhead->next->prev=newnode;
			}
			else
				list->tail=newnode;
			newnode->prev=dhead;
			dhead->next=newnode;
			list->size=list->size+1;
			break;
		}
		dhead=dhead->next;
	}
}

void delete_front(list_t* list) // TODO: delete the start node from the linked list.
{
	node_t *delnode;
	int element;
	if(list->head==NULL)
		return;
	if((list->head)->next==NULL)
	{
		delnode=list->head;
		list->head=NULL;
		element=delnode->data;
		free(delnode);
		delnode=NULL;
		list->size--;
	}
	else
	{
		delnode=list->head;
		list->head=(list->head)->next;
		element=delnode->data;
		(list->head)->prev=NULL;
		free(delnode);
		delnode=NULL;
		list->size--;
	}
}

void delete_back(list_t* list) // TODO: delete the end node from the linked list.
{
	node_t* delnode;
	if(list->tail!=NULL)
	{
		delnode=list->tail;
		list->tail->prev->next=NULL;
		list->tail=list->tail->prev;
		free(delnode);
	}
	list->size=list->size-1;
}

void delete_node(list_t* list, int data) // TODO: delete the node with “data” from the linked list.
{
	node_t* dhead,*delnode;
	dhead=list->head;
	while(dhead!=NULL)
	{
		if(dhead->data==data)
		{
			if(dhead==list->head)
			{
				delete_front(list);
				break;
			}
			else if(dhead==list->tail)
			{
				delete_back(list);
				break;
			}
			else
			{
				delnode=dhead;
				dhead->prev->next=dhead->next;
				dhead->next->prev=dhead->prev;
				free(delnode);
				list->size=list->size-1;
				break;
			}
			
		}
		dhead=dhead->next;
	}

}

node_t* search(list_t* list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{
	node_t* dhead;
	dhead=list->head;
	while(dhead!=NULL)
	{
		if(dhead->data==data)
			return dhead;
		dhead=dhead->next;
	}
	return NULL;

}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t* it = list->head;
	while(it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}
