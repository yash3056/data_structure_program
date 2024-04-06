#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct Node
{
  int info;
  struct Node *next;
};
struct Node *start=NULL;
/////////////////////////////////////////////////////////////////
void printlist()
{
  struct Node *current;
  current=start;
  if(current==NULL)
   printf("\nThe list is empty");
  else
  {
    printf("\nThe numbers in the list are :\n");
    while(current!=NULL)
    {
      printf("%d ",current->info);
      current=current->next;
    }
  }
}
///////////////////////////////////////////////////////////////////////////
void addsort(int num)
{
  struct Node *current,*prev,*newnode;
  newnode=(struct Node *)malloc(sizeof(struct Node));
  newnode->info=num;
  if(start==NULL)
  {
    start=newnode;
    newnode->next=NULL;
  }
  else if(newnode->info < start->info)
  {
    newnode->next=start;
    start=newnode;
  }
  else
  {
    current=start;
    while(newnode->info > current->info && current!=NULL)
    {
	prev=current;
	current=current->next;
    }
    newnode->next=current;
    prev->next=newnode;
  }
}
////////////////////////////////////////////////////////////////////

void main()
{
  clrscr();
  addsort(6);
  addsort(8);
  addsort(2);
  addsort(3);
  addsort(9);
  addsort(4);
  printlist();
  getch();
}