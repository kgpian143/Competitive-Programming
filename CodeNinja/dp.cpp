#include <bits/stdc++.h>
using namespace std;

int subsetSum(int a[], int n, int sum)
{
	// Initializing the matrix
	pair <int , vector<int>> tab[n + 1][sum + 1];
// Initializing the first value of matrix
	tab[0][0].first = 1;
	for (int i = 1; i <= sum; i++)
		tab[0][i].first = 0;
	

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
		// if the value is greater than the sum
			if (a[i - 1] > j)
				tab[i][j] = tab[i - 1][j];
			else
			{
				tab[i][j].first = tab[i - 1][j].first + tab[i - 1][j - a[i - 1]].first;
                tab[i][j].second.push_back() ;
			}
		}
	}


	return tab[n][sum].first;
}

int main()
{
	int n = 4;
	int a[] = {3,3,3,3};
	int sum = 6;

	cout << (subsetSum(a, n, sum));
}
