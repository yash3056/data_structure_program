#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#define SIZE 10
struct Node
{
  int info;
  struct Node *next;
};
struct Node *front=NULL;
struct Node *rear=NULL;

void add(int item)
{
  struct Node *newnode;
  newnode=(struct Node *)malloc(sizeof(struct Node));
  newnode->info=item;
  newnode->next=NULL;
  if(rear==NULL)
    front=newnode;
  else
    rear->next=newnode;

   rear=newnode;
   printf("\nThe item %d added into the queue",rear->info);
}
//////////////////////////////////////////
void remove()
{
  struct Node *current=front;
  if(front==NULL)
   printf("\nThe queue is empty");
  else
  {
    if(front==rear)
    front=rear=NULL;
    else
    front=front->next;

    printf("\nThe item %d removed from the queue",current->info);
    free(current);
  }
}
/////////////////////////////////////////
void display()
{
  struct Node *current=front;
  if(front==NULL)
   printf("\nThe queue is empty");
  else
  {
   printf("\nFront-> ");
   while(current)
   {
     printf("%d ",current->info);
     current=current->next;
   }
  }
}
////////////////////////////////////////
void main()
{
  int ch,num;
  while(1)
  {
   clrscr();
   printf("\n                     Queue Menu");
   printf("\n                        ---------");
   printf("\n                    1. Add");
   printf("\n                    2. Remove");
   printf("\n                    3. Display Queue");
   printf("\n                    4. Exit");
   printf("\n\nEnter your choice (1-4) : ");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
	printf("Enter number : ");
	scanf("%d",&num);
	add(num);
	break;
     case 2:
	remove();
	break;
     case 3:
	display();
	break;
     case 4:
	return;
     default:
	printf("\nInvalid choice");
   }
   printf("\nPress any key to continue...");
   getch();
  }
}