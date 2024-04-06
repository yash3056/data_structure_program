#include<vivek.h>
float fx(float a,float b)
{
 float c;
 c=-(a*b);
 return c;
}
void main()
{
 int i=0;
 float x0,y0,h,x,s1,x1,y1;
 clrscr();
 printf("enter value of x0,x:\n");
 scanf("%f%f",&x0,&x);
 printf("enter value of y0:");
 scanf("%f",&y0);
 printf("enter value of h:");
 scanf("%f",&h);
 do
 {
  printf("value of x%d=%f\tvalue of y%d=%f\n",i,x0,i,y0);
  s1=fx(x0,y0);
  x1=x0+h;
  y1=y0+h*s1;
  x0=x1;
  y0=y1;
  i++;
 }
 while(x0!=x);
  printf("value of x%d=%f\tvalue of y%d=%f\n",i,x0,i,y0);
 printf("\ny(%f)=%f",x,y1);
 getch();
}
