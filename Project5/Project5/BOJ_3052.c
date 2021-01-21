#include <stdio.h>

int main() {
	freopen("input.txt", "r", stdin);
	int num;
	int cnt = 0;
	int arr[11];
	for (int t = 0; t < 11; t++)
		arr[t] = -1;
	for (int i = 0; i < 11; i++)
	{
		scanf("%d", &num);
		int ch = num % 42;
		for (int j = 0; j < 11; j++)
		{
			if (arr[j] == ch) break;
			if (arr[j] == -1)
			{
				arr[j] = ch;
				cnt++;
				break;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}