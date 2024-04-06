


#include<stdio.h>
#include<conio.h>
int arr[100];
int tn=0;
/////////////////////////////////////////////////////////////////
void addstart(int num)
{
  int i;
  if(tn==100)
   printf("\nArray overflow");
  else
  {
    for(i=tn;i>0;i--)
    arr[i]=arr[i-1];
    arr[0]=num;
    tn++;
  }
}
//////////////////////////////////////////////////////////////////////
void addlast(int num)
{
  int i;
  if(tn==100)
   printf("\nArray overflow");
  else
  {
    arr[tn]=num;
    tn++;
  }
}
//////////////////////////////////////////////////////////////////////
void addposition(int num,int pos)
{
  int i;
  if(tn==100)
   printf("\nArray overflow");
  else
  {
    if(pos>=1 && pos<=tn+1)
    {
      if(pos==1)
      addstart(num);
      else if(pos==tn+1)
      addlast(num);
      else
      {
	for(i=tn;i>=pos;i--)
	arr[i]=arr[i-1];
	arr[pos-1]=num;
	tn++;
      }
    }
    else
    printf("\nInvalid position");
  }
}
////////////////////////////////////////////////////////////////////////
void printlist()
{
  int i;
  if(tn==0)
  printf("The list is empty");
  else
  {
    printf("\nThe numbers in the list are : \n");
    for(i=0;i<tn;i++)
    printf("%d ",arr[i]);
  }
}
///////////////////////////////////////////////////////////////////////////
void deletestart()
{
  int i;
  if(tn==0)
  printf("\nThe list is empty");
  else
  {
    printf("\nThe number %d removed from the list",arr[0]);
    for(i=0;i<tn-1;i++)
    arr[i]=arr[i+1];
    tn--;
  }
}
////////////////////////////////////////////////////////////////////////
void deletelast()
{
  int i;
  if(tn==0)
  printf("\nThe list is empty");
  else
  {
    printf("\nThe number %d removed from the list",arr[tn-1]);
    tn--;
  }
}
///////////////////////////////////////////////////////////////////
void deleteposition(int pos)
{
  int i;
  if(tn==0)
  printf("\nThe list is empty");
  else
  {
    if(pos>=1 &&  pos<=tn)
    {
     if(pos==1)
     deletestart();
     else if(pos==tn)
     deletelast();
     else
     {
       printf("\nThe number %d removed from the list",arr[pos-1]);
       for(i=pos-1;i<tn-1;i++)
       arr[i]=arr[i+1];
       tn--;
     }
    }
    else
    printf("\nInvalid position");
  }
}

void main()
{
  int num,pos,ch;
  while(1)
  {
   clrscr();
   printf("\n                          Menu");
   printf("\n                        ---------");
   printf("\n                    1. Insert number at start");
   printf("\n                    2. Insert number at last");
   printf("\n                    3. Insert number at position");
   printf("\n                    4. Delete number at start");
   printf("\n                    5. Delete number at last");
   printf("\n                    6. Delete number at position");
   printf("\n                    7. Print List");
   printf("\n                    8. Exit");
   printf("\n\nEnter your choice (1-8) : ");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
	printf("Enter number : ");
	scanf("%d",&num);
	addstart(num);
	break;
     case 2:
	printf("Enter number : ");
	scanf("%d",&num);
	addlast(num);
	break;
     case 3:
	printf("Enter number : ");
	scanf("%d",&num);
	printf("Enter position : ");
	scanf("%d",&pos);
	addposition(num,pos);
	break;
     case 4:
	deletestart();
	break;
     case 5:
	deletelast();
	break;
     case 6:
	printf("Enter position : ");
	scanf("%d",&pos);
	deleteposition(pos);
	break;
     case 7:
	printlist();
	break;
     case 8:
	return;
     default:
	printf("\nInvalid choice");
   }
   printf("\nPress any key to continue...");
   getch();
  }
}