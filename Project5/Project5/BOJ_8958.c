#include <stdio.h>
#include <string.h>

int main() {
	int n, cnt;
	char arr[81];
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr);
		int result = 0, cnt = 1;
		for (int j = 0; j < strlen(arr); j++)
		{
			if (arr[j] == 'X') {
				cnt = 1;
			}
			else {
				result += cnt++;
			}
		}
		printf("%d\n", result);
	}
	return 0;
}