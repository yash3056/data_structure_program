#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#define MAX 50
void push(int *,int *,int);
int pop(int *,int *);
void main()
{
  char str[MAX],*s;
  int n1,n2,n3,nn,num;
  int stack[MAX],top=-1;
  clrscr();
  printf("\nEnter the postfix expression to be evaluated : ");
  gets(str);  //3 2 * 5 -
  s=str;
  while(*s)
  {
     if(*s==' '|| *s=='\t')
     {
      s++;
      continue;
     }
     num=0;

     if(*s>='0' && *s<='9')
     {
       while( isdigit(*s) )
       {
	 nn= *s - '0';
	 num=(num*10)+nn;
	 s++;
       }
       push(stack,&top,num);
     }
     else
     {
       n1=pop(stack,&top);
       n2=pop(stack,&top);
       switch(*s)
       {
	case '+':
	n3=n2+n1;
	break;
	case '-':
	n3=n2-n1;
	break;
	case '/':
	n3=n2/n1;
	break;
	case '*':
	n3=n2*n1;
	break;
	case '%':
	n3=n2%n1;
	break;
	case '^':
	n3=pow(n2,n1);
	break;
	default:
	printf("Unknown operator");
	exit(1);
     }
     push(stack,&top,n3);
     s++;
   }
  }
   nn=pop(stack,&top);
   printf("\nResult is : %d",nn);
   getch();
   }


void push(int *stk,int *sp,int item)
{
   if(*sp==MAX)
   printf("\nStack is full");
   else
   {
     *sp=*sp+1;
     stk[*sp]=item;
   }
}

int pop(int *stk,int *sp)
{
   int item;
   if(*sp==-1)
   {
     printf("\nStack is empty");
     return(-1);
   }
   else
   {
     item=stk[*sp];
     *sp=*sp-1;
     return(item);
   }
}








