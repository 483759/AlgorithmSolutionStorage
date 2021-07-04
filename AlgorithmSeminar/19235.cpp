#include <cstdio>
#include <vector>
using namespace std;
typedef struct { int r, c; }point;
typedef struct { int k; point p; }block;
block board[2][10][4];

int n, t, x, y, ans,sum;

void print() {
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 4; j++)
				printf("%d", board[k][i][j].k);
			printf("\n");
		}
		printf("\n");
	}
}

bool safe(int c, vector<point> p) {
	for (auto x : p)
		if (x.r >= 10 || board[c][x.r][x.c].k)	//비어있지 않다면
			return false;
	return true;
}
void blockMove(int c, point cur, block b) {
	vector<point> v, next;
	v.push_back(cur);
	if (b.k > 1)v.push_back(b.p);

	for (auto x : v) {
		board[c][x.r][x.c] = { 0,{0,0} };
		next.push_back({ x.r + 1,x.c });
	}

	while (safe(c, next)) {
		v = next;
		for (int i = 0; i < next.size(); i++)
			next[i].r++;
	}

	if (b.k == 1) {
		board[c][v[0].r][v[0].c] = { 1,v[0] };
		return;
	}

	for (int i = 0; i < 2; i++) {
		board[c][v[i].r][v[i].c] = { b.k,v[!i] };
	}
}

int fullRow(int c) {
	for (int r = 9; r >= 6; r--) {
		bool b = true;
		for (int i = 0; i < 4; i++)
			if (!board[c][r][i].k)b = 0;
		if(b) return r;
	}
	for (int r = 5; r >= 4; r--) {
		for (int i = 0; i < 4; i++)
			if (board[c][r][i].k)return r;
	}
	return -1;
}
void rowPop(int cl, int row) {
	for (int i = 0; i < 4; i++) {
		int kin = board[cl][row][i].k;
		if (!kin)continue;

		if (kin==3){
			point next = board[cl][row][i].p;
			board[cl][next.r][next.c] = { 1,next };
		}
		board[cl][row][i] = { 0,{0,0} };
	}
}
void blockDown(int cl) {
	for (int r = 8; r > 3; r--) {
		for (int i = 0; i < 4; i++)
			if (board[cl][r][i].k)
				blockMove(cl, { r,i }, board[cl][r][i]);
	}

}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d", &t, &y, &x);
		//printf("%d %d %d\n", t, y, x);

		for (int B = 0; B < 2; B++) {
			if (t == 1) {
				board[B][y][x] = { 1,{y,x} };
			}
			else if (t == 2) {
				board[B][y][x] = { 2,{y,x + 1} };
				board[B][y][x + 1] = { 2,{y,x} };
			}
			else {
				board[B][y][x] = { 3,{y + 1,x} };
				board[B][y + 1][x] = { 3,{y,x} };
			}

			blockMove(B, { y,x }, board[B][y][x]);

			int state;
			while ((state = fullRow(B)) > 5) {
				rowPop(B, state);
				ans++;
			}blockDown(B);
			while ((state = fullRow(B)) > 3) {
				rowPop(B, state);
			}blockDown(B);
			int temp = y; y = x; x = 3 - temp;
			if (t == 2)t = 3;
			else if (t == 3) { t = 2; x--; };
		}
		print();
	}
	for (int k = 0; k < 2; k++)
		for (int i = 4; i < 10; i++)
			for (int j = 0; j < 4; j++)
				if (board[k][i][j].k)sum++;
	printf("%d\n%d", ans, sum);
	return 0;
}