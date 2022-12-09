/**#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node node;
node *allocatenode(int ele)
{
    node *ptr;
    ptr = malloc(sizeof(node));
    ptr->data = ele;
    ptr->link = NULL;
    return ptr;
}
void insert_at_front(node **ptrhead, int ele)
{
    node *newnode;
    newnode = allocatenode(ele);
    if (*ptrhead == NULL)
    {
        *ptrhead = newnode; // printf("%d",newnode->data);
    }
    else
    {
        newnode->link = *ptrhead;
        *ptrhead = newnode;
    }
}
void display(node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->link;
    }
    printf("\n");
}

void insert_at_end(node **ptrhead, int ele)
{
    node *newnode;
    newnode = allocatenode(ele);
    if (*ptrhead == NULL)
        *ptrhead = newnode;
    else
    {
        node *dhead;
        dhead = *ptrhead;
        while (dhead->link != NULL)
        {
            dhead = dhead->link;
        }
        dhead->link = newnode;aaa
    }
}

void insert_at_pos(node **ptrhead, int ele, int pos)
{
    node *dhead;
    if (pos == 1)
        insert_at_front(ptrhead, ele);
    else
    {
        node *newnode;
        newnode = allocatenode(ele);
        dhead = *ptrhead;
        int i = 1;
        while (i < pos - 1 && dhead->link!=NULL)
        {
            i++;
            dhead = dhead->link;
        }
        if (i == pos - 1)
        {
            if (dhead->link == NULL)
                insert_at_end(ptrhead, ele);
            else
            {
                //printf("a");
                node *temp;
                temp = dhead->link;
                // dhead->data=ele;
                dhead->link = newnode;
                newnode->link = temp;
            }
        }
        else
        {
            printf("invalid insertion");
        }
    }
}

int main()
{
    node *head;

    head = NULL;
    int ele;
    int c;
    int pos;
    printf("Enter 1 to insert in beginning 2 for end 3 for insert in position(ele pos) and 4 to display 5 to exit\n");
    while (1)

    {
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            scanf("%d", &ele);
            insert_at_front(&head, ele);
            break;
        case 2:
            scanf("%d", &ele);
            insert_at_end(&head, ele);
            break;
        case 3:
            pos;
            scanf("%d %d", &ele, &pos);
            insert_at_pos(&head, ele, pos);
            break;
        case 4:
            display(head);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("invalid");
        }
    }
    return 0;
}
**/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node node;
node *allocatenode(int ele)
{
    node *ptr;
    ptr = malloc(sizeof(node));
    ptr->data = ele;
    ptr->link = NULL;
    return ptr;
}
int insert_at_front(node **ptrhead, int ele)
{
    node *newnode;
    newnode = allocatenode(ele);
    if (newnode == NULL)
        return 0;
    else
    {
        if (*ptrhead == NULL)
        {
            *ptrhead = newnode; // printf("%d",newnode->data);
        }
        else
        {
            newnode->link = *ptrhead;
            *ptrhead = newnode;
        }
        return 1;
    }
}
void display(node *head)
{
    int i=0;
    while (head != NULL)
    {
        i++;
        printf("%d ", head->data);
        head = head->link;
    }
    printf("\nSize:%d\n",i);
}

int insert_at_end(node **ptrhead, int ele)
{
    node *newnode;
    newnode = allocatenode(ele);
    if (newnode == NULL)
        return 0;
    else
    {
        if (*ptrhead == NULL)
            *ptrhead = newnode;
        else
        {
            node *dhead;
            dhead = *ptrhead;
            while (dhead->link != NULL)
            {
                dhead = dhead->link;
            }
            dhead->link = newnode;
            
        }
        return 1;
    }
}

int insert_at_pos(node **ptrhead, int ele, int pos)
{
    node *dhead;
    int res;
    if (pos == 1)
        res=insert_at_front(ptrhead, ele);
    else
    {
        node *newnode;
        newnode = allocatenode(ele);
        if(newnode==NULL)
        res=0;
        else
        {dhead = *ptrhead;
        int i = 1;
        while (i < pos - 1 && dhead->link!=NULL)
        {
            i++;
            dhead = dhead->link;
        }
        if (i == pos - 1)
        {
            if (dhead->link == NULL)
                res=insert_at_end(ptrhead, ele);
            else
            {
                //printf("a");
                node *temp;
                newnode->link = dhead->link;
                // dhead->data=ele;
                dhead->link = newnode;
                //= temp;
                res=1;
            }
        }
        else
        {
            printf("invalid insertion\n");
            res=0;
        }
        }
    }
    return res;
}
int delete_front(node **ptrhead)
{
    if(*ptrhead==NULL)
    return -1;
    else
    {
        node *delnode;
    delnode=*ptrhead;
    *ptrhead=(*ptrhead)->link;
    int ele;
    ele=delnode->data;
    free(delnode);
    delnode=NULL;
    return ele;
    }
}
int delete_end(node **ptrhead)
{
    node* prev;
    int ele;
    if(*ptrhead==NULL)
    return -1;
    else
    {node *dhead;
    dhead=*ptrhead;
    prev=NULL;
    while(dhead->link!=NULL)
    {
        prev=dhead;
        dhead=dhead->link;
    }
    ele=dhead->data;
    free(dhead);
    //dhead=NULL;
    if(prev)
    {
        prev->link=NULL;
    }
    if(!prev)
    *ptrhead=NULL;
    return ele;
    }
}
int delete_key(node **ptrhead,int key)
{
    node* prev;
    int ele;
    if(*ptrhead==NULL)
    return -1;
    else
    {node *dhead;
    dhead=*ptrhead;
    prev=NULL;
    while(dhead->link!=NULL)
    {
        prev=dhead;
        if(dhead->data==key)
        break;
        dhead=dhead->link;
    }
    ele=dhead->data;
    node *link;
    link=dhead->link;
    free(dhead);
    //dhead=NULL;
    if(prev)
    {
        prev->link=link;
    }
    return ele;
    }
}
int main()
{
    node *head;

    head = NULL;
    int ele;
    int c;
    int pos;
    int res;
    int key;
    printf("Enter:\n1. to insert in beginning\n2. for end insert\n3. for insert in position(ele pos)\n4 .to display\n5.to delete at front\n6. to delete at end\n7.to delete key\n8.to exit");
    while (1)

    {
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            scanf("%d", &ele);
            res=insert_at_front(&head, ele);
            if(res) printf("insert successful\n");
            else printf("insert failed\n");
            break;
        case 2:
            scanf("%d", &ele);
            res=insert_at_end(&head, ele);
            if(res) printf("insert successful\n");
            else printf("insert failed\n");
            break;
        case 3:
            scanf("%d %d", &ele, &pos);
            res=insert_at_pos(&head, ele, pos);
            if(res) printf("insert successful\n");
            else printf("insert failed\n");
            break;
        case 4:
            display(head);
            break;
        case 5:res=delete_front(&head);
        printf("Deleted elemnet is:%d\n",res);
            break;
        case 6:res=delete_end(&head);
        printf("Deleted element is:%d\n",res);
        break;
        case 7:
        scanf("%d",&key);
        res=delete_key(&head,key);
        printf("The deleted element is:%d\n",res);
        break;
	case 8:exit(0);
	       break;
        default:
            printf("invalid");
        }
    }
    return 0;
}

