#include<stdio.h>
#include<conio.h>
#define SIZE 10
void add(int *Q,int item,int top,int *front,int *rear)
{
   if((*rear+1)==top)
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
void displayQ(int *Q,int front,int rear)
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
void push(int *stk,int item,int *top,int rear)
{
  if(*top==(rear+1))
  printf("\nStack overflow");
  else
  {
    (*top)--;
    stk[*top]=item;
    printf("\nThe number %d pushed into the stack",item);
  }
}
/////////////////////////////////////////////////////

void pop(int *stk,int *top)
{
  if(*top==SIZE)
    printf("\nStack underflow");
  else
   {
      printf("\nThe number %d popped from the stack",stk[*top]);
      (*top)++;
   }
}
/////////////////////////////////////////////////////
void displayStack(int *stk,int top)
{
  if(top==SIZE)
    printf("\nStack underflow");
  else
   {
     int i;
     printf("\nThe numbers in stack are :");
     for(i=top;i<SIZE;i++)
     printf("\n%d ",stk[i]);
   }
}

void main()
{
  int stkQ[SIZE];
  int front=-1,rear=-1;
  int top=SIZE;
  int ch,num;
  while(1)
  {
   clrscr();
   printf("\n                 Stack Menu");
   printf("\n              -----------------");
   printf("\n              1. Push");
   printf("\n              2. Pop");
   printf("\n              3. Display stack");
   printf("\n              4. Add");
   printf("\n              5. Remove");
   printf("\n              6. Display Queue");
   printf("\n              7. Exit");
   printf("\n\nEnter your choice (1-7) : ");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
	  printf("\nEnter number to be pushed : ");
	  scanf("%d",&num);
	  push(stkQ,num,&top,rear);
	  break;
     case 2:
	  pop(stkQ,&top);
	  break;
     case 3:
	  displayStack(stkQ,top);
	  break;
     case 4:
	  printf("\nEnter number to be added : ");
	  scanf("%d",&num);
	  add(stkQ,num,top,&front,&rear);
	  break;
     case 5:
	  remove(stkQ,&front,&rear);
	  break;
     case 6:
	  displayQ(stkQ,front,rear);
	  break;
     case 7:
	  return;
     default:
	 printf("\nInvalid choice");
	 break;
   }
  printf("\nPress any key....");
  getch();
  }
}

