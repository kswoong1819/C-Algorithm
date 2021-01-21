#include <stdio.h>

int main() {
	int a, b, c;
	int n;
	int arr[10] = {0,};
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &a, &b, &c);
	int total = a * b * c;
	while (total > 0)
	{
		n = total % 10;
		total /= 10;
		arr[n]++;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}