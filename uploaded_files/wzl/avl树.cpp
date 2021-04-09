#include<iostream>
#define MaxNum 100001
#include<stdlib.h> 
using namespace std;
struct node
{
	double data;
	int height;
	struct node* left;
	struct node* right;
};
typedef struct node* tree;
int getheight(tree T)
{
	if (!T)
	{
		return 0;
	}
	int ret = getheight(T->left);
	int sum = getheight(T->right);
	if (sum > ret)
	{
		ret = sum;
	}
	ret++;
	return ret;
	//return max(getheight(T->left), getheight(T->right)) + 1;
}
tree ll(tree A)
{
	tree B = A->left;
	A->left = B->right;
	B->right = A;
	A->height = max(getheight(A->left), getheight(A->right)) + 1;
	B->height = max(getheight(B->left), A->height) + 1;
	return B;
}
tree rr(tree A)
{
	tree B = A->right;
	A->right = B->left;
	B->left = A;
	A->height = max(getheight(A->left), getheight(A->right)) + 1;
	B->height = max(getheight(B->right), A->height) + 1;
	return B;
}
tree lr(tree A)
{
	A->left = rr(A->left);
	return ll(A);
}
tree rl(tree A)
{
	A->right = ll(A->right);
	return rr(A);
}
tree Insert(tree T, int n)
{
	if (!T)
	{
		T = (tree)malloc(sizeof(struct node));
		T->left = T->right = NULL;
		T->data = n;
		T->height = 0;
	}else if (n < T->data)
	{
		T->left = Insert(T->left, n);
		if (getheight(T->left) - getheight(T->right) == 2)
		{
			if (n < T->left->data)
			{
				T = ll(T);
			}else
			{
				T = lr(T);
			}
		}
	}else if (n > T->data)
	{
		T->right = Insert(T->right, n);
		if (getheight(T->left) - getheight(T->right) == -2)
		{
			if (n > T->right->data)
			{
				T = rr(T);
			}else
			{
				T = rl(T);
			}
		}
	}
	T->height = max(getheight(T->left), getheight(T->right)) + 1;
	return T;
}
int Find(double n, tree T)
{
	if (n == T->data)
	{
		return 1;
	}
	if (n < T->data)
	{
		return Find(n, T->left) + 1;
	}else
	{
		return Find(n, T->right) + 1;
	}
}
int N;
double arr[MaxNum];
tree root;
int main()
{
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> arr[i];
		root = Insert(root, arr[i]);
	}
	for (i = 0; i < N; i++)
	{
		int ret = Find(arr[i], root);
		cout << ret;
		if (i + 1 < N)
		{
			cout << " ";
		}
	}
	return 0;
}
