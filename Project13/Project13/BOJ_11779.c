#include <stdio.h>
#include <malloc.h>

#define min(a, b) (a>b ? b : a)
#define MaxLen 1001
#define MaxSz 10e10

int arr[MaxLen][MaxLen];
long long dk[MaxLen][2];
int cnt = 0;
int result[MaxLen];

void bfs(int n, int start, int end) {
	int queue[MaxLen * 10];
	int front = 0, rear = 0;
	queue[rear++] = start;
	while (front < rear)
	{
		int tmp = queue[front++];
		for (int i = 1; i <= n; i++) {
			if (arr[tmp][i] >= 0 && arr[tmp][i] < 1000001) {
				int dif = min(dk[i][0], dk[tmp][0] + arr[tmp][i]);
				if (dif < dk[i][0]) {
					dk[i][0] = dif;
					dk[i][1] = tmp;
					if (end == i)
						continue;
					queue[rear++] = i;
				}
			}
		}
	}
	return;
}

void road(int start, int end) {
	if (start == end) {
		return;
	}
	result[cnt++] = dk[end][1];
	road(start, dk[end][1]);
}

int main() {
	int n, m, s, e, w, fs, fe;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		dk[i][0] = MaxSz;
		dk[i][1] = 0;
		for (int j = 1; j <= n; j++) {
			arr[i][j] = 1000001;
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &s, &e, &w);
		if (arr[s][e] > w)
			arr[s][e] = w;
	}
	scanf("%d %d", &fs, &fe);
	dk[fs][0] = 0;
	dk[fs][1] = 1;
	bfs(n, fs, fe);
	printf("%lld\n", dk[fe][0]);
	result[cnt++] = fe;
	road(fs, fe);
	printf("%d\n", cnt);
	for (int i = cnt-1; i >= 0; i--) {
		printf("%d ", result[i]);
	}
	return 0;
}
