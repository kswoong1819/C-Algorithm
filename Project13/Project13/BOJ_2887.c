#include <stdio.h>

#define MaxSz 100001
#define swap(a, b) {int t=a; a=b; b=t;}

typedef struct {
	int a, b, c;
}list;

int n, x[MaxSz], y[MaxSz], z[MaxSz], check[MaxSz], point[MaxSz];
list L[MaxSz * 3];

void qsort(int l, int r, int* A) {
	if (l < r) {
		int i = l - 1;
		int j = r + 1;
		if (A == L) {
			int m = L[(l + r) / 2].c;
			list t;
			while (1) {
				while (L[++i].c < m);
				while (L[--j].c > m);
				if (i >= j)
					break;
				t = L[i];
				L[i] = L[j];
				L[j] = t;
			}
		}
		else {
			int m = A[(l + r) / 2];
			while (1) {
				while (A[++i] < m);
				while (A[--j] > m);
				if (i >= j)
					break;
				swap(x[i], x[j]);
				swap(y[i], y[j]);
				swap(z[i], z[j]);
				swap(check[i], check[j]);
			}
		}
		qsort(l, i - 1, A);
		qsort(j + 1, r, A);
	}
}

int find(int k) {
	if (point[k] == k)
		return k;
	return point[k] = find(point[k]);
}

int merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return 0;
	else {
		point[b] = a;
		return 1;
	}
}

int main() {
	int* arr[3] = { x, y, z };
	int cnt = 0, result = 0, front = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x[i], &y[i], &z[i]);
		check[i] = i;
		point[i] = i;
	}

	for (int i = 0; i < 3; i++) {
		qsort(0, n - 1, arr[i]);
		for (int j = 1; j < n; j++) {
			L[cnt].c = arr[i][j] - arr[i][j - 1];
			L[cnt].a = check[j];
			L[cnt++].b = check[j - 1];
		}
	}

	qsort(0, cnt - 1, L);
	for (int i = 0; front < n - 1; i++) {
		if (merge(L[i].a, L[i].b)) {
			result += L[i].c;
			front++;
		}
	}

	printf("%d", result);
	return 0;
}