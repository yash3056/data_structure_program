#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
  struct node *leftchild;
  int info;
  struct node *rightchild;
};

int nol=0;
int height=0;

void main()
{
  void insert(struct node **,int);
  void inorder(struct node *);
  void preorder(struct node *);
  void postorder(struct node *);
  struct node *root=NULL;
  void leaf_nodes(struct node *);
  void find_height(struct node *,int);
  insert(&root,10);
  insert(&root,5);
  insert(&root,12);
  insert(&root,8);
  insert(&root,15);
  insert(&root,6);
  insert(&root,9);
  insert(&root,18);
  insert(&root,3);
  insert(&root,11);
  insert(&root,14);
  insert(&root,7);
  clrscr();
  printf("\nInorder :\n");
  inorder(root);
  printf("\nPreorder :\n");
  preorder(root);
  printf("\nPostorder :\n");
  postorder(root);
  leaf_nodes(root);
  printf("\nNumber of leaf nodes = %d",nol);
  find_height(root,1);
  printf("\nThe height of binary search tree is %d",height);
  getch();
}
/////////////////////////////////////////////////
void insert(struct node **root,int num)
{
  struct node *new_node,*parent;
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
    parent=*root;
    if(parent->info<num)
    {
	insert( &(parent->rightchild),num);
    }
    else
    {
	insert( &(parent->leftchild),num);
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
       inorder(root->rightchild);
     }
}

void leaf_nodes(struct node *root)
{
     if(root)
     {
       leaf_nodes(root->leftchild);
       if(root->leftchild==NULL && root->rightchild==NULL)
       nol++;
       leaf_nodes(root->rightchild);
     }
}

void find_height(struct node *root,int lvl)
{
     if(root)
     {
       find_height(root->leftchild,lvl+1);
       if(lvl>height)
       height=lvl;
       find_height(root->rightchild,lvl+1);
     }

}
//////////////////////////////////////////
void preorder(struct node *root)
{
     if(root!=NULL)
     {
       printf("%d  ",root->info);
       preorder(root->leftchild);
       preorder(root->rightchild);
     }
}
/////////////////////////////////////////////////
void postorder(struct node *root)
{
     if(root!=NULL)
     {
       postorder(root->leftchild);
       postorder(root->rightchild);
       printf("%d  ",root->info);
     }
}
