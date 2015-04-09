#include <cstring>
#include <iostream>
#include <string>
using namespace std;

typedef struct node 
{
	int count;
	int pass;
	node * next[26];
	node() : count(0), pass(0) { memset(next, 0, 26);}
} node;

node * createTrieTree()
{
	int num;
	cin >> num;
	string str;
	node * root = new node[sizeof(node)];
	for (int i = 0; i < num; i ++)
	{
		cin >> str;
		node * p = root;
		for (int j = 0; j < str.size(); j ++)
		{
			if (p->next[str[j] - 'a'] == NULL)
			{
				node * temp = new node(); // new node[sizeof(node)];  is allocating an array.
				p->next[str[j] - 'a'] = temp;
			}
			p = p->next[str[j] - 'a'];
			p->pass ++;
			if (j == str.size() - 1)
				p->count ++;
		}
		
	}
	return root;
}

int countTimes(node *root, string str)
{
	node *p = root;
	if (p == NULL)
		return 0;
	for (int i = 0; i < str.size(); i ++)
	{
		if (p->next[str[i] - 'a'] == NULL)
			return 0;
		p = p->next[str[i] - 'a'];
	}
	return p->pass;
}

int main()
{
	node *p = createTrieTree();
	int numAsk = 0;
	cin >> numAsk;
	while (numAsk --)
	{
		string str;
		cin >> str;
		cout << countTimes(p, str) << endl;	
	}
	return 0;
}
