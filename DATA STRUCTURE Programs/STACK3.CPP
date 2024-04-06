#include<stdio.h>
#include<conio.h>
#define SIZE 80
void push(char *stk,char item,int *top)
{
  if(*top==SIZE)
  printf("\nStack overflow");
  else
  {
    stk[*top]=item;
    (*top)++;
  }
}
/////////////////////////////////////////////////////

void pop(char *stk,int *top)
{
  if(*top==0)
    printf("\nStack underflow");
  else
   {
      (*top)--;
      printf("%c",stk[*top]);
   }
}
/////////////////////////////////////////////////////

void main()
{
  char str[SIZE];
  char stk[SIZE];
  int i,top=0;
  clrscr();
  printf("Enter any string : ");
  gets(str);
  for(i=0;str[i]!='\0';i++)
  push(stk,str[i],&top);
  printf("\nString in reverse order is :\n");
  while(top!=0)
  pop(stk,&top);
  getch();
}

