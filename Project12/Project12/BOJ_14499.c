#include <stdio.h>
#include <malloc.h>

static int n, m, x, y, k, d;
int map[21][21];
int cube[6] = { 0, };

int dr[5] = { 0,0,0,-1,1 };
int dc[5] = { 0,1,-1,0,0 };

int move(int d) {
	int* new = (int*)malloc(sizeof(int) * 6);
	int nx, ny;
	nx = x + dr[d];
	ny = y + dc[d];
	if (nx < 0 || nx >= n || ny < 0 || ny >= m)
		return 0;
	x = nx;
	y = ny;
	if (d == 1) {
		new[0] = cube[2];
		new[1] = cube[3];
		new[2] = cube[1];
		new[3] = cube[0];
		new[4] = cube[4];
		new[5] = cube[5];
	}
	if (d == 2) {
		new[0] = cube[3];
		new[1] = cube[2];
		new[2] = cube[0];
		new[3] = cube[1];
		new[4] = cube[4];
		new[5] = cube[5];
	}
	if (d == 3) {
		new[0] = cube[4];
		new[1] = cube[5];
		new[2] = cube[2];
		new[3] = cube[3];
		new[4] = cube[1];
		new[5] = cube[0];
	}
	if (d == 4) {
		new[0] = cube[5];
		new[1] = cube[4];
		new[2] = cube[2];
		new[3] = cube[3];
		new[4] = cube[0];
		new[5] = cube[1];
	}
	for (int i = 0; i < 6; i++) {
		cube[i] = new[i];
	}
	return 1;
}

void change() {
	int a = map[x][y];
	int b = cube[1];
	if (a == 0) {
		map[x][y] = b;
	}
	else {
		cube[1] = a;
		map[x][y] = 0;
	}
	printf("%d\n", cube[0]);
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &d);
		if (move(d))
			change();
	}
	return 0;
}