//Selection sort
#include<stdio.h>
#include<conio.h>
void bubble(int n[],int noe)
{
  int i,j,t;
  for(i=0;i<noe-1;i++)
  {
    for(j=0;j<noe-1-i;j++)
    {
      if(n[j]>n[j+1])
      {
       t=n[j];
       n[j]=n[j+1];
       n[j+1]=t;
      }
    }
  }
}

void show(int *n,int size)
{
  int i;
  for(i=0;i<size;i++)
  printf("%d ",*(n+i));
}

void main()
{
  int n[10]={4,6,2,1,18,14,8,5,11,34};
  clrscr();
  printf("\nThe numbers in original order : ");
  show(n,10);
  bubble(n,10);
  printf("\nThe numbers in sorted order   : ");
  show(n,10);
  getch();
}
