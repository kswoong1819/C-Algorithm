#include <stdio.h>

#define MAX_LEN 101

int matrix[MAX_LEN][MAX_LEN];
int bfsvisit[MAX_LEN];
int dfsvisit[MAX_LEN];
int queue[MAX_LEN];
int cnt = 0;

int bfs(int n, int v) {
	int front = 0, rear = 0, pop;
	queue[rear++] = n;
	bfsvisit[n] = 1;

	while (front < rear)
	{
		pop = queue[front++];
		for (int i = 1; i <= v; i++)
		{
			if (matrix[pop][i] == 1 && !bfsvisit[i]) {
				bfsvisit[i] = 1;
				queue[rear++] = i;
				cnt++;
			}
		}
	}

	return 0;
}

int dfs(int n, int v) {
	dfsvisit[n] = 1;
	for (int i = 1; i <= v; i++)
	{
		if (matrix[n][i] == 1 && !dfsvisit[i]) {
			dfsvisit[i] = 1;
			cnt++;
			dfs(i, v);
		}
	}

	return 0;
}

int main() {
	int v, n, a, b;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &v, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		matrix[a][b] = matrix[b][a] = 1;
	}
	// bfs(1, v);
	dfs(1, v);
	printf("%d", cnt);
	return 0;
}