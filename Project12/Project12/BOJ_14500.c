#include <stdio.h>
#include <malloc.h>

#define max_len 501
#define max(a, b) (a > b ? a : b)

int n, m;
int result = 0;
int matrix[max_len][max_len];

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

void dfs(int r, int c, int k, int cur) {
	int nr, nc, tmp;
	if (k == 4) {
		result = max(result, cur);
		return;
	}
	for (int i = 0; i < 4; i++) {
		nr = r + dr[i];
		nc = c + dc[i];
		if (nr < 0 || nr >= n || nc < 0 || nc >= m)
			continue;
		if (matrix[nr][nc] == -1)
			continue;
		tmp = matrix[nr][nc];
		matrix[nr][nc] = -1;
		dfs(nr, nc, k+1, cur + tmp);
		matrix[nr][nc] = tmp;
	}
	return;
}

void plus(int r, int c, int cur) {
	int nr, nc, total, nj;
	for (int i = 0; i < 4; i++) {
		total = cur;
		for (int j = i; j < i+3; j++) {
			nj = j % 4;
			nr = r + dr[nj];
			nc = c + dc[nj];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m)
				break;
			total += matrix[nr][nc];
			if (j == i + 2) {
				result = max(result, total);
			}
		}
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	/*
	int** matrix = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * m);
		for (int j = 0; j < m; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		free(matrix[i]);
	}
	free(matrix);
	*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp = matrix[i][j];
			matrix[i][j] = -1;
			dfs(i, j, 1, tmp);
			plus(i, j, tmp);
			matrix[i][j] = tmp;
		}
	}


	printf("%d\n", result);
	return 0;
}
