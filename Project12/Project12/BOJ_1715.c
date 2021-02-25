#include <stdio.h>

#define MaxSz 100001
#define swap(a, b) {int t=a; a=b; b=t;}

int heap[MaxSz];
int heapSize = 0;

void heapPush(int num) {
	heap[heapSize] = num;
	int current = heapSize++;
	while (current > 0 && heap[current] < heap[(current - 1) / 2])
	{
		swap(heap[current], heap[(current - 1) / 2]);
		current = (current - 1) / 2;
	}
	return;
}

int heapPop() {
	if (heapSize <= 0)
		return -1;
	int Nnum = heap[0];
	heap[0] = heap[--heapSize];
	int current = 0;
	while (current * 2 + 1 < heapSize) {
		int child;
		if (current * 2 + 2 == heapSize) {
			child = current * 2 + 1;
		}
		else {
			child = heap[current * 2 + 1] < heap[current * 2 + 2] ? current * 2 + 1 : current * 2 + 2;
		}

		if (heap[current] < heap[child])
			break;
		swap(heap[current], heap[child]);
		current = child;
	}
	return Nnum;
}

int main() {
	int n, num, tmp;
	int result = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		heapPush(num);
	}
	if (n == 1) {
		printf("%d\n", 0);
		return 0;
	}
	while (1)
	{
		int total = 0;
		for (int i = 0; i < 2; i++) {
			tmp = heapPop();
			if (tmp < 0) {
				break;
			}
			total += tmp;
		}
		result += total;
		if (heapSize == 0)
			break;
		heapPush(total);
	}
	printf("%d\n", result);
	return 0;
}
