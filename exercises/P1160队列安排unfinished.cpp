#include <cstdio>

struct node {
	int value;
	node* l, r;
	node()
	{
		value = 0;
		l = NULL, r = NULL;
	}
};
typedef people node*;

inline int read();

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#endif

	N = read();
	people queue[N + 1];

	people head = new node;
	head->value = 1;
	queue[1] = head;

	for (register int i = 1; i < N; i++) {
		int k = read(), p = read();

	}

	int M = read();

	for (register int i = 1; i <= M; i++)

	return 0;
}

inline int read()
{
	int x = 0;
	char c = getchar();
	while (c > '9' && c < '0')
		c = getchar();
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x;
}
