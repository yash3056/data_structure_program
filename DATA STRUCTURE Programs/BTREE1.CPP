#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
  struct node *leftchild;
  int info;
  struct node *rightchild;
};
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

void main()
{
  struct node *root=NULL;
  clrscr();
  insert(&root,12);
  insert(&root,15);
  insert(&root,8);
  insert(&root,6);
  insert(&root,20);
  insert(&root,10);
  insert(&root,25);
  insert(&root,4);
  insert(&root,19);
  insert(&root,9);
  printf("\nInorder :\n");
  inorder(root);
  printf("\nPreorder :\n");
  preorder(root);
  printf("\nPostorder :\n");
  postorder(root);
  getch();
}
