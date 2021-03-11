#include <stdio.h>
#include <malloc.h>

typedef struct nd {
	int st, cnt;
	struct nd* nxt;
}node;

int bfs(node* head, int a) {
	node* tmp, * use, * new;
	use = head->nxt;
	while (head->nxt != NULL) {
		tmp = head->nxt;
		if (tmp->st == a)
			return tmp->cnt;
		if (tmp->st % 10 == 1) {
			if (tmp->st / 10 >= a) {
				new = (node*)malloc(sizeof(node));
				new->st = tmp->st / 10;
				new->cnt = tmp->cnt + 1;
				new->nxt = NULL;
				use->nxt = new;
				use = use->nxt;
			}
		}
		if (tmp->st % 2 == 0) {
			if (tmp->st * 2 >= a) {
				new = (node*)malloc(sizeof(node));
				new->st = tmp->st / 2;
				new->cnt = tmp->cnt + 1;
				new->nxt = NULL;
				use->nxt = new;
				use = use->nxt;
			}
		}
		head->nxt = tmp->nxt;
		free(tmp);
	}
	return -1;
}

int main() {
	long long a, b;
	freopen("input.txt", "r", stdin);
	scanf("%lld %lld", &a, &b);
	node* head = (node*)malloc(sizeof(node));
	node* new = (node*)malloc(sizeof(node));
	new->st = b;
	new->cnt = 1;
	new->nxt = NULL;
	head->nxt = new;
	printf("%d\n", bfs(head, a));
	return 0;
}
