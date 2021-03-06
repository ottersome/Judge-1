#include <stdio.h>
#include <iostream>
using namespace std;

int dp[7][7] = {
	{1000, 1000, 1, 1000, 1, 1000, 1},
	{1000, 1000, 1000, 1, 1, 1000, 1000},
	{1, 1000, 1000, 1, 1000, 1, 1},
	{1000, 1, 1, 1000, 1000, 1, 1000},
	{1, 1, 1000, 1000, 1000, 1000, 1000},
	{1000, 1000, 1, 1, 1000, 1000, 1},
	{1, 1000, 1, 1000, 1000, 1, 1000}
};

int main()
{
	int i, j, k;
	for (k = 0; k < 7; k ++)
		for (i = 0; i < 7; i++)
			for (j = 0; j < 7; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	while (cin >> i >> j, (i || j))
		cout << ((dp[i][j] == 1000)? 0: dp[i][j]) << endl;
}