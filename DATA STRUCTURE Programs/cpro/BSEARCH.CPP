#include<stdio.h>
#include<conio.h>
void main()
{
  int n[10]={4,6,12,21,28,34,38,45,61,84};
  int i,m,start=0,last=9,mid;
  clrscr();
  printf("\nEnter number to be searched : ");
  scanf("%d",&m);
  printf("\nNumbers in the array are : ");
  for(i=0;i<10;i++)
  {
    printf("%d ",n[i]);
  }

  while(start<=last)
  {
    mid=(start+last)/2;
    if(m==n[mid])
    break;
    if(m>n[mid])
     start=mid+1;
    else
     last=mid-1;
   }

   if(start<=last)
    printf("\nThe number %d is present in the array at position %d",m,mid+1);
  else
    printf("\nThe number %d is not present in the array",m);
  getch();
}

