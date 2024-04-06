/*fiting of st. line by least square approximation*/
#include<vivek.h>
#define n 7
void main()
{
 int i;
 float x[n],y[n],sx=0.0,sy=0.0,sxy=0.0,sqx=0.0,a,b,d;
 clrscr();
 printf("approximation for eq. of st. line y=ax+b\n");
 printf("enter of values of x points");
 for(i=0;i<n;i++)
 {
  scanf("%f",&x[i]);
 }
  printf("enter of values of y points");
 for(i=0;i<n;i++)
 {
  scanf("%f",&y[i]);
 }
 for(i=0;i<n;i++)
 {
  sx=sx+x[i];
  sy=sy+y[i];
  sxy=sxy+(x[i]*y[i]);
  sqx=sqx+pow(x[i],2);
 }
 d=n*sqx-pow(sx,2);
 b=(sy*sqx-sx*sxy)/d;
 a=(n*sxy-sx*sy)/d;
 printf("value of a=%f\n",a);
 printf("value of b=%f\n",b);
 printf("required eq. st. is y=%f x+%f",a,b);
 getch();
}