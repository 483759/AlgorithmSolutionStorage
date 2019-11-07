#include <cstdio>
int n, w, h, count;
int save[13], map[13][16], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
bool safe(int r, int c) {
	return r >= 0 && r < h && c >= 0 && c < w;
}
void breakBrick(int r, int c) {
	int range = map[r][c], count = map[r][c] ? 1 : 0;
	map[r][c] = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < range; j++)
			if (safe(r + dy[i], c + dx[i]))
				breakBrick(r + dy[i] * j, c + dx[i] * j);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &w, &h);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)scanf("%d", &map[i][j]);
	for (int k = 0, temp; k < n; k++) {
		scanf("%d", &temp);
		for(int j=0;j<h;j++)
			if (map[j][temp - 1]) {
				breakBrick(j, temp - 1);
				break;
			}
		for (int i = 0; i < w; i++) {
			int idx = 0;
			for (int j = h - 1; j >= 0; j--) {
				if (map[j][i]) {
					save[idx++] = map[j][i];
					map[j][i] = 0;
				}
			}
			for (int j = h - 1, t = 0; t < idx; j--, t++)
				map[j][i] = save[t];
		}
	}
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (map[i][j]) count++;
	printf("%d\n", count);
		return 0;
}

//#include <cstdio>
//int n, w, h, count;
//int save[13], map[13][16], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
//bool safe(int r, int c) {
//	return r >= 0 && r < h && c >= 0 && c < w;
//}
//void breakBrick(int r, int c) {
//	int range = map[r][c], count = map[r][c] ? 1 : 0;
//	map[r][c] = 0;
//	for (int i = 0; i < 4; i++) {
//		for (int j = 1; j < range; j++)
//			if (safe(r + dy[i], c + dx[i]))
//				breakBrick(r + dy[i] * j, c + dx[i] * j);
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d", &n, &w, &h);
//	for (int i = 0; i < h; i++)
//		for (int j = 0; j < w; j++)scanf("%d", &map[i][j]);
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++)
//			printf("%d ", map[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//	for (int k = 0, temp; k < n; k++) {
//		scanf("%d", &temp);
//		for (int j = 0; j<h; j++)
//			if (map[j][temp - 1]) {
//				breakBrick(j, temp - 1);
//				break;
//			}
//		for (int i = 0; i < w; i++) {
//			int idx = 0;
//			for (int j = h - 1; j >= 0; j--) {
//				if (map[j][i]) {
//					save[idx++] = map[j][i];
//					map[j][i] = 0;
//				}
//			}
//			for (int j = h - 1, t = 0; t < idx; j--, t++)
//				map[j][i] = save[t];
//		}
//		for (int i = 0; i < h; i++) {
//			for (int j = 0; j < w; j++) {
//				if (map[i][j]) count++;
//				printf("%d ", map[i][j]);
//			}
//			printf("\n");
//		}printf("\n");
//	}
//
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++) {
//			if (map[i][j]) count++;
//			printf("%d ", map[i][j]);
//		}
//		printf("\n");
//	}
//	printf("%d\n", count);
//
//	return 0;
//}