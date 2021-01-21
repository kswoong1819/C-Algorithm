#include <stdio.h>

int main() {
	int c;
	freopen("input.txt", "r", stdin);
	scanf("%d", &c);
	for (int i = 0; i < c; i++)
	{
		int n, j, arr[1001], sum = 0, cnt = 0;
		double avg = 0;
		scanf("%d", &n);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &arr[j]);
			sum += arr[j];
		}
		avg = sum / n;
		for (j = 0; j < n; j++)
		{
			if (avg < arr[j]) cnt++;
		}
		printf("%.3lf%%\n", (double)cnt / n * 100);
	}
	return 0;
}