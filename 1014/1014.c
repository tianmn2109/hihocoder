#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct node
{
	int next[26];
	int count;
} T[1000000];

void init(int len)
{
	int i = 0;
	for (i = 0 ;i < 26; i ++)
		T[len].next[i] = 0;
	T[len].count = 0;
}

int len = 0;

void insert(char * s)
{
	int i = 0;
	int p = 0;
	while (s[i] != '\0')
	{
		if (T[p].next[s[i] - 'a'] == 0)
		{
			init(len);
			T[p].next[s[i] - 'a'] = len ++;
		}
		p = T[p].next[s[i] - 'a'];
		T[p].count ++;
		i ++;
	}
}

int query(char *s)
{
	int i = 0;
	int p = 0;
	while (s[i] != '\0')
	{
		if (T[p].next[s[i] - 'a'] == 0)
			return 0;
		p = T[p].next[s[i] - 'a'];
		i ++;
	}
	return T[p].count;
}

int main()
{
	int num;
	char s[11];
	init(0);
	len = 1;
	scanf("%d", &num);
	while (num --)
	{
		scanf("%s", s);
		insert(s);
	}
	scanf("%d", &num);
	while (num --)
	{
		scanf("%s", s);
		printf("%d\n", query(s));
	}
	return 0;
}
