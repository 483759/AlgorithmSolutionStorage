#include <cstdio>
int num[7], map[21][21], dx[] = { 1, -1, 0, 0 }, dy[] = {0, 0, -1, 1};
int w = 4, s = 5, on = 1,n, m, x, y, k, op;
void func(int& n1, int& n2) {
	int temp = n1;
	n1 = 7 - n2;
	n2 = temp;
}
bool safe(int x, int y) {
	return x >= 0 && x < m && y >= 0 && y < n;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d%d%d", &n, &m, &x, &y, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < k; i++) {
		int temp;
		scanf("%d", &op);

		if (!safe(x + dx[op-1], y + dy[op-1]))
			continue;
		x += dx[op - 1]; y += dy[op - 1];	//좌표 이동
		switch (op) {	//주사위 굴리기
		case 1:	//동쪽
			func(on, w);
			break;
		case 2:	//서쪽
			func(w, on);
			break;
		case 3:	//북쪽
			func(on, s);
			break;
		case 4:	//남쪽
			func(s, on);
			break;
		}
		if (!map[y][x]) {	//이동한 칸이 비어있으면
			map[y][x]=num[on];
		}
		else {	//비어있지 않으면
			num[on] = map[y][x];
			map[y][x] = 0;
		}
		printf("%d\n", num[7 - on]);
		/*printf(" x: %d y: %d\n", x, y);
		for (int j = 1; j < 7; j++) printf("%d ", num[j]);
		printf("\n\n");*/
	}
	return 0;
}