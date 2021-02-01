#include <stdio.h>
#include <malloc.h>

//int sorted[1001];
typedef int int32;
typedef short int16;
typedef unsigned char uint8;
typedef long long int64;

int64 data;

typedef struct
{
	int a;
	int b;
	int c;//a+b;
}DATA_;

DATA_ sum(DATA_ in)
{
	in.c = in.a + in.b;
	return in;
}



void merge(int* data, int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = start;

	//int	sorted[1001];
	int* sorted = (int*)malloc(sizeof(int) * (end - start + 1));
	k = 0;
	while (i <= mid && j <= end) {
		if (data[i] <= data[j]) {
			sorted[k++] = data[i++];
		}
		else {
			sorted[k++] = data[j++];
		}
	}
	if (i > mid) {
		for (int t = j; t <= end; t++) {
			sorted[k] = data[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= mid; t++) {
			sorted[k] = data[t];
			k++;
		}
	}
	k = 0;
	for (int t = start; t <= end; t++)
	{
		data[t] = sorted[k++];
	}
	free(sorted);
}

void merge_sort(int* data, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(data, start, mid);
		merge_sort(data, mid + 1, end);
		merge(data, start, mid, end);
	}
}

int main() {
	int n;
	int data[1001];
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}

	merge_sort(data, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		printf("%d\n", data[i]);
	}
	return 0;
}