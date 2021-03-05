#include <stdio.h>
#include <malloc.h>

#define Ms 100001
#define min(a, b) (a>b ? b : a)

int visited[Ms] = { 0, };
int arr[4];
int ans = 0, cnt = 0;

void value(int t) {
	arr[0] = t + 1;
	arr[1] = t - 1;
	arr[2] = t * 2;
}

void bfs(int k) {

}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	bfs(k);
	printf("%d\n%d", ans, cnt);
	return 0;
}