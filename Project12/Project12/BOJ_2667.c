#include <stdio.h>
#include <malloc.h>

#define size 25
#define SZnode sizeof(node)
#define swap(a, b) {int t; t = a; a = b; b = t;}

char matrix[size][size];
int house[size * size] = {0,};
int house_cnt = 0;

int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};

typedef struct
{
	int r;
	int c;
	struct node* next;
}node;

void bfs(node* head, int n);
void quick_sort(int* house, int start, int end);

int main() {
	int n;
	node* head, * new;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", matrix[i]);
	}
	head = (node*)malloc(SZnode);
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == '1') {
				house_cnt++;
				house[house_cnt]++;
				matrix[i][j] = '0';
				new = (node*)malloc(SZnode);
				new->r = i;
				new->c = j;
				new->next = NULL;
				head->next = new;

				bfs(head, n);
			}
		}
	}
	quick_sort(house, 0, house_cnt);
	printf("%d\n", house_cnt);
	for (int k = 1; k <= house_cnt; k++)
	{
		printf("%d\n", house[k]);
	}
	return 0;
}

void bfs(node* head, int n) {
	node* tmp, * new, * use;
	int nr, nc;

	use = head->next;
	while (head->next != NULL) {
		tmp = head->next;
		for (int i = 0; i < 4; i++) {
			nr = tmp->r + dr[i];
			nc = tmp->c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= n)
				continue;
			if (matrix[nr][nc] == '0')
				continue;
			matrix[nr][nc] = '0';
			new = (node*)malloc(SZnode);
			new->r = nr;
			new->c = nc;
			new->next = NULL;
			use->next = new;
			use = use->next;
			house[house_cnt]++;
		}
		head->next = tmp->next;
		free(tmp);
	}
}

void quick_sort(int* house, int start, int end) {
	if (start >= end) {
		return;
	}
	int pivot = start;
	int i = pivot + 1;
	int j = end;

	while (i <= j)
	{
		while (i <= end && house[pivot] >= house[i]) i++;
		while (j > start && house[pivot] <= house[j]) j--;
		if (j < i) {
			swap(house[j], house[pivot]);
		}
		else {
			swap(house[j], house[i]);
		}
	}
	quick_sort(house, start, j - 1);
	quick_sort(house, j + 1, end);
}