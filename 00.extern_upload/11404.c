#include <stdio.h>
#include <malloc.h>

#define min(x, y) x < y ? x : y

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m, a, b, c;
	scanf("%d", &n);
	scanf("%d", &m);
	int arr[101][101];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0xffffff;
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		arr[a - 1][b - 1] = min(arr[a - 1][b - 1], c);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)
					arr[i][j] = 0;
				else
					arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0xfffff)
				printf("0 ");
			else
				printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
