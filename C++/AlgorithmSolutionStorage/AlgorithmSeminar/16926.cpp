#include <cstdio>
#include <cstring>
using namespace std;
typedef struct { int x, y; }point;
int N, M, r, dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int arr[305][305], temp[305][305];
bool safe(point cur,point s, point f) {
	return cur.x >= s.x && cur.x <= f.x && cur.y >= s.y && cur.y <= f.y;
}
void rotate(point s,point f) {
	if ((f.x - s.x <= 0) || (f.y - s.y <= 0))return;

	int d=0;
	int cx = s.x, cy = s.y;
	int nx = s.x + dx[d], ny = s.y + dy[d];
	while (!(nx == s.x && ny == s.y)) {
		temp[ny][nx] = arr[cy][cx];
		cx += dx[d]; cy += dy[d];
		
		if (!safe({ cx + dx[d],cy + dy[d] }, s, f))d++;
		nx = cx + dx[d]; ny = cy + dy[d];
	}
	temp[ny][nx] = arr[cy][cx];

	rotate({ s.x + 1,s.y + 1 }, { f.x - 1,f.y - 1 });

}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &N, &M, &r);
	for (int i = 0; i < N; i++)for (int j = 0; j < M; j++)scanf("%d", &arr[i][j]);
	while (r--) {
		rotate({ 0,0 }, { M - 1,N - 1 });
		memcpy(arr, temp, sizeof(temp));
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	return 0;
}