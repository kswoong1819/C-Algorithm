#include <stdio.h>

#define MAX_LEN 1001

int matrix[MAX_LEN][MAX_LEN] = { 0 };
int dfsvisit[MAX_LEN] = { 0 };
int bfsvisit[MAX_LEN] = { 0 };
int queue[MAX_LEN];

int dfs(int v, int n) {
	dfsvisit[v] = 1;
	printf("%d ", v);
	for (int i = 1; i <= n; i++)
	{
		if (matrix[v][i] == 1 && !dfsvisit[i]) {
			dfs(i, n);
		}
	}

	return 0;
}

int bfs(int v, int n) {
	int front = 0, rear = 0, pop;
	printf("%d ", v);
	queue[0] = v;
	rear++;
	bfsvisit[v] = 1;

	while (front < rear) {
		pop = queue[front];
		front++;
		for (int i = 1; i <= n; i++)
		{
			if (matrix[pop][i] == 1 && !bfsvisit[i]) {
				printf("%d ", i);
				queue[rear] = i;
				rear++;
				bfsvisit[i] = 1;
			}
		}
	}

	return 0;
}

int main() {
	int n, m, v;
	int a, b;
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		matrix[a][b] = matrix[b][a] = 1;
	}
	dfs(v, n);
	printf("\n");
	bfs(v, n);
	return 0;
}