/*
 ============================================================================
 Name        : boyermoore.c
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
#define no_of_char 256

void boyermoore(char *, char *);
void shift_function(char *, int , int table[]);

int main()
{
	char *txt = "Shrawan Kumar Keshari";
	char *patt = "Kumar";
	//printf("1");
	boyermoore(txt,patt);
	getch();
	return 0;
}

void boyermoore(char *text, char *pattern)
{   //printf("2");
	int i,j;
	int length_patt = strlen(pattern);
	int length_txt = strlen(text);
	int shift_table[no_of_char];
	shift_function(pattern,length_patt,shift_table);
	i = j = length_patt - 1;
	//printf("3");
	while(i < length_txt)
	{   //printf("4");
		if(pattern[j] == text[i])
		{
			i--;
			j--;
		}
		else
		{
			if( j < 0)
			{
				printf("String matches at:%d",i + 1);
				j = j + length_patt;
				i = (i + 1) + (j + 1);
			}
			else
			{
				i = i + shift_table[(int) text[i]];
				while(j < length_patt - 1)
					j++;
			}
		}
	}
}

void shift_function(char *patt, int length, int table[no_of_char])
{
	int i,j;
	for(i = 0 ; i < no_of_char ; i++)
		table[i] = length;

	for(j = 0 ; j <= length - 2 ; j++)
		table[(int) patt[j]] = length - 1 - j;
}
