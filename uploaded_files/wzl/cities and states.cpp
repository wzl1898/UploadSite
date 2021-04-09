#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string, int>Map;
int N;
string a, b;
int main()
{
	cin >> N;
	int i;
	int ret = 0;
	for (i = 0 ; i < N; i++)
	{
		cin >> a >> b;
		a = a.substr(0, 2);
		if (a != b)
		{
			ret += Map[a + b];
			Map[b + a] = Map[b + a] + 1;
		}
	}
	cout << ret;
	return 0;
}
