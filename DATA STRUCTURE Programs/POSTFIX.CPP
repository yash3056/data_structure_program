//INFIX TO POSTFIX
#define MAX 50
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
//////////////////////////////////////////////////
int priority(char ele)
{
 int pri;
 if(ele=='^')
 pri=3;
 else if(ele=='*' || ele=='/' || ele=='%')
 pri=2;
 else if(ele=='+' || ele=='-')
 pri=1;
 else
 pri=0;
 return pri;
}
////////////////////////////////////////////////////
void push(char *stk,int *sp,char item)
{
  if(*sp==MAX)
  printf("\nStack is full");
  else
  {
    *sp=*sp+1;  //top++
    stk[*sp]=item;
  }
}
//////////////////////////////////////////////////////
char pop(char *stk,int *sp)
{
   char item;
   if(*sp==-1)
   {
     return ' '; //Stack is empty
   }
   else
   {
     item=stk[*sp];
     *sp=*sp-1;
     return (item);
   }
}
/////////////////////////////////////////////////////////

void main()
{
char target[MAX],stack[MAX],str[MAX],*s,*t,n1;
int top=-1;
clrscr();
printf("Enter the infix expression: ");
scanf("%[^\n]s",str);  //a+b*c\0
t=target;
s=str;

while(*s)
{
 if(*s==' '|| *s=='\t')
 {
   s++;
   continue;
 }

 if(isdigit(*s)||isalpha(*s))
 {
    while(isdigit(*s)||isalpha(*s))
    {
	 *t=*s;   //target=a
	  t++;
	  s++;
    }
    *t=' ';
     t++;
 }

 if( *s=='(' )
 {
   push(stack,&top,*s);
   s++;
  }

  if( *s==')'  )
  {
    n1=pop(stack,&top);
    while(n1!='(')
    {
	*t=n1;
	 t++;
	 *t=' ';
	 t++;
	 n1=pop(stack,&top);
    }
    s++;
  }


   if(*s=='+'|| *s=='-'|| *s=='*' || *s=='/' || *s=='%'||*s=='^')
   {
     if(top==-1)
     push(stack,&top,*s);
     else
     {
      n1=pop(stack,&top);
      while( priority(n1) >= priority(*s) )
      {
	*t=n1;
	 t++;
	 *t=' ';
	 t++;
	 n1=pop(stack,&top);
      }
      push(stack,&top,n1);
      push(stack,&top,*s);
    }
   s++;
  }
}

while (top!=-1)
{
  *t=pop(stack,&top);
   t++;
   *t=' ';
   t++;
}
*t='\0';
printf("\nPostfix expression is : %s",target);
getch();
}








