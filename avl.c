#include<stdio.h>
#include<stdlib.h>
struct tnode
{
	struct tnode* left;
	struct tnode* right;
	int data;
	int lh;
        int rh;
        int level;

};
typedef struct tnode tnode;struct list
{
	tnode** arr;
	int len;
	int top;
};
typedef struct list list;
struct queue
{
	int front;
	int rear;
	tnode **ptr_s;//even with single can work
	int size;
};
typedef struct queue queue;
void create_queue(queue * ptr_Q)
{
	ptr_Q->front=-1;
	ptr_Q->rear=-1;
	ptr_Q->ptr_s=malloc(sizeof(tnode*)*ptr_Q->size);
}
void insertQ(queue *ptr_Q,tnode *ele)
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
	static int count=1;
	tnode* ele;
	if(ptr_Q->front==-1)//reseting option
		return -999;
	else
	{
		ele=ptr_Q->ptr_s[ptr_Q->front];
		ptr_Q->front=ptr_Q->front+1;
		if(ptr_Q->front==ptr_Q->rear+1)//last element deletion
			ptr_Q->front=ptr_Q->rear=-1;
		printf("Level:%d Data:%d\n",ele->level,ele->data);
		if(ele->left!=NULL)
		{
			(ele->left)->level=ele->level+1;
			insertQ(ptr_Q,ele->left);
		}
		if(ele->right!=NULL)
		{
			(ele->right)->level=ele->level+1;
			insertQ(ptr_Q,ele->right);
		}
		deleteQ(ptr_Q);
		return 1;
	}
}
void levelorder(tnode* root)
{
	if(root!=NULL)
	{
		queue Q;
		Q.size=100;
		create_queue(&Q);
		insertQ(&Q,root);
		deleteQ(&Q);
	}
}
tnode* inp(list* l)
{
	tnode* root=malloc(sizeof(tnode));
	scanf("%d",&root->data);
	root->left=root->right=NULL;
	root->lh=root->rh=0;
	while(1)
	{
		int ele;
		scanf("%d",&ele);
		l->arr[l->len]=root;
		//l->top++;
		l->len++;
		if(ele==-1)
			break;
		createBST(&root,root,ele,l);
	}
	return root;
}
void check(tnode** mroot,list *l)
{
	int bf;
	tnode  *gp,*p,*c,*gp_prev;
	gp=malloc(sizeof(tnode));
	p=malloc(sizeof(tnode));
	c=malloc(sizeof(tnode));
	gp_prev=malloc(sizeof(tnode));
	//gp_prev=mroot;
	while(l->len!=0)
	{
		//printf("a=%d\n",*a);
		bf=((l->arr[(l->len)-1]->lh)-(l->arr[(l->len-1)]->rh));
		(l->len)--;
		printf("check:%d %d\n",l->arr[l->len]->data,bf);
		if(!(bf==0 || bf==1 || bf==-1))
		{
			if(l->len>0)
			gp_prev=l->arr[l->len-1];
			gp=l->arr[l->len];
			p=l->arr[l->len+1];
			c=l->arr[l->len+2];
			reset(*mroot);
			levelorder(*mroot);
			printf("values:%d %d %d %d\n",l->len,gp_prev->data,p->data,c->data);
			if(p==gp->left && c==p->left)//LL
			{
				printf("ll\n");
				gp->left=p->right;
				gp->lh=p->rh;
				p->rh=1+((gp->lh>gp->rh)?gp->lh:gp->rh);
				p->right=gp;
				printf("x%d %d\n",gp->data,gp->lh);
				printf("y%d %d\n",p->data,p->rh);
				printf("check3:%d %d %d\n",gp->data,gp->lh,gp->rh);
				printf("check3:%d %d %d\n",p->data,p->lh,p->rh);
				printf("check3:%d %d %d\n",c->data,c->lh,c->rh);
				
				if(l->len==0)
				 {printf("zzz");
				 *mroot=p;
				 gp_prev=p;
				 }
				 else if(l->len>0 && gp==gp_prev->left)
				{
					printf("zzz");
					gp_prev->left=p;
					gp_prev->lh=1+((p->lh>p->rh)?p->lh:p->rh);
				}
				else if(l->len>0 && gp==gp_prev->right)
				{
					printf("zzz");
					gp_prev->right=p;
					gp_prev->rh=1+((p->lh>p->rh)?p->lh:p->rh);
				}
				printf("check3:%d %d %d\n",gp_prev->data,gp_prev->lh,gp_prev->rh);
			}
			else if(p==gp->right && c==p->right)//RR
			{
				printf("rr\n");
				gp->right=p->left;
				gp->rh=p->lh;
				p->left=gp;
				p->lh=1+((gp->lh>gp->rh)?gp->lh:gp->rh);
				printf("x%d %d\n",gp->data,gp->rh);
				printf("y%d %d\n",p->data,p->lh);
				printf("check3:%d %d %d\n",gp->data,gp->lh,gp->rh);
				printf("check3:%d %d %d\n",p->data,p->lh,p->rh);
				printf("check3:%d %d %d\n",c->data,c->lh,c->rh);
				
				if(l->len==0)
				 {
				 *mroot=p;
				 gp_prev=p;
				 }
				 else if(l->len>0 && gp==gp_prev->left )
				{
					gp_prev->left=p;
					gp_prev->lh=1+((p->lh>p->rh)?p->lh:p->rh);
				}
				else if(l->len>0 && gp==gp_prev->right)
				{
					gp_prev->right=p;
					gp_prev->rh=1+((p->lh>p->rh)?p->lh:p->rh);
				}
				printf("check3:%d %d %d\n",gp_prev->data,gp_prev->lh,gp_prev->rh);
			}
			else if(p==gp->right && c==p->left)//RL
			{
				p->left=c->right;
				p->lh=c->rh;
				c->right=p;
				c->rh=1+((p->lh>p->rh)?p->lh:p->rh);
				gp->right=c;
				gp->rh=1+((c->lh>c->rh)?c->lh:c->rh);
				printf("check3:%d %d %d\n",gp->data,gp->lh,gp->rh);
				printf("check3:%d %d %d\n",p->data,p->lh,p->rh);
				printf("check3:%d %d %d\n",c->data,c->lh,c->rh);
				tnode* temp;
				temp=p;
				p=c;
				c=temp;
				gp->right=p->left;
				gp->rh=p->lh;
				p->left=gp;
				p->lh=1+((gp->lh>gp->rh)?gp->lh:gp->rh);
				printf("check3_:%d %d %d\n",gp->data,gp->lh,gp->rh);
				printf("check3_:%d %d %d\n",p->data,p->lh,p->rh);
				printf("check3_:%d %d %d\n",c->data,c->lh,c->rh);
				
				if(l->len==0)
				 {
				 *mroot=p;
				 gp_prev=p;
				 }
				 else if(l->len>0 && gp==gp_prev->left )
				{
					gp_prev->left=p;
					gp_prev->lh=1+((p->lh>p->rh)?p->lh:p->rh);
				}
				else if(l->len>0 && gp==gp_prev->right)
				{
					gp_prev->right=p;
					gp_prev->rh=1+((p->lh>p->rh)?p->lh:p->rh);
				}
				printf("check3:%d %d %d\n",gp_prev->data,gp_prev->lh,gp_prev->rh);
			}
			else if(p==gp->left && c==p->right)//LR
			{
				p->right=c->left;
				p->rh=c->lh;
				c->left=p;
				c->lh=1+((p->lh>p->rh)?p->lh:p->rh);
				gp->left=c;
				gp->lh=1+((c->lh>c->rh)?c->lh:c->rh);
				printf("check3:%d %d %d\n",gp->data,gp->lh,gp->rh);
				printf("check3:%d %d %d\n",p->data,p->lh,p->rh);
				printf("check3:%d %d %d\n",c->data,c->lh,c->rh);
				
				tnode* temp;
				temp=p;
				p=c;
				c=temp;
				gp->left=p->right;
				gp->lh=p->rh;
				p->right=gp;
				p->rh=1+((gp->lh>gp->rh)?gp->lh:gp->rh);
				
				printf("check3_:%d %d %d\n",gp->data,gp->lh,gp->rh);
				printf("check3_:%d %d %d\n",p->data,p->lh,p->rh);
				printf("check3_:%d %d %d\n",c->data,c->lh,c->rh);
				
				if(l->len==0)
				{ *mroot=p;
				gp_prev=p;
				}
				 else if(l->len>0 && gp==gp_prev->left )
				{
					gp_prev->left=p;
					gp_prev->lh=1+((p->lh>p->rh)?p->lh:p->rh);
				}
				else if(l->len=0 && gp==gp_prev->right)
				{
					gp_prev->right=p;
					gp_prev->rh=1+((p->lh>p->rh)?p->lh:p->rh);
				}
				printf("check3:%d %d %d\n",gp_prev->data,gp_prev->lh,gp_prev->rh);
			}
			reset(*mroot);
			printf("check2:%d %d\n",l->arr[l->len]->data,bf);
			levelorder(*mroot);
			l->len=0;
			break;
		}
	}
}
void fixheight(list* l)
{
	int len=l->len;
	len--;
	tnode *cmp;
	printf("a:%d %d\n",len,l->arr[len]->data);
	while(len!=0)
	{
		cmp=l->arr[len];
		if(l->arr[len-1]->data>cmp->data)
		l->arr[len-1]->lh=1+((cmp->lh>cmp->rh)?cmp->lh:cmp->rh);
		else
		l->arr[len-1]->rh=1+((cmp->lh>cmp->rh)?cmp->lh:cmp->rh);
		printf("height:%d %d %d\n",l->arr[len-1]->data,l->arr[len-1]->lh,l->arr[len-1]->rh);
		len--;
	}
}
	
void createBST(tnode** mroot,tnode* root,int ele,list* l)
{
	tnode* newnode=malloc(sizeof(tnode));
	printf("bst %d\n",l->len);
	if(ele<root->data)
	{
		if(root->left!=NULL)
		{
			printf("xxx\n");
			l->arr[l->len]=root->left;
			//l->top++;
			l->len++;
			//root->lh++;
			createBST(mroot,root->left,ele,l);
		}
		else
		{
			newnode->left=newnode->right=NULL;
			newnode->lh=newnode->rh=0;
			newnode->data=ele;
			root->left=newnode;
			//root->lh++;
			l->arr[l->len]=root->left;
			//l->top++;
			l->len++;
			printf("Before check%d\n",(l->arr[(l->len)-1]->data));
			//printf("Before check%d\n",(l->arr[(l->len)-1]->data);
			//levelorder(root);
			fixheight(l);
			check(mroot,l);
			//levelorder(root);
		}
	}
	else if(ele>root->data)
	{
		if(root->right!=NULL)
		{
			printf("xxx\n");
			l->arr[l->len]=root->right;
			//l->top++;
			l->len++;
			//root->rh++;
			createBST(mroot,root->right,ele,l);
		}
		else
		{
			newnode->left=newnode->right=NULL;
			newnode->lh=newnode->rh=0;
			newnode->data=ele;
			root->right=newnode;
			//root->rh++;
			l->arr[l->len]=root->right;
			//l->top++;
			l->len++;
			printf("Before chec%d\n",(l->arr[(l->len)-1]->data));
			//levelorder(root);
			fixheight(l);
			check(mroot,l);
			//levelorder(root);
		}
	}
}
void inorder(tnode* root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		inorder(root->left);
		inorder(root->right);
	}
}
tnode* createarr(list *l)
{
	l->arr=malloc(sizeof(tnode*)*100);
	l->len=0;
}
void reset(tnode* root)
{
	if(root!=NULL)
	{
		reset(root->left);
		reset(root->right);
		root->level=0;
	}
}
int main()
{
	tnode* root;
	list *l;
	l=malloc(sizeof(list));
	createarr(l);
	printf("Enter the elements\n");
	root=inp(l);
	printf("Tree:\n");
	tnode* droot;
	reset(root);
	levelorder(root);
	return 0;
}
