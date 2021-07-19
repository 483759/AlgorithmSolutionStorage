#include <cstdio>
int N, M, dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
char map[101][101];
bool visit[101][101];
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf(" %c", &map[0][i]);
		if (map[0][i] == '*')visit[0][i] = true;
		for (int j = 1; j < M; j++) {
			scanf("%c", &map[j][i]);
			if (map[j][i] == '*')visit[j][i] = true;
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			bool check = true;
			for (int k = 0; k < 4; k++)
				if (map[j + dy[k]][i + dx[k]] != '*')check = false;
		}
	return 0;
}