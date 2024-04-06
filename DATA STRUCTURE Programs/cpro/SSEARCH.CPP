//Sequential search method
#include<stdio.h>
#include<conio.h>
void main()
{
  int n[10]={14,6,2,1,8,4,18,5,11,34};
  int i,m,pos=0;
  clrscr();
  printf("\nEnter number to be searched : ");
  scanf("%d",&m);

  printf("\nNumbers in the array are : ");
  for(i=0;i<10;i++)
  {
    printf("%d ",n[i]);
    if(n[i]==m)
    pos=i+1;
  }

  if(pos==0)
    printf("\nThe number %d is not present in the array",m);
  else
    printf("\nThe number %d is present in the array at position %d",m,pos);
  getch();
}

