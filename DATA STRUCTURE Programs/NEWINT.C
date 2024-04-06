#include<stdio.h>
#include<conio.h>
#include<math.h>
#define n 5
void main()
{
 float u,b1,b2,b3,b4,*x,*y,m,*a,*s,*d,*e,t,w;
 int i,j=0,f=0,k=0,l=0;
 clrscr();
 printf("enter value of x,y");
 for(i=0;i<n;i++)
 {
  scanf("%f%f",&x[i],&y[i]);
 }
 printf("\nenter point to be interpolate");
 scanf("%f",&m);
 for(i=0;i<n;i++)
 {
  if(i>0)
  {
  a[j]=(y[i]-y[i-1]);
  j++;
  }
}
for(j=0;j<n-1;j++)
{
 if(j>0)
 {
  s[f]=(a[j]-a[j-1]);
  f++;
 }
}
 for(f=0;f<n-2;f++)
 {
  if(f>0)
  {
   d[k]=(s[f]-s[f-1]);
   k++;
 }
 }
 for(k=0;k<n-3;k++)
 {
  if(k>0)
  {
   e[l]=d[k]-d[k-1];
   }
 }
 printf("\nThe difference table is:\n");
 j=0;l=0;k=0;f=0;
 for(i=0;i<n;i++)
 {
  printf("\n%f ",y[i]);
  if(i>0)
  {
   printf("%f ",a[j]);
   j++;
  }
  if(i>1)
  {
   printf("%f ",s[l]);
   l++;
  }
  if(i>2)
  {
   printf("%f ",d[k]);
   k++;
  }
  if(i>3)
  {
   printf("%f ",e[f]);
   f++;
  }
 }
  u=(m-x[0]);
  t=x[1]-x[0];
  b1=u/t;
  b2=(u*(u-1)/(2*pow(t,2)));
  b3=(u*(u-1)*(u-2))/(6*pow(t,4));
  b4=(u*(u-1)*(u-2)*(u-3))/(24*pow(t,4));
  w=y[0]+(a[0]*b1)+(s[0]*b2)+(d[0]*b3)+(e[0]*b4);
  printf("\n\ninterpolated value = %f",w);
 getch();
}