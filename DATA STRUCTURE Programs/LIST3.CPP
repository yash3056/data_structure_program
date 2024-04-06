#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct Node
{
  int info;
  struct Node *next;
  struct Node *prev;
};
struct Node *start=NULL;
struct Node *last=NULL;
/////////////////////////////////////////////////////////////////
void addstart(int num)
{
   struct Node *newnode;
   newnode=(struct Node *)malloc(sizeof(struct Node ));
   newnode->info=num;
   newnode->prev=NULL;
   newnode->next=start;
   if(start==NULL)
    last=newnode;
   else
    start->prev=newnode;
   start=newnode;
   printf("\nThe number %d added at the start of list",start->info);
}
//////////////////////////////////////////////////////////////////////
void addlast(int num)
{
   struct Node *newnode;
   newnode=(struct Node *)malloc(sizeof(struct Node));
   newnode->info=num;
   newnode->next=NULL;
   newnode->prev=last;

   if(last==NULL)
    start=newnode;
   else
    last->next=newnode;

   last=newnode;
}
//////////////////////////////////////////////////////////////////////
int countnodes()
{
 int c=0;
 struct Node *current=start;
 while(current!=NULL)
 {
   c++;
   current=current->next;
 }
 return c;
}
//////////////////////////////////////////////////////////////////////
void addposition(int num,int pos)
{
  int i,c=countnodes();
  struct Node *newnode,*current;
  if(pos>=1 && pos<=c+1)
  {
    if(pos==1)
     addstart(num);
    else if(pos==c+1)
     addlast(num);
    else
    {
     newnode=(struct Node*)malloc(sizeof(struct Node));
     newnode->info=num;
     current=start;
     for(i=1;i<pos;i++)
     {
       current=current->next;
     }
     newnode->next=current;
     newnode->prev=current->prev;
     current->prev->next=newnode;
     current->prev=newnode;
   }
  }
  else
  printf("\nInvalid position");
}
////////////////////////////////////////////////////////////////////////
void printlistforward()
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
void printlistbackward()
{
  struct Node *current;
  current=last;
  if(current==NULL)
   printf("\nThe list is empty");
  else
  {
    printf("\nThe numbers in the list are :\n");
    while(current!=NULL)
    {
      printf("%d ",current->info);
      current=current->prev;
    }
  }
}
///////////////////////////////////////////////////////////////////////////
void deletestart()
{
  struct Node *current=start;
  if(current==NULL)
  printf("\nThe list is empty");
  else
  {
    if(start==last)
     start=last=NULL;
    else
    {
      start=current->next;
      start->prev=NULL;
    }
    printf("\nThe number %d removed from the list",current->info);
    free(current);
  }
}
////////////////////////////////////////////////////////////////////////
void deletelast()
{
  struct Node *current;
  current=last;
  if(current==NULL)
  printf("\nThe list is empty");
  else
  {
     if(start==last)
     start=last=NULL;
     else
     {
      last=last->prev;
      last->next=NULL;
     }
     printf("\nThe number %d removed from the list",current->info);
     free(current);
  }
}
///////////////////////////////////////////////////////////////////
void deleteposition(int pos)
{
  int i,c=countnodes();
  struct Node *current;
  if(pos>=1 && pos<=c)
  {
   if(pos==1)
     deletestart();
   else if(pos==c)
     deletelast();
   else
   {
     current=start;
     for(i=1;i<pos;i++)
     {
       current=current->next;
     }
     current->prev->next=current->next;
     current->next->prev=current->prev;
     printf("\nThe number %d removed from the list",current->info);
     free(current);
   }
  }
  else
  printf("\nInvalid position");
}
///////////////////////////////////////////////////////
void reverselist()
{
  struct Node *current,*prev,*save=NULL;
  if(start==NULL)
   printf("The list is empty");
  else
  {
    current=start;
    while(current!=NULL)
    {
      prev=current;
      current=current->next;
      prev->next=save;
      save=prev;
    }
    start=save;
    printf("\nThe list is reversed now");
  }
}
////////////////////////////////////////////////////////////
void sortlist()
{
  struct Node *i,*j;
  int temp;
  if(start==NULL)
   printf("The list is empty");
  else
  {
    for(i=start;i->next!=NULL;i=i->next)
    {
       for(j=i->next;j!=NULL;j=j->next)
       {
	 if(i->info > j->info)
	 {
	   temp=i->info;
	   i->info=j->info;
	   j->info=temp;
	 }
       }
    }
    printf("\nThe list is sorted now");
  }
}

void main()
{
  int num,pos,ch;
  while(1)
  {
   clrscr();
   printf("\n                     Linked List Menu");
   printf("\n                        ---------");
   printf("\n                    1. Insert number at start");
   printf("\n                    2. Insert number at last");
   printf("\n                    3. Insert number at position");
   printf("\n                    4. Delete number at start");
   printf("\n                    5. Delete number at last");
   printf("\n                    6. Delete number at position");
   printf("\n                    7. Print List Forward");
   printf("\n                    8. Print List Backward");
   printf("\n                    9. Sort List");
   printf("\n                    10. Exit");
   printf("\n\nEnter your choice (1-10) : ");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
	printf("Enter number : ");
	scanf("%d",&num);
	addstart(num);
	break;
     case 2:
	printf("Enter number : ");
	scanf("%d",&num);
	addlast(num);
	break;
     case 3:
	printf("Enter number : ");
	scanf("%d",&num);
	printf("Enter position : ");
	scanf("%d",&pos);
	addposition(num,pos);
	break;
     case 4:
	deletestart();
	break;
     case 5:
	deletelast();
	break;
     case 6:
	printf("Enter position : ");
	scanf("%d",&pos);
	deleteposition(pos);
	break;
     case 7:
	printlistforward();
	break;
     case 8:
	printlistbackward();
	break;
     case 9:
	sortlist();
	break;
     case 10:
	return;
     default:
	printf("\nInvalid choice");
   }
   printf("\nPress any key to continue...");
   getch();
  }
}