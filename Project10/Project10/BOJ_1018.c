#include <stdio.h>

#define MAX_N 51

int n, m;
int cnt = 0;
char matrix[MAX_N][MAX_N];
int visit[MAX_N][MAX_N];
int queue[MAX_N][2];
int front = 0, rear = 0;

void bfs_scan() {
	visit[0][0] = 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", matrix[i]);
	}
	bfs_scan(0, 0);
	printf("%c ", matrix[3][3]);
	return 0;
}