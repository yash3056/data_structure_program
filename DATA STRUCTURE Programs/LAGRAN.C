/*lagrangian methed*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#define maxpt 5
void main()
{
float x[maxpt],y[maxpt],a,sum=0,px;
int i,j;
clrscr();
printf("enter the x points");
for(i=0;i<maxpt;i++)
{
scanf("%f",&x[i]);
}
printf("enter value of y for x");
for(j=0;j<maxpt;j++)
{
scanf("%f",&y[j]);
}
printf("enter value of x for interpolation");
scanf("%f",&a);
for(i=0;i<maxpt;i++)
{
px=1;
for(j=0;j<maxpt;j++)
{
if(i!=j)
px=px*(a-x[j])/(x[i]-x[j]);
}
sum=sum+y[i]*px;
}
printf("interpolated value=%f",sum);
getch();
}

