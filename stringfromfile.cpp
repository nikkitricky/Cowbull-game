#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int file_length(FILE* fp){
	char ch;
	int count = 0;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == '\n')
		{
			count++;
		}
	}
	return count;
}
void stringy(char str[50]){
	FILE* l=fopen("dict.txt","r");
	int len= file_length(l);
	FILE* fp = fopen("dict.txt", "r");
	time_t t;
	int slip = 0;
	srand((unsigned)time(&t));
	int count=rand() % len;
	char ch;
	while (slip!=count){
		int i = 0;
		while ((ch = fgetc(fp)) != '\n'){
			str[i++] = ch;
		}
		str[i] = '\0';
		slip++;
	}
	
}
int *strarr(char *a)
{
	int l = strlen(a), i, *r;
	r = (int *)calloc(sizeof(int), 26);
	for (i = 0; i<l; i++)
		r[a[i] - 'a'] = i + 1;
	return r;
}
int check(char *s, char *c)
{
	int *is, *ic, cow = 0, bull = 0, ls = strlen(s), i;
	is = strarr(s); ic = strarr(c);
	for (i = 0; i<26; i++)
	{
		if (is[i] != 0 && ic[i] != 0)
		{
			if (is[i] == ic[i])
				cow++;
			else
				bull++;
		}
	}
	printf("\nCOWS:%d\nBULLS:%d\n", cow, bull);
	if (cow == ls)
		return 1;
	else
		return 0;
}
int main()
{
	
	int n, i = 0;
	
	char *u, c;
	u = (char*)malloc(sizeof(char) * 100);
	
	printf("\nENTER INPUT:");
	char s[50];
	stringy(s);
	//printf("%s", s);
	printf("\nString to be guessed is of length:%d\n------------------------------------------------------", strlen(s));
	do{
		printf("\nGuess a word:");
		scanf("%s", u); i++;
	} while (!check(s, u));
	printf("\n You Guessed word in %d Chances\n\n\n", i);
	system("pause");
		
	return 0;
}