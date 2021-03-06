#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#define N 31
using namespace std;

double wlen[N], blen[N];
double wDP[N][N * N], bDP[N][N * N];
double ans[N][N * N];
//F[i,j] = (Len[i]-j+1)*F[i-1,j-1] + F[i-1,j]

inline void Init(double len[N], double DP[N][N * N])
{
	int i, j;
	memset(DP, 0, sizeof(DP));
	for (i = 0; i <= N - 1; i++) DP[i][0] = 1;
	for (i = 1; i <= N - 1; i++)
		for (j = 1; j <= len[i]; j++)
			DP[i][j] = (len[i] - j + 1) * DP[i - 1][j - 1] + DP[i - 1][j];
	return ;
}

int main()
{
	int i, j, k;
	wlen[0] = -1, wlen[1] = 1;
	blen[0] = 0, blen[1] = 2;
	for (i = 2; i <= N - 1; i++)
	{
		wlen[i] = wlen[i - 2] + 2;
		blen[i] = blen[i - 2] + 2;
	}
	Init(wlen, wDP);
	Init(blen, bDP);
	memset(ans, 0, sizeof(ans));
	for (i = 1; i <= N - 1; i++)
	{
		for (j = 1; j <= (N - 1) * (N - 1); j++)
			for (k = 0; k <= j; k++)
				if (k <= wlen[i] && j - k <= blen[i - 1])
					ans[i][j] += wDP[i][k] * bDP[i - 1][j - k];
	}
	while (scanf("%d %d", &i, &j) != EOF)
	{
		if (i == 0 && j == 0) break;
		printf("%.lf\n", ans[i][j]);
	}
}