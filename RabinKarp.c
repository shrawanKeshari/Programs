/*
 ============================================================================
 Name        : RabinKarp.c
 Author      : Pawan Keshari
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

void rabinkarp(char *, char *, int );
#define digit 256

int main()
{
    char *txt = "Shrawan Kumar Keshari";
	char *patt = "Kumar";
	int prime = 101;
	rabinkarp(txt,patt,prime);
	getch();
	return 0;
}

void rabinkarp(char *text, char *pattern, int prime)
{
	int i,j,mul = 1;
	int length_text = strlen(text);
	int length_pattern = strlen(pattern);
	int hash_text = 0;
	int hash_pattern = 0;
	for(i = 0 ; i < length_pattern - 1 ; i++)
	{
		mul = (mul * digit) % prime;
	}
	for(i = 0 ; i < length_pattern ; i++)
	{
		hash_pattern = (hash_pattern * digit + pattern[i]) % prime;
		hash_text = (hash_text * digit + text[i]) % prime;
	}
    for(i = 0 ; i <= (length_text - length_pattern) ; i++)
    {
    	if(hash_text == hash_pattern)
    	{
    		for(j = 0 ; j < length_pattern ; j++)
    		{
    			if(text[i + j] != pattern[j])
    				break;
    		}
    		if(j == length_pattern)
    		{
    			printf("\nString Matches at:%d",i);
    		}
    	}
    	if(i < length_text - length_pattern)
    	{
    		hash_text = (digit * ( hash_text - text[i] * mul) + text[i + length_pattern]) % prime;
    		if( hash_text < 0)
    			hash_text = hash_text + prime;
    	}
    }
}
