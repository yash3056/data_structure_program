/* MERGE SORT */
# include<stdio.h>
# include<stdlib.h>
#include<conio.h>
void merge_sort(int *, int , int , int );
void merge_pass(int *, int , int );

/* Definition of the function
void merge_sort(int l[], int top, int size, int bottom)
{
	int temp[1000];
	int f = top;
	int s = size +1 ;
	int t = top ;
	int upper;
	while(( f <= size)&&(s <=bottom))
	{
		if(l[f] <= l[s])
		{
			temp[t] = l[f] ;
			f ++;
		}

		else
		{
			temp[t] = l[s] ;
			s ++;
		}

		t ++;
	}

	if(f <=size)
	{
		for(f = f ; f<=size; f++)
		{
			temp[t] = l[f];
			t++;
		}
	}

	else
	{
		for(s = s ; s<= bottom ; s++)
		{
			temp[t]=l[s];
			t++;
		}

	}

	for(upper = top; upper <= bottom ; upper++)
	{
		l[upper]=temp[upper];
	}

}
*/

void merge_sort(int *append,int a,int b,int c)
{
  int ca,cb,cc,i;
  int *p=(int *)malloc((c+1)*sizeof(int));
  ca=0;
  cb=b+1;
  cc=0;

  while(ca<=b && cb<=c)
  {
    if(append[ca]<append[cb])
    {
      p[cc]=append[ca];
      ca++;
      cc++;
    }
    else
    {
     p[cc]=append[cb];
     cb++;
     cc++;
    }
  }
  while(ca<=b)
  {
    p[cc]=append[ca];
    ca++;
    cc++;
  }
  while(cb<=c)
  {
    p[cc]=append[cb];
    cb++;
    cc++;
  }
  for(i=0;i<=c;i++)
  append[i]=p[i];
}


void merge_pass(int *append, int m, int n )
{
  if( m!= n)
  {
    int mid = (m+n)/2;
    merge_pass( append, m, mid );
    merge_pass( append, mid+1, n );
    merge_sort( append, m, mid, n );
  }
}

/* main function */

void main()
{
	int *list;
	int i, n;
	clrscr();
	printf("\nHow many numbers to sort ");
	scanf("%d",&n);
	list=(int *)malloc(n*sizeof(int));
	for(i = 0 ; i < n ; i++)
	{
	 printf("Enter number %d : ",i+1);
	 scanf("%d",&list[i]);
	}

	printf("\n Entered list as follows:\n");
	for( i = 0 ; i<n ; i++)
		printf("%4d", list[i]);

	i = 0 ;

	merge_pass(list, i, n-1);

	printf("\n Merge sorted list is as follows:\n");

	for( i = 0 ; i<n ; i++)
	printf("%4d",list[i]);
   getch();
   free(list);
}





