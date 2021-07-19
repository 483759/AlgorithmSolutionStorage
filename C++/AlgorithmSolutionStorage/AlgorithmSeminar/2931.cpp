#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int r, c, dx[] = { 0,1,0,-1,0 }, dy[] = { 0,0,1,0,-1 };
//북 동 남 서
int tarr[7][5] = {
	{0,0,2,0,4},{0,1,0,3,0},{0,1,2,3,4},{0,0,0,2,1},
{0,0,1,4,0},{0,4,3,0,0},{0,2,0,0,3}
};
bool ans[4],visit[26][26];
char arr[26][26], block[] = {'|','-','+','1','2','3','4'};
typedef struct { int x, y; }point;
point blank={-1,1}, s, f;
bool safe(int x, int y) {
	return x >= 0 && x < c && y >= 0 && y < r;
}
int blocknum(char c) {
	for (int i = 0; i < 7; i++)
		if (block[i] == c)return i;
	return -1;
}
bool correct() {
	for(int i=0;i<r;i++)
		for (int j = 0; j < c; j++) {
			switch (arr[i][j]) {
			case '.':
			case 'M':
			case 'Z':
				break;
			default:
				if (!visit[i][j])return 0;
				break;
			}
		}
	return 1;
}
point dfs() {
	point cur = s;
	int dir=0;
	for (int i = 1; i < 5; i++) {
		int nx = cur.x + dx[i], ny = cur.y + dy[i];
		if (!safe(nx, ny))continue;
		char next = arr[ny][nx];
		for (int j = 0; j < 7; j++)
			if (block[j] == next&&tarr[blocknum(next)][i]) { 
				cur = { nx,ny };
				dir = i; 
			}
		if (dir)break;
	}	//진행방향 정하기
	while (!(cur.x == f.x && cur.y == f.y)) {
		visit[cur.y][cur.x] = 1;
		int b = blocknum(arr[cur.y][cur.x]);
		int nd = tarr[b][dir];
		if (!nd)return cur;
		cur.x += dx[nd]; cur.y += dy[nd]; dir = nd;
		if (blocknum(arr[cur.y][cur.x])==-1)return cur;
	}
		
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d ", &r, &c);
	for (int i = 0; i < r; i++)
		scanf("%s", arr[i]);
	for (int i = 0; i < r; i++) 
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'M') { s = { j,i }; continue; }
			if (arr[i][j] == 'Z') { f = { j, i }; continue; }
		}

	blank=dfs();

	for (int i = 0; i < 7; i++) {
		memset(visit, 0, sizeof(visit));
		arr[blank.y][blank.x] = block[i];
		point p=dfs();
		if (p.x == f.x && p.y == f.y&&correct()) {
			printf("%d %d %c", blank.y+1, blank.x+1, block[i]);
			return 0;
		}
	}
	return 0;
}