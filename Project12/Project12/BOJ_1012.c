#include <stdio.h>
#include <malloc.h>

int dr[4] = {0,1,0,-1};
int dc[4] = {1,0,-1,0};

/* BFS
typedef struct
{
	int r;
	int c;
	struct node* next;
}node;

void bfs(int** map, node* head, int n, int m) {
	node* tmp, * new, * use;
	int nr, nc;
	use = head->next;
	while (head->next != NULL)
	{
		tmp = head->next;
		for (int i = 0; i < 4; i++) {
			nr = tmp->r + dr[i];
			nc = tmp->c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m)
				continue;
			if (map[nr][nc] != 1)
				continue;
			map[nr][nc] = 0;
			new = (node*)malloc(sizeof(node));
			new->r = nr;
			new->c = nc;
			new->next = NULL;
			use->next = new;
			use = use->next;
		}
		head->next = tmp->next;
		free(tmp);
	}
}
*/

// DFS
void dfs(int** map, int r, int c, int n, int m) {
	int nr, nc;
	for (int i = 0; i < 4; i++)
	{
		nr = r + dr[i];
		nc = c + dc[i];
		if (nr < 0 || nr >= n || nc < 0 || nc >= m)
			continue;
		if (map[nr][nc] == 1) {
			map[nr][nc]--;
			dfs(map, nr, nc, n, m);
		}
	}
	return;
}

int main() {
	int t, T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (t = 0; t < T; t++)
	{
		int M, N, K;
		int a, b;
		int cnt = 0;
		scanf("%d %d %d", &M, &N, &K);
		int** map = (int**)malloc(sizeof(int*) * N);
		for (int i = 0; i < N; i++)
		{
			map[i] = (int*)malloc(sizeof(int) * M);
		}
		for (int k = 0; k < K; k++)
		{
			scanf("%d %d", &b, &a);
			map[a][b] = 1;
		}
		/* BFS
		node* head = (node*)malloc(sizeof(node));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)	{
				if (map[i][j] == 1) {
					cnt++;
					map[i][j]--;
					node* new = (node*)malloc(sizeof(node));
					new->r = i;
					new->c = j;
					new->next = NULL;
					head->next = new;

					bfs(map, head, N, M);
				}
			}
		}
		*/

		// DFS
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					cnt++;
					map[i][j]--;
					dfs(map, i, j, N, M);
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			free(map[i]);
		}
		free(map);
		printf("%d\n", cnt);
	}
	return 0;
}
