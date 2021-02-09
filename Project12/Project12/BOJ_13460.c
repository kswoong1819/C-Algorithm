#include <stdio.h>
#include <malloc.h>

typedef struct {
	int redR, redC;
	int blueR, blueC;
	int cnt;
}point;

int n, m;
int front = 0, rear = 0;
char matrix[11][11];
int visited[11][11][11][11] = { 0, };
point balls[41];

int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

void init() {
	balls[0].cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (matrix[i][j] == 'R') {
				balls[0].redR = i;
				balls[0].redC = j;
			}
			else if (matrix[i][j] == 'B') {
				balls[0].blueR = i;
				balls[0].blueC = j;
			}
		}
	}
	visited[balls[0].redR][balls[0].redC][balls[0].blueR][balls[0].blueC] = 1;
	return;
}

int* move(int nr, int nc, int y, int x) {
	int *tmp = (int*)malloc(sizeof(int) * 3);
	while (1) {
		nr += y;
		nc += x;
		tmp[2]++;
		if (matrix[nr][nc] == '#' || matrix[nr][nc] == 'O') {
			tmp[0] = nr - y;
			tmp[1] = nc - x;
			return tmp;
		}
	}
}

int bfs() {
	int* nums;
	point n_ball, use;

	while (front >= rear)
	{
		use = balls[rear++];
		int depth = ++use.cnt;
		if (depth > 10) {
			return -1;
		}
		for (int i = 0; i < 4; i++) {
			n_ball = use;
			nums = move(n_ball.redR, n_ball.redC, dr[i], dc[i]);
			int Rr = nums[0], Rc = nums[1], Rcnt = nums[2];
			nums = move(n_ball.blueR, n_ball.blueC, dr[i], dc[i]);
			int Br = nums[0], Bc = nums[1], Bcnt = nums[2];

			if (matrix[Br + dr[i]][Bc + dc[i]] == 'O') {
				continue;
			}
			if (matrix[Rr + dr[i]][Rc + dc[i]] == 'O') {
				return depth;
			}

			if (Rr == Br && Rc == Bc) {
				if (Rcnt > Bcnt) {
					Rr -= dr[i];
					Rc -= dc[i];
				}
				else {
					Br -= dr[i];
					Bc -= dc[i];
				}
			}


			if (!visited[Rr][Rc][Br][Bc]) {
				visited[Rr][Rc][Br][Bc] = 1;
				n_ball.redR = Rr;
				n_ball.redC = Rc;
				n_ball.blueR = Br;
				n_ball.blueC = Bc;
				n_ball.cnt = depth;
				balls[++front] = n_ball;
			}

		}
	}
	return -1;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", matrix[i]);
	}

	init(matrix);
	printf("%d\n", bfs(matrix));

	return 0;
}
