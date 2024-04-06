/*Program of sorting using quick sort through recursion*/
#include<stdio.h>
#include<conio.h>
#define MAX 30
void display(int arr[],int low,int up)
{
    int i;
    for(i=low;i<=up;i++)
    printf("%d ",arr[i]);
}

void quick(int arr[],int low,int up)
{
    int piv,temp,left,right;
    int pivot_placed=0;
    left=low;
    right=up;
    piv=low; /*Take the first element of sublist as piv */

    if(low>=up)
      return ;


    while(pivot_placed==0)
    {
		while( arr[piv]<=arr[right] && piv!=right )
		right=right-1;

		if( piv==right )
		      pivot_placed=1;

		if( arr[piv] > arr[right] )
		{
			temp=arr[piv];
			arr[piv]=arr[right];
			arr[right]=temp;
			piv=right;
		}
		/*Compare from left to right */

		while( arr[piv]>=arr[left] && left!=piv )
		left=left+1;

		if(piv==left)
		pivot_placed=1;

		if( arr[piv] < arr[left] )
		{
			temp=arr[piv];
			arr[piv]=arr[left];
			arr[left]=temp;
			piv=left;
		}
    }


   quick(arr,low,piv-1);
   quick(arr,piv+1,up);
}


void main()
{
	int array[MAX],n,i;
	clrscr();
	printf("Enter the number of elements : ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
	 printf("Enter element %d : ",i+1);
	 scanf("%d",&array[i]);
	}

	printf("Unsorted list is :\n");
	display(array,0,n-1);
	printf("\n");

	quick(array,0,n-1);

	printf("Sorted list is :\n");
	display(array,0,n-1);
	printf("\n");
	getch();
}
















