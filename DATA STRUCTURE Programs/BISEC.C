#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
 int i;
 float x,z,a,b,m,e;
 clrscr();
 printf("enter value of a,b and error");
 scanf("%f%f%f",&a,&b,&e);
 do
 {
  x=a*a*a-a-1;
  m=(a+b)/2;
  z=m*m*m-m-1;
  if(z==0)
  printf("exact root is %f:");
  else
  {
  if (z*x<0)
  b=m;
  else
  a=m;
  }
 }
 while (abs(b-a)>e);
 printf("approximate root=%f",m);
 getch();
}
