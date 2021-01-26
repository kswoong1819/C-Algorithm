#include <stdio.h>

int main() {
	int cnt = 0, t, T;
	scanf("%d", &T);
	for (t = 0; t < T; t++) {
		char str[101];
		int check[26] = { 0 }, i, n, c;
		scanf("%s", str);
		for (i = 0; i < strlen(str); i++) {
			n = str[i] - 97;
			while (str[i] == str[i + 1]) {
				i++;
			}
			if (check[n] > 0) break;
			check[n]++;
			if (i == strlen(str) - 1) cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}