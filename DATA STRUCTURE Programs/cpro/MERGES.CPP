/*Program of sorting using quick sort through recursion*/
#include<stdio.h>
#include<conio.h>
void mergeSortedArray(int a[],int sa,int b[],int sb,int c[],int sc)
{
  int ca,cb,cc;
  ca=cb=cc=0;
  while(ca<sa && cb<sb)
  {
    if(a[ca]<b[cb])
    {
      c[cc]=a[ca];
      ca++;
      cc++;
    }
    else
    {
     c[cc]=b[cb];
     cb++;
     cc++;
    }
  }
  while(ca<sa)
  {
    c[cc]=a[ca];
    ca++;
    cc++;
  }
  while(cb<sb)
  {
    c[cc]=b[cb];
    cb++;
    cc++;
  }
}
/////////////////////////////////////////////////////////////////////
void show(int n[],int size)
{
  int i;
  for(i=0;i<size;i++)
  printf("%d ",n[i]);
}

void main()
{
  int a[5]={4,8,12,34,78};
  int b[5]={3,6,15,33,56};
  int c[10];
  clrscr();
  mergeSortedArray(a,5,b,5,c,10);
  printf("\nSorted Array : ");
  show(c,10);
  getch();
}