#include <stdio.h>

#define max_len 101

typedef struct {
	int r;
	int c;
	int d;
}node;

int matrix[max_len][max_len] = {0,};
node arr[max_len * max_len];

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

int n, result = 0, front = 0, rear = 0;

int check_dir(int d, char dir) {
	if (dir == 'L')
		d = (d + 4 - 1) % 4;
	else
		d = (d + 1) % 4;
	return d;
}

int move(int x, char dir) {
	int nr, nc, nd, cnt = 0;
	nr = arr[rear].r;
	nc = arr[rear].c;
	nd = arr[rear].d;
	while (cnt < x)
	{
		cnt++;
		nr += dr[nd];
		nc += dc[nd];
		if (nr < 1 || nr > n || nc < 1 || nc > n || matrix[nr][nc] == 2) {
			result += cnt;
			return 0;
		}
		rear++;
		arr[rear].r = nr;
		arr[rear].c = nc;
		arr[rear].d = nd;
		if (matrix[nr][nc] == 0) {
			matrix[arr[front].r][arr[front].c] = 0;
			front++;
		}
		matrix[nr][nc] = 2;
	}
	arr[rear].d = check_dir(arr[rear].d, dir);
	result += cnt;
	return 1;
}

int main() {
	int k, l, flag;
	int a, b, c;
	char d;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int ki = 0; ki < k; ki++) {
		scanf("%d %d", &a, &b);
		matrix[a][b] = 1;
	}
	arr[0].r = 1;
	arr[0].c = 1;
	arr[0].d = 0;
	matrix[1][1] = 2;
	scanf("%d", &l);
	for (int li = 0; li < l; li++) {
		scanf("%d %c", &c, &d);
		flag = move(c - result, d);
		if (!flag)
			break;
	}
	if (flag)
		move(max_len, d);
	printf("%d", result);
	return 0;
}
