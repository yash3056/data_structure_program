#include<stdio.h>
#include<conio.h>
#include <MATH.H>
void main()
{
 int i;
 float j,k,l,m,ea;
 clrscr();
 printf("enter values of j,k");
 scanf("%f%f",&j,&k);
 l=j+k;
 printf("exact sol. l=%f",l);
 i=l*1000;
 m=i/1000.00;
 printf("\napprox sol. m=%f",m);
 ea=fabs(m-l);
 printf("\nabsolute error=%f",ea);
 getch();
}

