#include<stdio.h>
#include<conio.h>

void create_heap(int list[], int n )
{

	int k, j, i, temp;

	for(k = 2 ; k <= n;  ++k)
	{
		i = k ;
		temp = list[k];
		j = i / 2 ;

		while((i >1) && (temp > list[j]))
		{
			list[i] = list[j];
			i = j ;
			j = i / 2 ;
			if ( j < 1 )
				j = 1 ;
		}

		list[i] = temp ;
	}
}


void heap_sort(int list[], int n)
{
	int k, temp, value, j, i, p;
	int step = 1;
	for(k = n ; k >= 2; --k)
	{
		temp = list[1] ;
		list[1] = list[k];
		list[k] = temp ;

		i = 1 ;
		value = list[1];
		j = 2 ;

		if((j+1) < k)
			if(list[j+1] > list[j])
				j ++;
		while((j <= ( k-1)) && (list[j] > value))
		{
			list[i] = list[j];
			i = j ;
			j = 2*i ;
			if((j+1) < k)
				if(list[j+1] > list[j])
					j++;
				else
					if( j > n)
						j = n ;
			list[i] = value;
		} /* end of while statement */

		printf("\n Step = %d ", step);
		step++;
		for(p = 1; p <= n; p++)
			printf(" %d", list[p]);
	} /* end for loop */
}

void display(int list[], int n)
{
	int i;
	for(i = 1 ; i <= n; ++ i)
	{
		printf("  %d", list[i]);
	}
}



void main()
{
	int list[100];
	int i, size;
	clrscr();
	printf("\nEnter size of the list (<=100) : ");
	scanf("%d",&size);
	for(i = 1 ; i <= size ; i++)
	{
	    printf("Enter number %d : ",i);
	    scanf("%d",&list[i]);
	}

	printf("\n Entered list is as follows:\n");
	display(list, size);
	create_heap(list, size);
	printf("\n Heap\n");
	display(list, size);
	printf("\n\n");

	heap_sort(list,size);

	printf("\n\n Sorted list is as follows :\n\n");
	display(list,size);

getch();
}
