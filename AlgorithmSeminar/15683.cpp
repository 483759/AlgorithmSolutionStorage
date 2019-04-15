#include <cstdio>
#include <cstring>
struct cctv { int r, c, w; };
int n, m, num, ans, rt[] = { 4, 2, 4, 4,1 }, map[9][9], dx[] = { 0, 1, 0, -1 }, dy[] = { -1, 0, 1, 0 };
bool visit[9][9], kind[6];
cctv ct[8];
bool safe(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m && map[r][c] != 6;
}
void func(int r, int c, int d) {
	while (safe(r, c)) {
		visit[r][c] = 1;
		r += dy[d]; c += dx[d];
	}
}
void watch(cctv c, int wc) {
	switch (c.w) {
	case 1:
		func(c.r, c.c, wc);
		break;
	case 2:
		func(c.r, c.c, wc);
		func(c.r, c.c, (wc + 2) % 4);
		break;
	case 3:
		func(c.r, c.c, wc);
		func(c.r, c.c, (wc + 1) % 4);
		break;
	case 4:
		func(c.r, c.c, wc);
		func(c.r, c.c, (wc + 1) % 4);
		func(c.r, c.c, (wc + 2) % 4);
		break;
	case 5:
		func(c.r, c.c, 0);
		func(c.r, c.c, 1);
		func(c.r, c.c, 2);
		func(c.r, c.c, 3);
		break;
	default:
		break;
	}
}
void repeat(int wh, int dep) {
	if (dep == num)return;
	for (int k = 0; k < rt[wh - 1]; k++) {
		watch(ct[dep], k);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visit[i][j] && map[i][j] != 6)ans++;
				printf("%d ", visit[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		repeat(ct[dep + 1].w, dep + 1);
		memset(visit, false, sizeof(visit));
	}
	return;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] % 6) {
				ct[num++] = { i, j, map[i][j] };
				kind[map[i][j]] = 1;
			}
		}

	repeat(ct[0].w, 0);
	//printf("%d \n", ans);

	//for (int i = 0; i < num; i++) {
	//	for (int a = 0; a < 4; a++) {
	//		for (int b = 0; b < 2; b++) {
	//			for (int c = 0; c < 4; c++) {
	//				for (int d = 0; d < 4; d++) {
	//					memset(visit, false, sizeof(visit));
	//					ans = 0;
	//					watch(ct[i], a, b, c, d);
	//					for (int i = 0; i < n; i++) {
	//						for (int j = 0; j < m; j++) {
	//							if (!visit[i][j] && map[i][j] != 6)ans++;
	//							printf("%d ", visit[i][j]);
	//						}
	//						printf("\n");
	//					}
	//					printf("%d \n", ans);
	//					if (!kind[4])break;
	//				}
	//				if (!kind[3])break;
	//			}
	//			if (!kind[2])break;
	//		}
	//		if (!kind[1])break;
	//	}
	//}
	return 0;
}