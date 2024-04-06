/*bisection method for f(x)=x*x*x-x-1*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
float x1,x2,x3,f1,f2,x;
clrscr();
printf("enter value of x1,x2");
scanf("%f%f",&x1,&x2);
printf("enter value of epsilon");
scanf("%f",&x);
do
{
x3=(x1+x2)/2;
f1=(x1*x1*x1)-x1-1;
f2=(x3*x3*x3)-x3-1;
//for exact root
if(f2==0)
{
printf("the exact root is %f",x3);
break;
}
else
{
if(f1*f2<0)
x2=x3;
else
x1=x3;
 }
}
while(fabs(x1-x2)>x);
printf("the approx root is %f",x3);
getch();
}

