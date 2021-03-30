#include <stdio.h>
#include <malloc.h>

typedef struct {
	int f, s, w;
}node;

int compare(const void *A, const void *B) {
	node* pA = (node*)A;
	node* pB = (node*)B;

	if (pA->w < pB->w) return -1;
	else if (pA->w > pB->w) return 1;
	else return 0;
}

node* arr[10005];
int check[10005];
/*
int heapsize = 0;

void heappush(node* new) {
	arr[heapsize] = new;

	int current = heapsize;
	while (current > 0 && arr[current]->w < arr[(current - 1)/2]->w) {
		node* tmp = arr[(current - 1) / 2];
		arr[(current - 1) / 2] = arr[current];
		arr[current] = tmp;
		current = (current - 1) / 2;
	}
	heapsize++;
	return;
}

void heappop(node** use) {
	*use = arr[0];
	arr[0] = arr[--heapsize];

	int current = 0;
	while (current * 2 + 1 < heapsize) {
		int child;
		if (current * 2 + 2 == heapsize)
			child = current * 2 + 1;
		else
			child = arr[current * 2 + 1]->w < arr[current * 2 + 2]->w ? current * 2 + 1 : current * 2 + 2;

		if (arr[current]->w < arr[child]->w)
			break;
		
		node* tmp = arr[current];
		arr[current] = arr[child];
		arr[child] = tmp;
		current = child;
	}
	return;
}
*/

int find(int k) {
	if (check[k] == k)
		return k;
	else
		return check[k] = find(check[k]);
}

void unionParent(int x, int y) {
	x = find(x);
	y = find(y);
	check[y] = x;
}

int main() {
	int v, e, a, b, c;
	int ans = 0;
	node* new, * use;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++) {
		check[i] = i;
	}
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		new = (node*)malloc(sizeof(node));
		new->f = a;
		new->s = b;
		new->w = c;
		arr[i] = new;
	}
	/*
	use = (node*)malloc(sizeof(node));
	while (heapsize > 0) {
		heappop(&use);
		if (find(use->f) != find(use->s)) {
			ans += use->w;
			unionParent(use->f, use->s);
		}
	}
	*/
	qsort(arr, 3, sizeof(arr[0]), compare);
	for (int i = 0; i < v; i++) {
		use = arr[i];
		if (find(use->f) != find(use->s)) {
			ans += use->w;
			unionParent(use->f, use->s);
		}
	}
	printf("%d\n", ans);
	return 0;
}