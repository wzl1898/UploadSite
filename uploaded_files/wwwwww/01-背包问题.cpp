#include<iostream>
using namespace std;
int Max(int a, int b)
{
	return (a > b) ? a : b;
}
int main()
{
	int N ,M;
	cin >> N >> M;
	int d[N], w[N];
	int i, j;
	int a[M+1];
	for (i = 0; i < N; i++)
	{
		cin >> w[i] >> d[i];
	}
	for (i = 0; i < M+1; i++)
	{
		a[i] = 0;
	}
	for (i = 0; i < N; i++)
	{
		for (j = M; j > 0; j--)
		{
			if (j - w[i] >= 0)
				a[j] = Max(a[j], d[i] + a[j - w[i]]);
		}
	}
	cout << a[M] << endl;
	return 0;
}
