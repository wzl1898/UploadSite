#include<iostream>
#define MaxNum 101
#define ll long long 
using namespace std;
int N;
struct cell
{
	int numerator;
	int denominator;
	int flag = 1;
};
struct cell cells[MaxNum];
ll LCM = 1;

ll GreatestCommonDivisor(ll a, ll b)

{

    ll t;
	ll temp;
    if (a < b)

    {

        temp = a;

        a = b;

        b = temp;

    }    

    while (b != 0)

    {

        t = a % b;

        a = b;

        b = t;

    }

    return a;

}
ll LeastCommonMultiple (ll a, ll b)

{

	ll c = GreatestCommonDivisor(a, b);
    ll t = a * b /c;

    return t;

}
int main()
{
	cin >> N;
	int i;
	int Flag = 1;
	for (i = 0; i < N; i++)
	{ 
		cin >> cells[i].numerator;
		getchar(); 
		cin >> cells[i].denominator;
		if (cells[i].numerator < 0)
		{
			cells[i].flag *= -1;
			cells[i].numerator *= -1;
		}
		if (cells[i].denominator < 0)
		{
			cells[i].flag *= -1;
			cells[i].denominator *= -1; 
		}
	}
	LCM = cells[0].denominator;
	for (i = 0; i < N; i++)
	{
		LCM = LeastCommonMultiple(LCM, cells[i].denominator);
	}
	ll tot = 0;
	for (i = 0; i < N; i++)
	{
		tot += cells[i].flag * cells[i].numerator * (LCM / cells[i].denominator);
	}
	int flag = 0;
	
	if (tot < 0)
	{
		Flag = -1;
		tot *= -1;
	}
	
	if (tot > LCM)
	{
		flag = 1;
		if (Flag == -1)
		{
			cout << "-";
		}
		cout << tot / LCM;
	}
	tot = tot % LCM;
	int div = GreatestCommonDivisor(tot, LCM);
	tot /= div;
	LCM /= div;
	if (tot > 0)
	{
		if (flag == 1)
		{
			cout << " "; 
		}
		if (Flag == -1)
		{
			cout << "-";
		}
		cout << tot << "/" << LCM;
	}
	return 0;
}
