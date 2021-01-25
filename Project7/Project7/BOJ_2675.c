#include <stdio.h>
#include <string.h>

int main() {
	int T;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		int r;
		char S[21];
		scanf("%d %s", &r, S);
		for (int i = 0; i < strlen(S); i++)
		{
			for (int j = 0; j < r; j++) {
				printf("%c", S[i]);
			}
		}
		puts("");
	}
	return 0;
}