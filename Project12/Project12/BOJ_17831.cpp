#include <stdlib.h>
#include <stdio.h>

#define N 200000
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct node {
	size_t n, c;
	int *arr;
} list[N];

int weights[N];

struct result {
	int inc, non;
} res[N];

void add_parent(int c, int p) {
	struct node *n = &list[p];

	if (n->n == n->c) {
		n->c = n->c ? n->c*2 : 1;
		n->arr = realloc(n->arr, sizeof n->arr[0] * n->c);
	}

	n->arr[n->n++] = c;
}

void solve(int p) {
	struct node *n = &list[p];
	if (n->n == 0) {
		return;
	}

	for (size_t i = 0; i < n->n; i++) {
		solve(n->arr[i]);
		res[p].non += MAX(res[n->arr[i]].inc, res[n->arr[i]].non);
	}
	for (size_t i = 0; i < n->n; i++) {
		int cur = res[p].non + weights[p]*weights[n->arr[i]];
		if (res[n->arr[i]].inc > res[n->arr[i]].non)
			cur += res[n->arr[i]].non - res[n->arr[i]].inc;
		
		res[p].inc = MAX(res[p].inc, cur);
	}
}

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		int p;
		scanf("%d", &p);
		add_parent(i, p-1);
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &weights[i]);

	solve(0);
	printf("%d\n", MAX(res[0].inc, res[0].non));
}
