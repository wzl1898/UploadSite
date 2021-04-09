#include<iostream>
#define MaxNum 100002
using namespace std;
int N;
int arr[MaxNum];
int ori[MaxNum], ending[MaxNum], miding[MaxNum], temp[MaxNum];
void Merge(int* arr, int s, int m, int e, int* temp)
{
	int p1 = s, p2 = m + 1, pb = 0;
	while (p1 <= m && p2 <= e)
	{
		if (arr[p1] > arr[p2])
		{
			miding[arr[p1]] += e - p2 + 1;
			temp[pb++] = arr[p1++];
		}else
		{
			temp[pb++] = arr[p2++];
		}
	}
	while (p1 <= m)
	{
		temp[pb++] = arr[p1++];
	}
	while (p2 <= e)
	{
		temp[pb++] = arr[p2++];
	}
	for (int i = 0; i < e - s + 1; i++)
	{
		arr[i + s] = temp[i];
	}
}
void MergeSort(int* arr, int s, int e, int* temp)
{
	if (s < e)
	{
		int m = s + (e - s) / 2;
		MergeSort(arr, s, m, temp);
		MergeSort(arr, m + 1, e, temp);
		Merge(arr, s, m, e, temp);
		return; 
	}
}
int main()
{
	cin >> N;
	int i;
	for (i = 1; i <= N; i++) 
	{
		cin >> arr[i];
		ori[arr[i]] = i;
		ending[arr[i]] = arr[i];
	}
	MergeSort(arr, 1, N, temp);
	for (i = 1; i <= N; i++)
	{
		miding[i] = ori[i] + miding[i];
	}
	for (i = 1; i <= N; i++)
	{
		int mini = min(ori[i], ending[i]);
		mini = min(mini, miding[i]);
		int maxi = max(ori[i], ending[i]);
		maxi = max(maxi, miding[i]);
		cout << maxi - mini << " ";
	}
	return 0;
}
