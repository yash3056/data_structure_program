#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int cn=0;
int ht=0;
struct node
{
  struct node *leftchild;
  int info;
  struct node *rightchild;
};
void insert(struct node **,int);
void inorder(struct node * );
void height(struct node *,int );
void preorder(struct node *);
void postorder(struct node *);

void remove(struct node **,int);
void search(struct node *,int,struct node **,struct node **,int *);
void main()
{
  int num,ch,c;
  struct node *root=NULL;
  while(1)
  {
    clrscr();
    printf("\n           Binary search tree Menu");
    printf("\n         ----------------------------");
    printf("\n             1. Insert node");
    printf("\n             2. Inorder");
    printf("\n             3. Preorder");
    printf("\n             4. Postorder");
    printf("\n             5. Delete node");
    printf("\n             6. Count nodes");
    printf("\n             7. Height of tree");
    printf("\n             8. Exit");
    printf("\nEnter your choice (1-8) ");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1:
	     printf("Enter number to be inserted into the node ");
	     scanf("%d",&num);
	     insert(&root,num);
	     break;
       case 2:
	     inorder(root);
	     break;
       case 3:
	     preorder(root);
	     break;
       case 4:
	     postorder(root);
	     break;
       case 5:
	     printf("Enter number to be removed ");
	     scanf("%d",&num);
	     remove(&root,num);
	     break;
       case 6:
	     cn=0;
	     inorder(root);
	     printf("\nNumber of nodes in a tree are : %d",cn);
	     break;
       case 7:
	     ht=0;
	     height(root,0) ;
	     printf("\nHeight of tree is %d",ht);
	     break;
       case 8:
	     return ;
       default:
	    printf("\nInvalid choice");
       }
  printf("\nPress any key to continue...");
  getch();
 }
}

/////////////////////////////////////////////////
void insert(struct node **root,int num)
{
  struct node *new_node;
  if(*root==NULL)
  {
     new_node=(struct node *)malloc(sizeof(struct node));
     new_node->info=num;
     *root=new_node;
     new_node->leftchild=NULL;
     new_node->rightchild=NULL;
  }
  else
  {
    if( (*root)->info<num)
    {
	insert( &(*root)->rightchild ,num);
    }
    else
    {
	insert( &(*root)->leftchild,num);
    }
  }
}
/////////////////////////////////////////////
void inorder(struct node *root)
{
     if(root!=NULL)
     {
       inorder(root->leftchild);
       printf("%d  ",root->info);
       cn++;
       inorder(root->rightchild);
     }
}
void height(struct node *root,int l)
{
     if(root!=NULL)
     {
       height(root->leftchild,l+1);
       if(l+1>ht)
       ht=l+1;
       height(root->rightchild,l+1);
     }
}
//////////////////////////////////////////
void preorder(struct node *root)
{
     if(root==NULL)
     {
       return;
     }
     else
     {
       printf("%d  ",root->info);
       preorder(root->leftchild);
       preorder(root->rightchild);
     }
}
/////////////////////////////////////////////////
void postorder(struct node *root)
{
     if(root==NULL)
     {
       return;
     }
     else
     {
       postorder(root->leftchild);
       postorder(root->rightchild);
       printf("%d  ",root->info);
     }
}
///////////////////////////////////////////////////////////////////
void remove(struct node **root,int num)
{
  struct node *parent,*x,*xsucc;
  int found;
  if(*root==NULL)
  {
    printf("\nTree is empty");
    return;
  }
  found=0;
  parent=x=xsucc=NULL;
  search(*root,num,&x,&parent,&found);
  if(found==0)
  printf("\nNumber not found");
  else
  {
    if(x->leftchild!=NULL && x->rightchild!=NULL)
    {
       xsucc=x->rightchild;
       while(xsucc->leftchild!=NULL)
       {
	 parent=xsucc;
	 xsucc=xsucc->leftchild;
       }
       x->info=xsucc->info;
       if(parent==NULL)
       parent=x;
       x=xsucc;
    }

    if(x->leftchild!=NULL && x->rightchild==NULL)
    {
       if(x==parent->leftchild)
       parent->leftchild=x->leftchild;
       else
       parent->rightchild=x->leftchild;

    }
    if(x->leftchild==NULL && x->rightchild!=NULL)
    {
       if(x==parent->leftchild)
       parent->leftchild=x->rightchild;
       else
       parent->rightchild=x->rightchild;
    }

    if(x->leftchild==NULL && x->rightchild==NULL)
    {
       if(x==parent->leftchild)
	parent->leftchild=NULL;
	else
	parent->rightchild=NULL;
    }
    free(x);
  }
}
///////////////////////////////////////////////////////////
void search(struct node *root,int num,struct node **x,struct node **parent,int *found)
{
  struct node *q;
  q=root;
  while (q!=NULL)
  {
     if(q->info==num)
     {
       *found=1;
       *x=q;
       return;
     }
     else
     {
      if(q->info>num)
      {
	 *parent=q;
	 q=q->leftchild;
      }
      else
      {
	 *parent=q;
	 q=q->rightchild;
      }
    }
  }
}
