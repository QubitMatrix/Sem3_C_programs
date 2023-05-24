#include <stdio.h>
#include <stdlib.h>

int check=0;
int found=0;
//struct for node
struct node {
    char *value;            // all void* types replaced by char*
    struct node *p_left;
    struct node *p_right;
};

int my_strlen(char * s) 
{
    int len=0;
    int i=0;
    while(s[i]!='\0')
    {
  		len++;
		i++;
    }
    //printf("%d",len);
    return len;
}

void my_strcpy(char *str1, char *str2)//str2 is source, str1 is dest
{
    int i=0;
    while(i<my_strlen(str2))
    {
    	str1[i]=str2[i];
       	i++;
    }
    str1[i]='\0';
}

int my_strcmp(const char *a, const char *b)
{
    int i=0;
    	while(a[i]!='\0')
    	{
    		if(a[i]!=b[i])
    			return (a[i]-b[i]);
    		i++;
    	}
    	return 0;
}
//inserts elements into the tree
void insert(char* key, struct node** leaf)
{
    if((*leaf)==NULL)
    {
        struct node* newnode=malloc(sizeof(struct node));
        newnode->p_left=newnode->p_right=NULL;
        newnode->value=malloc(100);
        (*leaf)=newnode;
        my_strcpy(newnode->value,key);
        //printf("b%s\n",(*leaf)->value);
    }
    else
    {
        if(my_strcmp(key,(*leaf)->value)>0)
        {
            if((*leaf)->p_right==NULL)
            {
                struct node* newnode=malloc(sizeof(struct node));
                newnode->p_left=newnode->p_right=NULL;
                newnode->value=malloc(100);
                my_strcpy(newnode->value,key);
                (*leaf)->p_right=newnode;
                //printf("c%s\n",(*leaf)->value);
            }
            else
            {
                insert(key,&(*leaf)->p_right);
            }
        }
        else if(my_strcmp(key,(*leaf)->value)<0)
        {
            
            if((*leaf)->p_left==NULL)
            {
                struct node* newnode=malloc(sizeof(struct node));
                newnode->p_left=newnode->p_right=NULL;
                newnode->value=malloc(100);
                my_strcpy(newnode->value,key);
                (*leaf)->p_left=newnode;
                //printf("d%s\n",(*leaf)->value);
            }
            else
            {
                insert(key,&(*leaf)->p_left);
            }
        }
        else
        {
            check=-1;
        }
    }
}




//recursive function to print out the tree inorder
void asc_order(struct node *root)
{
    if(root!=NULL)
	{
		asc_order(root->p_left);
		printf("%s\n",root->value);
		asc_order(root->p_right);
	}
}



//searches elements in the tree
void search(char* key, struct node* leaf)  // no need for **
{
        if(leaf!=NULL)
        {
            if(my_strcmp(key,leaf->value)>0)
            {
                if(leaf->p_right!=NULL)
                {
                    search(key,leaf->p_right);
                }
            }
            else if(my_strcmp(key,leaf->value)<0)
            {
            
                if(leaf->p_left!=NULL)
                {
                    search(key,leaf->p_left);
                }
            }
            else
            {
                found=1;
            }
        }
}




int main()
{
    struct node *p_root = NULL;
    char *value;
    size_t malloc_size = 100;
    int size;
    int temp=100;
    scanf("%d",&size);
    int i;
    //reading the input and inserting in the tree
    char *srn[size];
    for (i = 0; i < size; i++) 
    {
        srn[i] = malloc(malloc_size * sizeof(char)); /* allocates 100 bytes */
        scanf("%99s", srn[i]);
        insert(srn[i],&p_root);
    }   
    char searchname[temp];
    scanf("%s",searchname);

    //checking inorder print
    printf("Ascending order:\n");
    asc_order(p_root);

    //checking for 1 or more duplicate insertions
    printf("%d\n",check);

    //searching a string in the tree
    search(searchname,p_root);
    printf("%d\n",found);
    return 0;
}
