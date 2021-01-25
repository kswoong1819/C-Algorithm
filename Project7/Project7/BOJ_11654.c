#include <stdio.h>

int main() {
	int n, result = 0;
	char nums[101];
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	scanf("%s", &nums);
	for (int i = 0; i < n; i++)
	{
		result += nums[i] - '0';
	}
	printf("%d\n", result);
	return 0;
}