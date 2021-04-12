#include <stdio.h>

#define MaxSz 100001
#define INF 987654321
#define min(a, b) (a>b ? b : a)

int arr[MaxSz];

int main() {
	int n, s;
	int result = INF;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int front = 0, rear = 0, sum = arr[0];
	while (front <= rear && rear < n) {
		if (sum < s) {
			sum += arr[++rear];
		}
		else if (sum == s) {
			result = min(result, rear - front + 1);
			sum += arr[++rear];
		}
		else {
			result = min(result, rear - front + 1);
			sum -= arr[front++];
		}
	}
	if (result == INF)
		printf("0");
	else
		printf("%d", result);
	return 0;
}