#include<stdio.h>
#include<conio.h>
#include<math.h>
#define n 3
void main()
{
 float b1,b2,b3,x[n],y[n],m,k=0.0,d;
 int i;
 clrscr();
 printf("enter value of x");
 for(i=0;i<n;i++)
 {
  scanf("%f",&x[i]);
  }
 printf("enter value of y for x points");
 for(i=0;i<n;i++)
 {
  scanf("%f",&y[i]);
  }
 printf("enter point to be interpolate");
 scanf("%f",&m);
 d=x[1]-x[0];
 b1=y[0];
 b2=(y[1]-y[0])/d;
 b3=(y[2]-2*y[1]+y[0])/(2*pow(d,2));
 k=b1+b2*(m-x[0])+b3*(m-x[0])*(m-x[1]);
 printf("interpolated value = %f",k);
 getch();
}
