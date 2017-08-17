/*
 ============================================================================
 Name        : LCS.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int max(int ,int );
int LCS(char *,int ,char *,int );

int main()
{
	int n,m,lenght;
	printf("Enter the size of two arrays:\n");
	scanf("%d %d",&m,&n);
	char *x = (char *)malloc(sizeof(char) * m);
	char *y = (char *)malloc(sizeof(char) * n);
	printf("Enter the strings:\n");
	scanf("%s",x);
	scanf("%s",y);
	lenght = LCS(x,m,y,n);
	printf("%d",lenght);
	getch();
	return 0;
}

int LCS(char *x,int m,char *y,int n)
{
	int i,j;
	int LCS[m+1][n+1];
	for(i = 0; i <= m; i++)
		LCS[i][0] = 0; //if taking element from y array but not from x array.
	for(j = 0; j <= n; j++)
		LCS[0][j] = 0; //if taking element from x array but not from y array.
	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(x[i - 1] == y[j - 1])
				LCS[i][j] = 1 + LCS[i -1][j - 1];
			else
				LCS[i][j] = max(LCS[i - 1][j],LCS[i][j - 1]);
		}
	}
	return LCS[m][n];
}

int max(int a,int b)
{
	return (a > b)? a : b;
}
