#include<stdio.h>
#include<conio.h>
#define SIZE 5
int stk[SIZE];
int top=0;
void push(int item)
{
  if(top==SIZE)
  printf("\nStack overflow");
  else
  {
    stk[top]=item;
    printf("\nThe number %d pushed into the stack",item);
    top++;
  }
}
/////////////////////////////////////////////////////
void pop()
{
  if(top==0)
    printf("\nStack underflow");
  else
   {
      top--;
      printf("\nThe number %d popped from the stack",stk[top]);
   }
}
/////////////////////////////////////////////////////
void display()
{
  if(top==0)
    printf("\nStack underflow");
  else
   {
     int i;
     printf("\nThe numbers in stack are :");
     for(i=top-1;i>=0;i--)
     printf("\n%d ",stk[i]);
   }
}

void main()
{
  int ch,num;
  while(1)
  {
   clrscr();
   printf("\n                 Stack Menu");
   printf("\n              -----------------");
   printf("\n              1. Push");
   printf("\n              2. Pop");
   printf("\n              3. Display stack");
   printf("\n              4. Exit");
   printf("\n\nEnter your choice (1-4) : ");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
	  printf("\nEnter number to be pushed : ");
	  scanf("%d",&num);
	  push(num);
	  break;
     case 2:
	  pop();
	  break;
     case 3:
	  display();
	  break;
     case 4:
	  return;
     default:
	 printf("\nInvalid choice");
	 break;
   }
  printf("\nPress any key....");
  getch();
  }
}

