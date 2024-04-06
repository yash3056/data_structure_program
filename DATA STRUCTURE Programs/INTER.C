#include<stdio.h>
#include<conio.h>
void main()
{
int x,y,u,l,n;
clrscr();
printf("enter the choice");
scanf("%d",&n);
for (x=n;x>=1;x--)
{
 y=((x*x*x)-x-1);
 if(y>0)
  u=x;
 else
 {
  if(y==0)
   printf("root is=%d",x);
  else
  {
   l=x;
  }
 }
}
 printf("the interval is (%d,%d)",u,l);
 getch();
}