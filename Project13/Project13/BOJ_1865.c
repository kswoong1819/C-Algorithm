#include <stdio.h>
#include <malloc.h>

#define INF 100000000
#define min(a,b) (a>b ? b : a)

typedef struct nd {
	int ed, wt;
	struct nd* nxt;
}node;

void bfs(int p, int n, node* head, node** arr, int* dist) {
	node* use, * new, * tmp, * now;
	use = head->nxt;
	while (head->nxt != NULL) {
		tmp = head->nxt;
		now = arr[tmp->ed];
		while (now->nxt != NULL) {
			int we = now->wt + dist[tmp->ed];
			if (we < dist[now->ed]) {
				dist[now->ed] = we;
				if (dist[p] < 0) return;
				new = (node*)malloc(sizeof(node));
				new->ed = now->ed;
				new->wt = 0;
				new->nxt = NULL;
				use->nxt = new;
				use = use->nxt;
			}
			now = now->nxt;
		}
		head->nxt = tmp->nxt;
		free(tmp);
	}
	return;
}

int main() {
	int tc, n, m, w, s, e, t;
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int T = 0; T < tc; T++) {
		scanf("%d %d %d", &n, &m, &w);
		node* arr[501];
		node* tmp, * new, * head;
		int dist[501];
		int flag = 1;
		for (int i = 1; i <= n; i++) {
			dist[i] = INF;
			head = (node*)malloc(sizeof(node));
			head->nxt = NULL;
			arr[i] = head;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &s, &e, &t);
			new = (node*)malloc(sizeof(node));
			new->ed = e;
			new->wt = t;
			new->nxt = arr[s];
			arr[s] = new;

			new = (node*)malloc(sizeof(node));
			new->ed = s;
			new->wt = t;
			new->nxt = arr[e];
			arr[e] = new;
		}
		int queue[201] = { 0, };
		int front = 0, rear = 0;
		for (int i = 0; i < w; i++) {
			scanf("%d %d %d", &s, &e, &t);
			new = (node*)malloc(sizeof(node));
			new->ed = e;
			new->wt = t * -1;
			new->nxt = arr[s];
			arr[s] = new;
			queue[rear++] = e;
		}
		while (front < rear) {
			int q = queue[front++];
			head = (node*)malloc(sizeof(node));
			tmp = (node*)malloc(sizeof(node));
			tmp->ed = q;
			tmp->wt = 0;
			tmp->nxt = NULL;
			head->nxt = tmp;
			dist[q] = 0;
			bfs(q, n, head, arr, dist);
			if (dist[q] < 0) {
				printf("YES\n");
				flag = 0;
				break;
			}
			for (int i = 1; i <= n; i++) {
				dist[i] = INF;
			}
		}
		if (flag)
			printf("NO\n");
	}
	return 0;
}