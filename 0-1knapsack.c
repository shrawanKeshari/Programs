/*
 ============================================================================
 Name        : 0-1knapsack.c
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
int knapsack(int *, int *,int ,int );

int main()
{
	int n,i,m,max_benifit;
	printf("Enter the size of weight and benifit array:\n");
	scanf("%d",&n);
	printf("Enter the maximum capacity of knapsack:\n");
	scanf("%d",&m);
	int *weight = (int *)malloc(sizeof(int) * n);
	int *benifit = (int *)malloc(sizeof(int) * n);
	printf("Enter the weight and benifit:\n");
	for(i = 0; i < n; i++)
		scanf("%d %d",&weight[i],&benifit[i]);

	max_benifit = knapsack(weight,benifit,n,m);
	printf("\nMaximum Benifit is:%d",max_benifit);
	getch();
	return 0;
}

int knapsack(int *wt,int *ben,int n,int m)
{
	int i,w;
	int b[n+1][m+1];
	for(i = 0; i <= n; i++)
		b[i][0] = 0;
	for(w = 0; w <= m; w++)
		b[0][w] = 0;
	for(i = 1; i <= n; i++)
	{
		for(w = 1; w <= m; w++)
		{
			if(wt[i - 1] <= w)
				b[i][w] = max((ben[i - 1] + b[i - 1][w - wt[i - 1]]),b[i - 1][w]);
			else
				b[i][w] = b[i - 1][w];
		}
	}
	return b[n][m];
}

int max(int a,int b)
{
	return (a > b)? a: b;
}
