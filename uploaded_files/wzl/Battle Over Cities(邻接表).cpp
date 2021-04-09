#include<iostream>
#include<cstring>
#include<stdlib.h>
#define MaxNum 1000 
using namespace std;
int N, M, K;

int visited[MaxNum];
int Check[MaxNum];
struct LNode
{
	int data;
	struct LNode* next; 
};
typedef struct LNode* List;
struct GNode
{
	int nv, ne;
	List G[MaxNum];
};
typedef struct GNode* Graph;
Graph Gr;
Graph CreateGraph(int N)
{
	Graph Gr = (Graph)malloc(sizeof(struct GNode));
	Gr->nv = Gr->ne = 0;
	int i;
	for (i = 1; i <= N; i++)
	{
		Gr->G[i] = (List)malloc(sizeof(struct LNode));
		Gr->G[i]->next = NULL;
	}
	return Gr;
}
struct ENode
{
	int v1, v2;
};
typedef struct ENode* Edge;
void Insert(Edge E)
{
	Gr->ne++;
	List cell = (List)malloc(sizeof(struct LNode));
	cell->data = E->v2;
	cell->next = Gr->G[E->v1]->next;
	Gr->G[E->v1]->next = cell;
	List cell2 = (List)malloc(sizeof(struct LNode));
	cell2->data = E->v1;
	cell2->next = Gr->G[E->v2]->next;
	Gr->G[E->v2]->next = cell2;
	free(E);
	return;
}
void DFS(int n, int m)
{
	visited[n] = 1;
	List pt = Gr->G[n]->next;
	while (pt)
	{
		if (visited[pt->data] == 0 && pt->data != m)
		{
			DFS(pt->data, m);
		}
		pt = pt->next;
	}
	return;
}

int main()
{
	cin >> N >> M >> K;
	Gr = CreateGraph(N);
	memset(visited, 0, sizeof(visited));
	int i, j;
	for (i = 0; i < M; i++)
	{
		Edge E = (Edge)malloc(sizeof(struct ENode));
		cin >> E->v1 >> E->v2;
		Insert(E);
	}
	for (i = 0 ; i < K; i++)
	{
		cin >> Check[i];
	}
	int cnt = 0;
	for (i = 0; i < K; i ++)
	{
		for (j = 1; j <= N; j++)
		{
			if (visited[j] == 0 && j != Check[i])
			{
				DFS(j, Check[i]);
				cnt++;
			}
		}
		cout << cnt - 1;
		if (i + 1 < K)
		{
			cout << endl;
		}
		cnt = 0;
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}
