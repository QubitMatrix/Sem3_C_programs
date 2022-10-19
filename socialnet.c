#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<stdbool.h>
#define MAX 100

typedef struct node 
{
    int id; //ID of user
    int numfren; //number of friends of user
    char name[MAX]; //name of user
    int* friends; //friends of user as an array
    struct node* right;  //user to the right
    struct node* left; //user to the left
} node;

struct node* retUser(char str[MAX])
{
    char name[MAX];
    char ID[MAX];
    char strfriends[MAX];

    //copied ID
    char*token=strtok(str,",");
    strcpy(ID,token);

    //copied Name
    token=strtok(NULL,",");
    strcpy(name,token);

    //copied friends' ID
    token=strtok(NULL,",");
    strcpy(strfriends,token);
    //printf("%s\n",(strfriends));

    //creating user nodes
    int id=atoi(ID);
    struct node *user = malloc(sizeof(struct node));
    user->id=id;
    user->friends=(int*)malloc(MAX * sizeof(int));
    strcpy(user->name,name);


    //adding user's friend's IDs
    token = strtok(strfriends,"|");  
    int i=0;
    while( token != NULL ) 
    {

        int temp=atoi(token);
        user->friends[i]=temp;
        i++;
        token = strtok(NULL,"|");
    }
    user->numfren=i;
    if(i==0){user->friends[i]=-1;}
    return user;
}


//search for user with id=key
struct node* search(int key, struct node *users)
{
    //CODE HERE
    struct node* temp;
    while(users!=NULL)
    {
	    if(key<users->id)
	    {
		    users=users->left;
	    }
	    else if(key>users->id)
	    {
		    users=users->right;
	    }
	    else
	    {
	    	    temp=users;
	    	    break;
	    }
    }
    if(users==NULL)
	    return NULL;//printf("Not found");
    else
	    return temp;//printf("Found");

}

//see document for explanattion
struct node*refineUser(struct node*user, struct node *users)
{
    //CODE HERE
    int pos;
    int del=0;
    struct node* search1;
    while(1)
    {
	    search1=search(user->id,users);
	    
	    if(search1==NULL)
		    break;
	    else
	    {
		    user->id++;
		    search1=search(user->id,users);
	    }
    }
    printf("a%d\n",user->numfren);
    for(int j=0;j<user->numfren;j++)
    {
	    printf("z%d\n",user->friends[j]);
	    search1=search(user->friends[j],users);
	    if(search1==NULL)
	    {
		for(int x=0;x<user->numfren;x++)
		{
			if(user->friends[x]==user->friends[j])
				pos=x;
		}
		for(int x=pos;x<user->numfren-1;x++)
			user->friends[x]=user->friends[x+1];
	        del++;	
		user->numfren--;
		j--;

	    }
	    else
	    {
	    //printf("zz%d\n",search1->numfren);
	   
		  search1->friends[search1->numfren++]=user->id;
	    //printf("zz%d\n",search1->numfren);
	   
	    }
    }
    //user->numfren-=del;
		if(user->numfren==0)
			user->friends[0]=-1;
    printf("c%d %d\n",user->numfren,user->id);
    return user;


}

//insert user with id
struct node* insertUser(struct node*root,int id,struct node*user)
{
   //CODE HERE
   //struct node* newnode=malloc(sizeof(struct node));
	//printf("a%d\n",root->id);
	if(root==NULL)
	{
//		newnode->left=newnode->right=NULL;
		//newnode;
		root=user;
	}
	else 
	{
		if(id<root->id)
		{ 
			if(root->left!=NULL)
				insertUser(root->left,id,user);
			else
			{
				//printf("x%d\n",root->id);
//				newnode->left=newnode->right=NULL;
//				newnode->id=id;
				root->left=user;
			}
		}
		else if(id>root->id)
		{
			if(root->right!=NULL)
				insertUser(root->right,id,user);
			else//without else it gets excuted for each iteration therefore newnode added to main root at the end of function      
			{
				//printf("xx%d\n",root->id);
//		        	newnode->left=newnode->right=NULL;
//				newnode->id=id;
		 		root->right=user;
			}	
		}
	}
	return root;
}

//prints friends list
void friends(int id, struct node *users) 
{
   //CODE HERE
   struct node* search1=search(id,users);
   if(search1!=NULL)
   {
	   for(int x=0;x<search1->numfren;x++)
		   printf("%d\n",search1->friends[x]);
	   if(search1->numfren==0)
		   printf("-1\n");
   }

}

//find child node with minimum value (inorder successor) - helper to delete node
struct node *minValueNode(struct node *node) {
  //CODE HERE
    struct node* temp;
    temp=node->right;
    while(temp->left!=NULL)
    {
		temp=temp->left;
    }
    return temp;
}

//deletes itself from its friend's nodes
struct node*deleteFriends(int key, struct node*users)
{
    //CODE HERE
    int pos;
	struct node* search1=search(key,users);
	if (search1==NULL)
		return NULL;

	for(int i=0;i<search1->numfren;i++)
	{
		struct node* delsearch=search(search1->friends[i],users);
		for(int x=0;x<delsearch->numfren;x++)
		{
			if(delsearch->friends[x]==key)
				pos=x;
		}
		for(int x=pos;x<delsearch->numfren-1;x++)
			delsearch->friends[x]=delsearch->friends[x+1];
		delsearch->numfren--;

	}
	if(search1->numfren==0)
		search1->friends[0]=-1;


	return users;
    
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  //CODE HERE
  	struct node* prev;
	struct node* replacement;
	prev=NULL;
	struct node* droot;
	droot=root;
	//printf("a");

	while(droot!=NULL)
	{
		if(key<(droot)->id)
		{
			prev=droot;
			droot=(droot)->left;
		}
		else if(key>(droot)->id)
		{
			prev=droot;
			droot=(droot)->right;
		}
		else//if(key==(droot)->id)
		{	
			break;
		}
	}
	if(droot==NULL)
		printf("Missing key");
	else
	{
		if(droot->left==NULL && droot->right==NULL)
		{
			replacement=NULL;
		}
		else if(droot->left==NULL && droot->right!=NULL)
		{
			replacement=droot->right;
		}
		else if(droot->right==NULL && droot->left!=NULL)
		{
			replacement=droot->left;
		}
		else
		{
			
			struct node*temp;
			temp=minValueNode(droot);
			temp->left=droot->left;
			replacement=droot->right;
		}
		if(prev==NULL)
		{
			root=replacement;
			free(droot);
		}
		else if(droot->id>prev->id)
		{
			prev->right=replacement;
	                free(droot);
		}
		else if(droot->id<prev->id)
		{
			prev->left=replacement;
	        	free(droot);
		}
	}
	return root;
}

//Print USER's IDs in ascending order
void printInOrder(node* myusers) 
{
    //CODE HERE
    if(myusers!=NULL)
    {

    	    printInOrder(myusers->left);
    	    printf("%d %s\n",myusers->id,myusers->name);    	    printInOrder(myusers->right);
    }
}


int main(int argc, char **argv)
{
    node *users=NULL;   
    while(1)
    {

        int opt, id;
        fflush(stdin);
        scanf("%d",&opt);
        char str[MAX];
        switch (opt)
        {
            case 1:
      
                scanf("%s",str);
                struct node*tbins=retUser(str); 
		tbins=refineUser(tbins, users);
                printf("b%d\n",tbins->id);      
	        users=insertUser(users,tbins->id,tbins);
                break;

            case 2:
           
                scanf("%d", &id);
                printf("users:%d\n",users->numfren);
                deleteFriends(id, users);
                printf("users:%d\n",users->numfren);
		users=deleteNode(users, id);
                break;

            case 3:
        
                scanf("%d", &id);
                node* result=search(id,users);
                if(result==NULL) 
                    printf("USER NOT IN TREE.\n");
                else{
                    printf("%d\n",result->id);
                }
                break;

            case 4:
                scanf("%d", &id);
                friends(id, users);
                break;

            case 5:
                printInOrder(users);
                break;

            case 6:
                exit(0);
                break;

            default: 
                printf("Wrong input! \n");
                break;
        }

    }
    return 0;
}
