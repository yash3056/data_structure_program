/*newton raphson method*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
float f(float);
float df(float);
void main()
{
float x1,x0,f1,f2,epsilon;
clrscr();
printf("enter initial approximation");
scanf("%f",&x0);
printf("enter value of tolerance");
scanf("%f",&epsilon);
do
{
f1=f(x0);
f2=df(x0);
x1=x0-(f1/f2);
if(f(x1)==0)
{
printf("the exact root is %f",x1);
break;
}
else
x0=x1;
}
while((abs(x1-x0)>epsilon));
printf("the approx root is %f",x1);
getch();
}
float f(float x)
{
 float y=0.0;
 y=x*x*x-4*sin(x)-9;
 return y;
}
float df(float x)
{
 float f=0.0;
 f=3*x*x-4*cos(x);
 return f;
}