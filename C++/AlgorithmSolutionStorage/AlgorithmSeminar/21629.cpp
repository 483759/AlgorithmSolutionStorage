#include <cstdio>
#include <math.h>
#include <cstring>
#include <algorithm>
#define pii pair<int,int>
#define BLACK -1
#define RAINBOW 0
#define AIR -2
using namespace std;

typedef struct { int x, y; }point;
int n, m, board[21][21],ans;
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool visit[21][21];

bool safe(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

pii dfs(point cur,int color) {
	visit[cur.y][cur.x] = 1;
	pii score = make_pair(0, 0);
	if (board[cur.y][cur.x] == RAINBOW)score.second++;
	else if (board[cur.y][cur.x] == color)score.first++;

	for (int i = 0; i < 4; i++) {
		int nx = cur.x + dx[i];
		int ny = cur.y + dy[i];
		if (safe(nx,ny)&&!visit[ny][nx] && (board[ny][nx] == color || board[ny][nx] == RAINBOW)) {
			auto ret = dfs({ nx,ny }, color);
			score.first += ret.first;
			score.second += ret.second;
		}
	}
	return score;
}

void popBlock(point cur, int color) {
	board[cur.y][cur.x] = AIR;
	visit[cur.y][cur.x] = 1;
	
	for (int i = 0; i < 4; i++) {
		int nx = cur.x + dx[i];
		int ny = cur.y + dy[i];
		if (safe(nx, ny) && !visit[ny][nx] && (board[ny][nx] == color || board[ny][nx] == RAINBOW)) {
			popBlock({ nx,ny }, color);
		}
	}
}

void gravity() {
	for(int j=0;j<n;j++)
		for (int i = n - 1; i >= 0; i--) {
			if (board[i][j] < 0)continue;
			int cur=i,next=i+1;
			while (safe(j, next)&&board[next][j]==AIR) {
				board[next][j] = board[cur][j];
				board[cur][j] = AIR;
				cur++;
				next++;
			}
		}
}

void rotate() {
	int temp[21][21];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp[i][j] = board[j][n - 1 - i];
	memcpy(board, temp, sizeof(temp));
}

void print() {
	printf("-------------------\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (board[i][j] == RAINBOW)
				printf(" R ");
			else if (board[i][j] == BLACK)
				printf(" B ");
			else if (board[i][j] >0)
				printf("%2d ", board[i][j]);
			else printf("   ");
		printf("\n");
	}
	printf("--------------------\n");
	printf("\n");
}

bool game() {
	pii score=make_pair(0,0);
	point block = { -1,-1 };
	printf("current score: %d\n", ans);
	print();
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			if (board[i][j] <= 0)continue;
			point cur = { j,i };

			auto x = dfs(cur, board[i][j]);
			memset(visit, false, sizeof(visit));

			if (x.first + x.second < 2)continue;
			if ((x.first + x.second > score.first + score.second)
				||((x.first+x.second==score.first+score.second)&&(x.second>score.second))
				|| ((x.first + x.second == score.first + score.second) && (x.second == score.second)&&(i>block.y))
				|| ((x.first + x.second == score.first + score.second) && (x.second == score.second) && (i == block.y&&j>block.x))) {
				score = x;
				block = { j,i };
			}
		}
	memset(visit, false, sizeof(visit));
	if (block.x != -1) {
		ans += pow(score.first + score.second, 2);
		popBlock(block, board[block.y][block.x]);
		print();
		gravity();
		rotate();
		gravity();
		print();
		return true;
	}
	else return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &board[i][j]);
	while (game());
	printf("%d", ans);
	return 0;
}