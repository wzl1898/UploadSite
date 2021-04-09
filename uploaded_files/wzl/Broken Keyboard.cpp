#include<iostream>
#define MaxNum 1000
#include<cstring>
using namespace std;
char s1[MaxNum];
char s2[MaxNum];
char missing[MaxNum];
int visited[MaxNum];
int Transform(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return c - 'a';
	}
	if (c >= 'A' && c <= 'Z')
	{
		return c - 'A';
	}
	if (c == '_')
	{
		return 26;
	}
	if (c >= '0' && c <= '9')
	{
		return 27 + c - '0';
	}
}
int main()
{
	cin >> s1 >> s2;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int p1 = 0, p2 = 0, idx = 0;
	while (p1 < len1)
	{
		if (s1[p1] == s2[p2])
		{
			p1++;
			p2++;
		}else
		{
			if(visited[Transform(s1[p1])] == 0)
			{
				visited[Transform(s1[p1])] = 1;
				missing[idx++] = s1[p1];
				p1++;
			}else
			{
				p1++;
			}
		}
	}
	for (int i = 0; i < idx; i++)
	{
		if (missing[i] >= 'a' && missing[i] <= 'z')
		{
			cout << (char)(missing[i] + ('A' - 'a'));
		}else
		{
			cout << missing[i];
		}
	}
	return 0;
}
