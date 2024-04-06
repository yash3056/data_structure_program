/*secant method f(x)=(x*x*x-2*x-5)*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) (x*x*x-2*x-5)
void main()
{
float x1,x2,x3,f1,f2,epsilon;
clrscr();
printf("enter value of x1,x2");
scanf("%f%f",&x1,&x2);
printf("enter value of tolerance");
scanf("%f",&epsilon);
do
{
f1=f(x1);
f2=f(x2);
x3=(x1*f2-x2*f1)/(f2-f1);
if(f(x3)==0)
{
printf("the exact root is %f",x3);
break;
}
else
{
x1=x2;
x2=x3;
}
}
while(abs(x3-x2)>epsilon);
printf("the approx root is %f",x3);
getch();
}
