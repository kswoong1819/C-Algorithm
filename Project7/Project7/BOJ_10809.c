#include <stdio.h>
#include <string.h>

int main() {
	char S[101];
	int arr[26], i, j;
	for (i = 0; i < 26; i++) arr[i] = -1;
	freopen("input.txt", "r", stdin);
	scanf("%s", S);
	for (i = 0; i < strlen(S); i++)
	{
		if (arr[S[i] - 97] < 0) {
			arr[S[i] - 97] = i;
		}
	}
	for (j = 0; j < 26; j++)
	{
		printf("%d ", arr[j]);
	}
	return 0;
}