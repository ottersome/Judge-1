#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n, tmp;
	while (scanf("%d", &n), n)
	{
		while (n / 10)
		{
			for (tmp = 0; n; n /= 10) tmp += n % 10;
			n = tmp;
		}
		printf("%d\n", n);
	}
}