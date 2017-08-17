/*
 ============================================================================
 Name        : Factorial.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
long int trailing_zeros();

int main(void) {
//	long int t,n;
//	int i=0;
//	scanf("%ld",&t);
//	while(i<t){
//		scanf("%ld",&n);
//		printf("%ld\n",trailing_zeros(n));
//		i++;
//	}
	int i= 0;
	if(i)
		printf("Printed...");
	else
		printf("Not Printed...");
	return 0;
}

long int trailing_zeros(long int n){
	int i=1;
	long int sum=0;
	while(n/pow(5,i)>=1){
		sum = sum + n/pow(5,i);
		i++;
	}
	return sum;
}

