#include <stdio.h>

typedef struct {
	int we, from, to;
}road;

int compare(const void* first, const void* second) {
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}

road arr[1000005];
int parent[100005];

int find(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
	x = parent[x];
	y = parent[y];
	parent[x] = y;
}

int main() {
	int n, m, a, b, c;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr[i].we = c;
		arr[i].from = a;
		arr[i].to = b;
	}
	qsort(arr, m, sizeof(road), compare);

	int cnt = 0, k = 0, sum = 0;
	while (cnt != n - 2) {
		a = arr[k].from;
		b = arr[k].to;
		if (find(a) != find(b)) {
			unite(a, b);
			cnt++;
			sum += arr[k].we;
		}
		k++;
	}
	printf("%d\n", sum);
	return 0;
}