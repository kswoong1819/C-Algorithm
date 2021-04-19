#include <stdio.h>

#define MaxSz 500001

int parent[MaxSz];

int find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

int main() {
	int n, m, a, b;
	int result = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		parent[i] = i;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		a = find(a);
		b = find(b);
		if (a != b) {
			if (a < b)
				parent[b] = a;
			else
				parent[a] = b;
		}
		else {
			result = i + 1;
			break;
		}
	}
	printf("%d", result);
	return 0;
}