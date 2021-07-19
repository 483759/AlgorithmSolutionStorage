#include <cstdio>
int tc,n,map[21][21],x;
void rotate() {
	int temp[21][21];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp[j][n - 1 - i] = map[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = temp[i][j];
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int T = 1; T <= tc; T++) {
		scanf("%d%d", &n, &x); int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &map[i][j]);

		for (int a = 0; a < 2; a++) {
			for (int i = 0; i < n; i++) {	//행검사
				bool check = true; bool road[21] = { 0 };
				for (int j = 0; j < n-1; j++) {
					if (map[i][j] == map[i][j + 1])continue;
					int sub = map[i][j] - map[i][j + 1];

					if (sub < -1 || sub>1||!check) { check = 0; break; }	//높이차2이상

					if (sub > 0) {	//내리막길
						for (int k = j + 1; k < j + 1 + x; k++) {
							if (k >= n || (map[i][j+1] != map[i][k])||road[k]) {	//높이가 다르거나 범위 벗어나면
								check = 0; break;
							}
							road[k] = 1;
						}
						if (check)j += x-1;
						else break;
					}
					else {
						for (int k = j; k > j - x; k--) {
							if (k < 0 || (map[i][j] != map[i][k]) || road[k]) {
								check = 0; break;
							}
							road[k] = 1;
						}
					}
				}
				if (check)ans++;
			}
			rotate();
		}
		printf("#%d %d\n", T, ans);

	}
	return 0;
}