#include <stdio.h>
#include <malloc.h>

#define min(a, b) (a>b ? b : a)

typedef struct {
	int st, ed, wh;
	struct node* nxt;
}node;

node* arr[1001];
long long dk[1001];

void bfs(int s, int e) {
	node* head, * tmp, * new, * use, *re, *fr;
	head = (node*)malloc(sizeof(node));
	new = (node*)malloc(sizeof(node));
	head->nxt = arr[s];
	use = head;
	while (use)
	{
		tmp = use->nxt;
		while (tmp) {
			dk[tmp->ed] = min(dk[tmp->ed], tmp->wh + dk[tmp->st]);
			if (arr[tmp->ed]) {
				fr = (node*)malloc(sizeof(node));
				re->nxt = arr[tmp->ed];
				while (re)
				{
					fr->nxt = new;
					new = arr[tmp->ed];
				}
			}
			tmp = tmp->nxt;
		}
	}

	return;
}

int main() {
	int n, m, s, e, w, fs, fe;
	node* tmp;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		dk[i] = 10e+10;
	}
	for (int i = 0; i < m; i++)	{
		scanf("%d %d %d", &s, &e, &w);
		tmp = (node*)malloc(sizeof(node));
		tmp->st = s;
		tmp->ed = e;
		tmp->wh = w;
		tmp->nxt = arr[s];
		arr[s] = tmp;
	}
	scanf("%d %d", &fs, &fe);
	dk[fs] = 0;
	bfs(fs, fe);
}