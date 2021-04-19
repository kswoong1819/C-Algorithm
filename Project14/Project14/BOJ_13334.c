#include <stdio.h>
#include <malloc.h>

#define MaxSz 100001
#define swap(a, b) {int t = a; a = b; b = t;}
#define max(a, b) (a>b ? a : b)

typedef struct {
	int a, b;
}point;

point* arr[MaxSz];
int heap[MaxSz];

int heapSz = 0;

void qsort(int st, int ed) {
	if (st < ed) {
		int i = st - 1;
		int j = ed + 1;
		int m = arr[(st + ed) / 2]->b;
		point* t;

		while (1) {
			while (arr[++i]->b < m);
			while (arr[--j]->b > m);
			if (i >= j) break;
			t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
		qsort(st, i - 1);
		qsort(j + 1, ed);
	}
}

void heapPush(int x) {
	heap[heapSz] = x;

	int cur = heapSz++;
	while (cur > 0 && heap[cur] < heap[(cur-1)/2]) {
		swap(heap[cur], heap[(cur - 1) / 2]);
		cur = (cur - 1) / 2;
	}
	return;
}

void heapPop() {
	heap[0] = heap[--heapSz];

	int cur = 0;
	while (cur * 2 + 1 < heapSz) {
		int child;
		if (cur * 2 + 2 == heapSz)
			child = cur * 2 + 1;
		else
			child = heap[cur * 2 + 1] < heap[cur * 2 + 2] ? cur * 2 + 1 : cur * 2 + 2;

		if (heap[cur] < heap[child]) break;

		swap(heap[cur], heap[child]);
		cur = child;
	}
	return;
}

int main() {
	int n, h, o, d;
	point* L;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &h, &o);
		L = malloc(sizeof(point));
		if (h < o) {
			L->a = h;
			L->b = o;
		}
		else {
			L->a = o;
			L->b = h;
		}
		arr[i] = L;
	}
	scanf("%d", &d);
	qsort(0, n-1);

	int result = 0;
	for (int i = 0; i < n; i++) {
		int le = arr[i]->a;
		int ri = arr[i]->b;
		
		if (ri - le <= d)
			heapPush(le);

		while (heapSz > 0) {
			if (ri - heap[0] > d)
				heapPop();
			else
				break;
		}

		result = max(result, heapSz);
	}
	printf("%d\n", result);
	return 0;	
}