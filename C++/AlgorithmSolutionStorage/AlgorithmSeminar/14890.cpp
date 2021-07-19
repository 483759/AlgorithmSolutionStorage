#include <cstdio>
bool visit[101];
int n, l, map[101][101], m[101][101],ans;
bool safe(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}
void rotate() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			m[j][n - 1 - i] = map[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = m[i][j];
}
void func() {
	for (int i = 0; i < n; i++) {
		bool check = 1;
		for (int j = 0; j < n; j++)visit[j] = 0;
		for (int j = 0, k, cur; j < n - 1; j++) {
			if (map[i][j] > map[i][j + 1]) {
				for (int k = 0; k < l; k++)
					if (!safe(j + 1 + k, i)
						|| visit[j + 1 + k]
						|| map[i][j] - map[i][j + 1 + k] != 1)
						check = 0;
				if (check)
					for (int k = 0; k < l; k++)
						visit[j + 1 + k] = 1;
			}
			else if (map[i][j] < map[i][j + 1]) {
				for (int k = 0; k < l; k++)
					if (!safe(j - k, i)
						|| visit[j - k]
						|| map[i][j + 1] - map[i][j - k] != 1)
						check = 0;
				if (check)
					for (int k = 0; k < l; k++)
						visit[j - k] = 1;
			}

		}
		if (check)ans++;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &l);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	func();
	rotate();
	func();
	printf("%d", ans);
	return 0;
}
//if (map[i][j + 1] > map[i][j]) {
//	//다르다면
//	for (k = 0; k < l; k++) {
//		cur = j + 1 - l + k;
//		if (!safe(cur, i) ||
//			map[i][cur] != map[i][j + 1] - 1
//			|| visit[i][cur]) {
//			check = 0;
//			break;
//		}
//	}
//	if (check)
//		for (k = 0; k < l; k++)
//			visit[i][j + 1 - l + k] = 1;
//	else
//		break;
//}

			//if (safe(j + l, i) && map[i][j + l] != map[i][j]) {
			//	for (k = 0; k < l; k++)
			//		if (map[i][j + l] - map[i][j + k] != 1)
			//			check = 0;
			//	if (k == l)j += (l - 1);
			//}