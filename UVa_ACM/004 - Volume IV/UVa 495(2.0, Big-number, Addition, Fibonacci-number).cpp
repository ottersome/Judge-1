#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 5000; // the longest digits of big number
struct bign
{
	int len, s[maxn];
	bign(){ memset(s, 0, sizeof(s)); len = 1; } // constructor

	bign operator = (const char *num) // assignment by C string
	{
		len = strlen(num);
		for (int i = 0; i < len; i++) s[i] = num[len - i - 1] - '0';
		return *this;
	}

	bign operator = (int num)
	{
		char s[maxn];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}

	bign(int num) { *this = num; }
	bign(const char *num) { *this = num; } // support "bign N = xxx;" feature

	string str() const // transform bign to string
	{
		string res = "";
		for (int i = 0; i < len; i++) res = (char)(s[i] + '0') + res;
		if (res == "") res = "0"; // boundary: when N == 0
		return res;
	}

	friend istream& operator >> (istream &in, bign &x) // istream: input stream -> cin
	{
		string s;
		in >> s; // read in a string
		x = s.c_str(); // transform into C string
		return in;
	}

	friend ostream& operator << (ostream &out, const bign &x) // ostream: output stream -> cout
	{
		out << x.str();
		return out;
	}

	bign operator + (const bign &b) const
	{
		bign c;
		c.len = 0;
		for (int i = 0, g = 0; g || i < max(len, b.len); i++) // g: carry
		{
			int x = g;
			if (i < len) x += s[i];
			if (i < b.len) x += b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;
		}
		return c;
	}

	bign operator += (const bign &b)
	{
		*this = *this + b;
		return *this;
	}

	bool operator < (const bign &b) const // comparison
	{
		if (len != b.len) return len < b.len;
		for (int i = len - 1; i >= 0; i--)
			if (s[i] != b.s[i]) return s[i] < b.s[i];
		return false;
	}
	bool operator > (const bign &b) const { return b < *this; }
	bool operator <= (const bign &b) const { return !(b < *this); } // to avoid too much function call, so we don't write !(b > *this)
	bool operator >= (const bign &b) const { return !(*this < b); }
	bool operator != (const bign &b) const { return b < *this || *this < b; } // one is smaller than the other
	bool operator == (const bign &b) const { return !(b < *this) && !(*this < b); }
};

#define MAX 5010
int n;
bign fibo[MAX];

int main()
{
	fibo[0] = 0; fibo[1] = 1;
	for (int i = 2; i < MAX; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	while (scanf("%d", &n) != EOF)
	{
		printf("The Fibonacci number for %d is ", n);
		cout << fibo[n] << endl;
	}
}