#include <stdio.h>

int n;
int arr[51][2];
int result[51];

int level(int arr[][2]) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < n; ++j)
		{
			int a = arr[i][0], b = arr[i][1];
			int c = arr[j][0], d = arr[j][1];
			if (a > c && b > d) {
				result[j]++;
			}
			else if (a < c && b < d) {
				result[i]++;
			}
		}
	}
	return 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);
		result[i] = 1;
	}
	level(arr);
	for (int j = 0; j < n; j++)
	{
		printf("%d ", result[j]);
	}
	return 0;
}