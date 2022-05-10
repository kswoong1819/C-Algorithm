#include <stdio.h>
#include <malloc.h>

int result = 0xffffff;

void floyd_wardshall(int len, int **arr) {
	for (int z = 0; z < len; z++)
		for (int i = 0; i < len; i++)
			for (int j = 0; j < len; j++) {
				if (arr[i][j] > arr[i][z] + arr[z][j])
					arr[i][j] = arr[i][z] + arr[z][j];
			}
}

void back_tracking(int cnt, int n2, int k2, int **arr, int *visit, int cur) {
	if (cnt == n2) {
		if (result > cur)
			result = cur;
		return;
	}
	for (int i = 0; i < n2; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		back_tracking(cnt + 1, n2, i, arr, visit, cur + arr[k2][i]);
		visit[i] = 0;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int n, k;
	scanf("%d %d", &n, &k);
	int** arr = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	}
	floyd_wardshall(n, arr);
	
	int *visited = (int*)calloc(n, sizeof(int));
	visited[k] = 1;
	back_tracking(1, n, k, arr, visited, 0);
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	*/
	for (int i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
	free(visited);

	printf("%d", result);

	return 0;
}
