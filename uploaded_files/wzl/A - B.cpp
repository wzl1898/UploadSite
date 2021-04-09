#include<iostream>
#include<map>
#include<cstring>
#define MaxNum 10001
using namespace std;
char s1[MaxNum], s2[MaxNum];
int len1, len2;
map<char, int>M;
int main()
{
	cin.getline(s1, sizeof(s1));
	cin.getline(s2, sizeof(s2));
	len1 = strlen(s1);
	len2 = strlen(s2);
	int i;
	for (i = 0; i < len2; i++)
	{
		M[s2[i]] = 1;
	}
	for (i = 0; i < len1; i++)
	{
		if (M[s1[i]] == 1)
		{
			continue;
		}else
		{
			cout << s1[i];
		}
	}
	return 0;
}
