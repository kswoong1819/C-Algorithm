#include <stdio.h>

int main() {
	int n, i;
	double arr[1000], max = 0, avg = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%lf", &arr[i]);
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	for (int j = 0; j < n; j++)
	{
		avg += arr[j] / max * 100;
	}
	/* printf("%.2lf", avg / (double)n); */
	printf("%lf", avg / n);
	return 0;
}