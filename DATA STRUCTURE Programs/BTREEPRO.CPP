#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
  struct node *leftchild;
  int info;
  struct node *rightchild;
};

void insert(struct node **,int);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void inorderLeaf(struct node *);
void preorderLeaf(struct node *);
void postorderLeaf(struct node *);

void main()
{
  struct node *root=NULL;
  insert(&root,10);
  insert(&root,5);
  insert(&root,13);
  insert(&root,12);
  insert(&root,14);
  clrscr();
  printf("\nInorder all nodes:\n");
  inorder(root);
  printf("\nInorder leaf nodes:\n");
  inorderLeaf(root);
  printf("\nPreorder all nodes:\n");
  preorder(root);
  printf("\nPreorder leaf nodes:\n");
  preorderLeaf(root);
  printf("\nPostorder all nodes:\n");
  postorder(root);
  printf("\nPostorder leaf nodes:\n");
  postorderLeaf(root);
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
     if(root)
     {
       inorder(root->leftchild);
       printf("%d  ",root->info);
       inorder(root->rightchild);
     }
}
//////////////////////////////////////////
void inorderLeaf(struct node *root)
{
     if(root)
     {
       inorderLeaf(root->leftchild);
       if(root->leftchild==NULL && root->rightchild==NULL)
       printf("%d  ",root->info);
       inorderLeaf(root->rightchild);
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
void preorderLeaf(struct node *root)
{
     if(root!=NULL)
     {
       if(root->leftchild==NULL && root->rightchild==NULL)
       printf("%d  ",root->info);
       preorderLeaf(root->leftchild);
       preorderLeaf(root->rightchild);
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
void postorderLeaf(struct node *root)
{
     if(root!=NULL)
     {
       postorderLeaf(root->leftchild);
       postorderLeaf(root->rightchild);
       if(root->leftchild==NULL && root->rightchild==NULL)
       printf("%d  ",root->info);
     }
}
