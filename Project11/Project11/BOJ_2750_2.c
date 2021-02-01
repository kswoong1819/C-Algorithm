#include <stdio.h>

#define swap(a,b) {int t; t = a; a = b; b = t;}

void quick_sort(int *data, int start, int end) {
	if (start >= end) {
		return;
	}
	int pivot = start;
	int i = pivot + 1;
	int j = end;

	while (i <= j)
	{
		while (i <= end && data[pivot] >= data[i]) i++;
		while (j > start && data[pivot] <= data[j]) j--;
		if (i > j) {
			swap(data[j], data[pivot])
		}
		else {
			swap(data[j], data[i])
		}
	}
	quick_sort(data, start, j - 1);
	quick_sort(data, j + 1, end);
}

int main() {
	int n;
	int data[1000001];
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	quick_sort(data, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", data[i]);
	}
	return 0;
}