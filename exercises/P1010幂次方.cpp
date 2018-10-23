#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int N;

inline string calc ( int x, int i );

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	scanf ("%d", &N);

	cout << calc(N, 0);

	return 0;
}

inline string calc ( int x, int i )
{
	string s;
	if (x == 0)
		return "0";
	do 
		if (x & 1)
			s = (i == 1 ? "2" : "2(" + calc(i, 0) + ")") + (s == "" ? "" : "+") + s;
	while (++i, x >>= 1);
	return s;
}
