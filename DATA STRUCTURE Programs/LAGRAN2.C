#include<stdio.h>
#include<conio.h>
#include<math.h>
#define n 5
void main()
{
 float x[n],y[n],m,k=0.0,d;
 int i,j,s=1;
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
for(i=0;i<n;i++)
{
 d=1.0;
 for(j=0;j<n;j++)
 {
  if(i!=j)
  d=d*((m-x[j])/(x[i]-x[j]));
 }
  printf("value of lagrange's %d polynomial is = %f\n",s,d);
  k=k+d*y[i];
  s++;
}
printf("the required interpolated value = %f",k);
getch();
}