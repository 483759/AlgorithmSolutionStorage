#include <cstdio>
int n, m, k;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	return 0;
}
//#include <iostream>
//#include <deque>
//using namespace std;
//
//typedef struct { int x, y; }point;
//int n, k, l, dir, ans, map[105][105], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//deque<pair<int, int>> op;
//deque<point> snake;
//void print() {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			printf("%3d", map[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	cin >> n >> k;
//	for (int i = 0; i <= n + 1; i++) {
//		map[0][i] = map[i][0] = map[n + 1][i] = map[i][n + 1] = -1;    //벽 처리
//	}
//	for (int i = 0, r, c; i < k; i++) {
//		cin >> r >> c;
//		map[r][c] = 2;	//사과
//	}
//	map[1][1] = 1;	//뱀
//
//	cin >> l;
//	for (int i = 0, x; i < l; i++) {
//		char c;
//		cin >> x >> c;
//		if (c == 'L')op.push_back(make_pair(x, -1));
//		else op.push_back(make_pair(x, 1));
//	}
//	snake.push_back({ 1,1 });
//
//	while (!snake.empty()) {
//		ans++;
//		point cur = snake.front();
//		point next = { cur.x + dx[dir],cur.y + dy[dir] };
//
//		if ((map[next.y][next.x] + 2) % 2) {
//			printf("%d", ans);
//			break;
//		}
//
//		if (!map[next.y][next.x]) {
//			map[snake.back().y][snake.back().x] = 0;
//			snake.pop_back();
//		}
//
//		map[next.y][next.x] = 1;
//		snake.push_front(next);
//
//		if (!op.empty() && op.front().first == ans) {
//			dir = (dir + op.front().second + 4) % 4;
//			op.pop_front();
//		}
//		print();
//	}
//	return 0;
//}

//#include <cstdio>
//#include <queue>
//using namespace std;
//typedef struct { int x, y; }point;
//queue<point> q;
//int l,n,k,dir = 0, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//int map[105][105],time[10005],ans;
//void print() {
//	for (int i = 0; i <= n+1; i++) {
//		for (int j = 0; j <= n+1; j++)
//			printf("%3d", map[i][j]);
//		printf("\n");
//	}
//}
//int main() {
//	scanf("%d", &n);
//	for(int i=0;i<=n;i++)
//		map[0][i] = map[n+1][i] = map[i][0] = map[i][n+1] = -1;
//	scanf("%d", &k);
//	while (k--) { int r, c; scanf("%d%d", &r, &c); map[r][c] = 2; }
//	scanf("%d", &l);
//	while (l--) {
//		int x; char c;
//		scanf("%d", &x);
//		scanf(" %c",&c);
//		if (c == 'L')time[x] = -1;
//		else time[x] = 1;
//	}q.push({ 1,1 });
//	while (1) {
//		if (time[ans] == 1)dir = (dir + 1) % 4;
//		else if (time[ans] == -1)dir = (dir + 3) % 4; ans++;
//		int nx = q.back().x + dx[dir], ny = q.back().y + dy[dir];
//		if (map[ny][nx] == 1 || map[ny][nx] == -1)break;
//		if (map[ny][nx] == 2) {
//			map[ny][nx] = 1;
//			q.push({ nx,ny });
//		}
//		else {
//			map[ny][nx] = 1;
//			q.push({ nx,ny });
//			map[q.front().y][q.front().x] = 0;
//			q.pop();
//		}
//	}
//	printf("%d", ans);
//	return 0;
//}
//#include <cstdio>
//#include <queue>
//#include <utility>
//using namespace std;
//struct point { int r, c; };
//int n, k, l, t, sd, idx;
//int map[101][101] = { 1 }, dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
//queue<point> snake;
//pair<int, int> p[101];
//bool safe(int r, int c) {
//	return r > 0 && r <= n && c > 0 && c <= n;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d", &n, &k);
//	for (int i = 0, r, c; i < k; i++) {
//		scanf("%d %d", &r, &c);
//		map[r][c] = 2;
//	}
//	scanf("%d", &l);
//	for (int i = 0; i < l; i++) {
//		char c;
//		scanf(" %d %c", &p[i].first, &c);
//		if (c == 'D')p[i].second = 1;
//		else p[i].second = -1;
//	}
//	map[1][1] = 1;
//	snake.push({ 1, 1 });
//	while (safe(snake.back().r, snake.back().c)) {
//		t++;
//		int sr = snake.back().r, sc = snake.back().c;
//
//		//방향전환을 해야한다면
//		if (t == p[idx].first + 1) {
//			sd = (sd + p[idx++].second + 4) % 4;
//		}
//
//		sr += dy[sd]; sc += dx[sd];
//
//		//이동할 칸에 사과가 잇다면 사과를 머리로 대체
//		if (map[sr][sc] == 2) {
//			map[sr][sc] = 1;
//			snake.push({ sr, sc });
//		}
//		else if (map[sr][sc] == 1)break;
//		//이동할 칸에 사과가 없다면 꼬리를 없앤다
//		else {
//			map[sr][sc] = 1;	//머리를 옮긴다
//			snake.push({ sr, sc });
//			map[snake.front().r][snake.front().c] = 0;
//			snake.pop();
//		}
//		//sr += dy[sd]; sc += dx[sd];	//다음 위치를 계산
//
//		//for (int i = 1; i <= n; i++) {
//		//	for (int j = 1; j <= n; j++)
//		//		printf("%d ", map[i][j]);
//		//	printf("\n");
//		//}
//		//printf("\n");
//
//	}
//	printf("%d", t);
//	return 0;
//}