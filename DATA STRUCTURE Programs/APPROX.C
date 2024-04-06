#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
 int i;
 float x=.005678,y,ea,er,ep;
 clrscr();
 printf("exact value of x=%f\n",x);
  i=x*1000;
 y=i/1000.00;
 printf("approximate value is=%f\n",y);
 ea=fabs(y-x);
 er=ea/x;
 ep=er*100;
 printf("absolute error=%f\n",ea);
 printf("relative error=%f\n",er);
 printf("percentage error=%f",ep);
 getch();
}