
#include<stdio.h>
#include<conio.h>
void hanoi_tower(char , char , char , int );

void hanoi_tower(char peg1, char peg2, char  peg3, int n)
{
	if( n <= 0)
		printf("\n Illegal entry ");

	if(n == 1)
		printf("\n Move Disk from %c to %c", peg1, peg3);
	else
	{
		hanoi_tower(peg1, peg3, peg2, n-1);
		hanoi_tower(peg1, peg2, peg3, 1);
		hanoi_tower(peg2, peg1, peg3, n-1);
	}
}

/* main function */

void main()
{
	int n;
	clrscr();
	printf("\n Input the number of disc: ");
	scanf("%d", &n);
	printf("\n Tower of Hanoi for %d DISC", n);
	hanoi_tower('1', '2', '3', n);
	getch();
}
