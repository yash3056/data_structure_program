//Insertion Sort
#include<stdio.h>
#include<conio.h>
void insertion(int n[],int size)
{
  int i,j,t;
  for(i=1;i<size;i++)
  {
    t=n[i];
    for(j=i-1;j>=0 && t<n[j];j--)
    {
      n[j+1]=n[j];
    }
    n[j+1]=t;
  }
}

void show(int n[],int size)
{
  int i;
  for(i=0;i<size;i++)
  printf("%d ",n[i]);
}

void main()
{
  int n[10]={4,6,2,1,18,14,8,5,11,34};
  clrscr();
  printf("\nThe numbers in original order : ");
  show(n,10);
  insertion(n,10);
  printf("\nThe numbers in sorted order   : ");
  show(n,10);
  getch();
}
