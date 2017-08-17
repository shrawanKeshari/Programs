/*
 ============================================================================
 Name        : KMP.c
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

void kmp(char *, char *);
void prefixfunction(char *,int ,int *);

int main()
{
	char *txt = "Shrawan Kumar Keshari";
	char *patt = "Kumar";
	kmp(txt,patt);
	getch();
	return 0;
}

void kmp(char *text, char *pattern)
{
	int length_patt = strlen(pattern);
	int length_txt = strlen(text);
	int *prefix_table = (int *)malloc(length_patt * sizeof(int));
	prefixfunction(pattern,length_patt,prefix_table);
	int i =0;
	int j = 0;
	while(i < length_txt)
	{
		if(pattern[j] == text[i])
		{
			j++;
			i++;
		}
		if(j == length_patt)
		{
			printf("String matches at:%d",i-j);
			j = prefix_table[j - 1];
		}
		else if(i < length_txt && pattern[j] != text[i])
		{
			if(j != 0)
				j = prefix_table[j - 1];
			else
				i = i + 1;
		}
	}
}

void prefixfunction(char *patt,int length,int *table)
{
	int len = 0, i = 1;
	table[0] = 0;
	while(i < length)
	{
		if(patt[i] == patt[len])
		{
			len++;
			table[i] = len;
			i++;
		}
		else
		{
			if(len != 0)
				len = table[len - 1];
			else
			{
				table[i] = 0;
				i++;
			}
		}
	}
}
