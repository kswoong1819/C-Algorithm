/*
#include <stdio.h>

#define min(a, b) (a > b ? b : a)

int dfs(int num) {
	if (num == 1) return 0;
	if (num % 3 == 0) return min(1 + dfs(num / 3), 2 + dfs((num - 1) / 2));
	if (num % 2 == 0) return min(1 + dfs(num / 2), 1 + dfs(num - 1));
	return 1 + dfs(num - 1);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", dfs(n));
	return 0;
}
*/
#include<stdio.h>

#define SZ 1000001
#define MIN(a,b) (a < b ? a : b);

int N;
int N_arr[SZ];

void solution() {
    N_arr[0] = N_arr[1] = 0;
    int temp;
    for (int i = 2; i <= N; i++) {
        N_arr[i] = N_arr[i - 1] + 1;
        if (i % 3 == 0) {
            temp = N_arr[i / 3] + 1;
            N_arr[i] = MIN(N_arr[i], temp);
        }
        if (i % 2 == 0) {
            temp = N_arr[i / 2] + 1;
            N_arr[i] = MIN(N_arr[i], temp);
        }
    }
}

int main() {
    scanf("%d", &N);
    solution();
    printf("%d", N_arr[N]);
}