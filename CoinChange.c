/*
 ============================================================================
 Name        : CoinChange.c
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
int coinchange(int *,int ,int );

int main()
{
	int n,sum,i,answer;
	printf("Enter the number of coins:\n");
	scanf("%d",&n);
	int *coin = (int *)malloc(sizeof(int) * n);
	printf("Enter the value of coins:\n");
	for(i = 0; i < n; i++)
		scanf("%d",&coin[i]);
	printf("Enter the amount for making change:\n");
	scanf("%d",&sum);

	answer = coinchange(coin,n,sum);
	printf("\nAnswer is:%d",answer);
	getch();
	return 0;
}

int coinchange(int *val,int n,int sum)
{
	int i,j;
	int m[sum+1];
	m[0] = 0;
	for(i = 1; i <= sum; i++)
		m[i] = 999999;
	for(i = 1; i <= sum; i++)
	{
		for(j = 0; j < n; j++)
		{
			if((val[j] <= i) && (m[i - val[j]] + 1 < m[i]))
				m[i] = m[i - val[j]] + 1;
		}
	}
	return m[sum];
}

int max(int a,int b)
{
	return (a > b)? a: b;
}
