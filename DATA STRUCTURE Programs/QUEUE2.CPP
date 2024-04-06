#include<stdio.h>
#include<conio.h>
#define SIZE 10
void add(int *Q,int *front,int *rear,int item)
{
   if(*rear==SIZE-1)
    printf("\nQueue is full");
   else
   {
     (*rear)++;
     Q[*rear]=item;
     printf("\nThe item %d added into the queue",Q[*rear]);
     if(*front==-1)
     *front=*rear;
   }
}
///////////////////////////////////////////
void remove(int *Q,int *front,int *rear)
{
   if(*front==-1)
    printf("\nQueue is empty");
   else
   {
     printf("\nThe item %d removed from the queue",Q[*front]);
     if(*front==*rear)
     *front=*rear=-1;
     else
     (*front)++;
   }
}
/////////////////////////////////////////////
void display(int *Q,int front,int rear)
{
   int i;
   if(front==-1)
    printf("\nQueue is empty");
   else
   {
    printf("\nFront-> ");
    for(i=front;i<=rear;i++)
    printf("%d ",Q[i]);
    printf(" <-Rear");
  }
}
//////////////////////////////////////////
void main()
{
  int Q[SIZE];
  int front=-1,rear=-1;
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
	add(Q,&front,&rear,num);
	break;
     case 2:
	remove(Q,&front,&rear);
	break;
     case 3:
	display(Q,front,rear);
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