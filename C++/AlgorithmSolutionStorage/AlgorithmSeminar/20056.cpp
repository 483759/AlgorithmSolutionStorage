#include <cstdio>
#include <queue>
using namespace std;

typedef struct { int m, s, d; }fireball;
typedef struct { int x, y; }point;
queue<fireball> map[51][51], temp[51][51];
int n, m, k;
int dx[] = { 0,1,1,1,0,-1,-1,-1 }, dy[] = { -1,-1,0,1,1,1,0,-1 };

void printMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", map[i][j].size());
		printf("\n");
	}
	printf("\n");
}

void printTemp() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", temp[i][j].size());
		printf("\n");
	}
	printf("\n");
}

void moveFireBall(point p) {
	while (!map[p.y][p.x].empty()) {
		fireball fb = map[p.y][p.x].front(); map[p.y][p.x].pop();

		int nx = p.x + dx[fb.d] * fb.s;
		int ny = p.y + dy[fb.d] * fb.s;

		nx = (nx + n * 1001) % n;
		ny = (ny + n * 1001) % n;

		temp[ny][nx].push(fb);
	}
}

void crashFireBall(point p) {
	queue<fireball>& ret = temp[p.y][p.x];

	if (ret.size() >= 2) {
		int mSum = 0, sSum = 0, size=ret.size(), dir = ret.front().d % 2;
		int b = 0;

		while (!ret.empty()) {
			fireball fb = ret.front(); ret.pop();
			mSum += fb.m; sSum += fb.s;
			if (fb.d % 2 != dir)b = 1;
		}

		if (mSum < 5)return;
		mSum /= 5;
		sSum /= size;
		for(int i=0;i<8;i++)
			if(i%2==b)
				map[p.y][p.x].push({ mSum,sSum,i });

	}
	else {
		while (!ret.empty()) {
			map[p.y][p.x].push(ret.front());
			ret.pop();
		}
	}
}

int sumOfMass() {
	int sum = 0;
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++)
			while (!map[i][j].empty()) {
				sum += map[i][j].front().m; map[i][j].pop();
			}
	return sum;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0, R, C, M, D, S; i < m; i++) {
		scanf("%d%d%d%d%d", &R, &C, &M, &S, &D);
		fireball fb = { M,S,D };
		map[R - 1][C - 1].push(fb);
	}

	while (k--) {
		//printMap();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (!map[i][j].empty())moveFireBall({ j,i });

		//printTemp();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (!temp[i][j].empty())crashFireBall({ j,i });
		
	}
	printMap();
	printf("%d", sumOfMass());
	return 0;
}

//#include <cstdio>
//#include <vector>
//using namespace std;
//typedef struct { int r, c; }point;
//typedef struct { int w, s, d; }cosm;
//vector<cosm> map[51][51];
//vector<cosm> tmp[51][51];
//int n, m, k,ans, dc[] = { 0,1,1,1,0,-1,-1,-1 }, dr[] = { -1,-1,0,1,1,1,0,-1 };
//point move(point cur, cosm c) {
//	point next;
//	next.r = cur.r + dr[c.d] * c.s;
//	next.c = cur.c + dc[c.d] * c.s;
//	next.r = (next.r + n*1001) % n;
//	next.c = (next.c + n*1001) % n;
//	return next;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d", &n, &m, &k);
//
//	for (int i = 0; i < m; i++) {
//		int r, c, w, s, d;
//		scanf("%d%d%d%d%d", &r, &c, &w, &s, &d);
//		map[r-1][c-1].push_back({ w,s,d });
//	}
//	while (k--) {
//		for(int i=0;i<n;i++)
//			for(int j=0;j<n;j++)
//				if (!map[i][j].empty()) {
//					for (auto x : map[i][j]) {
//						point next = move({ i,j }, x);
//						tmp[next.r][next.c].push_back(x);
//					}
//					map[i][j].clear();
//				}
//		for(int i=0;i<n;i++)
//			for(int j=0;j<n;j++)
//				if (!tmp[i][j].empty()) {
//					if (tmp[i][j].size() == 1) {
//						map[i][j].push_back(tmp[i][j][0]);
//						tmp[i][j].pop_back();
//						continue;
//					}
//					int num=tmp[i][j].size(),weight = 0, speed = 0, dir= tmp[i][j][0].d % 2, nd=0;
//					for (auto x : tmp[i][j]) {
//						weight += x.w; speed += x.s;
//						if ((x.d % 2) != dir)nd = 1;
//					}
//					tmp[i][j].clear();
//					if (weight < 5)continue;
//					weight = weight / 5; speed = speed / num;
//
//					for(int l=0;l<8;l++)
//						if ((l % 2) == nd) {
//							map[i][j].push_back({ weight,speed,l });
//						}
//				}
//	}
//	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
//		while (!map[i][j].empty()) {
//			ans += map[i][j].back().w;
//			map[i][j].pop_back();
//		}
//	}
//	printf("%d", ans);
//	return 0;
//}

//#include <cstdio>
//#include <vector>
//using namespace std;
//typedef struct { int r, c; }point;
//typedef struct { int k; point p; }block;
//block board[2][10][4];
//
//int n, t, x, y, ans, sum;
//
//void print() {
//	for (int k = 0; k < 2; k++) {
//		for (int i = 0; i < 10; i++) {
//			for (int j = 0; j < 4; j++)
//				printf("%d", board[k][i][j].k);
//			printf("\n");
//		}
//		printf("\n");
//	}
//}
//
//bool safe(int c, vector<point> p) {
//	for (auto x : p)
//		if (x.r >= 10 || board[c][x.r][x.c].k)	//비어있지 않다면
//			return false;
//	return true;
//}
//void blockMove(int c, point cur, block b) {
//	vector<point> v, next;
//	v.push_back(cur);
//	if (b.k > 1)v.push_back(b.p);
//
//	for (auto x : v) {
//		board[c][x.r][x.c] = { 0,{0,0} };
//		next.push_back({ x.r + 1,x.c });
//	}
//
//	while (safe(c, next)) {
//		v = next;
//		for (int i = 0; i < next.size(); i++)
//			next[i].r++;
//	}
//
//	if (b.k == 1) {
//		board[c][v[0].r][v[0].c] = { 1,v[0] };
//		return;
//	}
//
//	for (int i = 0; i < 2; i++) {
//		board[c][v[i].r][v[i].c] = { b.k,v[!i] };
//	}
//}
//
//int fullRow(int c) {
//	for (int r = 9; r >= 6; r--) {
//		bool b = true;
//		for (int i = 0; i < 4; i++)
//			if (!board[c][r][i].k)b = 0;
//		if (b) return r;
//	}
//	for (int r = 5; r >= 4; r--) {
//		for (int i = 0; i < 4; i++)
//			if (board[c][r][i].k)return r;
//	}
//	return -1;
//}
//void rowPop(int cl, int row) {
//	for (int i = 0; i < 4; i++) {
//		int kin = board[cl][row][i].k;
//		if (!kin)continue;
//
//		if (kin == 3) {
//			point next = board[cl][row][i].p;
//			board[cl][next.r][next.c] = { 1,next };
//		}
//		board[cl][row][i] = { 0,{0,0} };
//	}
//	int f = fullRow(cl);
//	if (f < 6)
//		for (int r = row - 1; r > 3; r--) {
//			for (int i = 0; i < 4; i++)
//				if (board[cl][r][i].k)
//					blockMove(cl, { r,i }, board[cl][r][i]);
//		}
//}
//int main() {
//	scanf("%d", &n);
//	while (n--) {
//		scanf("%d%d%d", &t, &y, &x);
//		//printf("%d %d %d\n", t, y, x);
//
//		for (int B = 0; B < 2; B++) {
//			if (t == 1) {
//				board[B][y][x] = { 1,{y,x} };
//			}
//			else if (t == 2) {
//				board[B][y][x] = { 2,{y,x + 1} };
//				board[B][y][x + 1] = { 2,{y,x} };
//			}
//			else {
//				board[B][y][x] = { 3,{y + 1,x} };
//				board[B][y + 1][x] = { 3,{y,x} };
//			}
//
//			blockMove(B, { y,x }, board[B][y][x]);
//
//			int state;
//			while ((state = fullRow(B)) != -1) {
//				if (state > 5) {
//					rowPop(B, state);
//					ans++;
//				}
//				else
//					rowPop(B, 9);
//			}
//
//			int temp = y; y = x; x = 3 - temp;
//			if (t == 2)t = 3;
//			else if (t == 3) { t = 2; x--; };
//		}
//		//print();
//	}
//	for (int k = 0; k < 2; k++)
//		for (int i = 4; i < 10; i++)
//			for (int j = 0; j < 4; j++)
//				if (board[k][i][j].k)sum++;
//	printf("%d\n%d", ans, sum);
//	return 0;
//}
