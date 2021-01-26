#include <stdio.h>

int main() {
	char str[1000001];
	int i, n, arr[26] = { 0 }, maxidx = 0, maxcnt = 0;
	scanf("%s", str);
	for (i = 0; str[i] != 0; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			n = str[i] + 32 - 97;
		}
		else {
			n = str[i] - 97;
		}
		arr[n]++;
		if (maxcnt < arr[n]) {
			maxcnt = arr[n];
			maxidx = n;
		}
	}
	for (i = 0; i < 26; i++) {
		if (i != maxidx && maxcnt == arr[i]) {
			printf("?");
			return 0;
		}
	}
	printf("%c", maxidx + 65);
	return 0;
}