#include <iostream>
using namespace std;

typedef struct { int x, y; }point;
int n, m, ans = 11, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
int order[11];
string map[11];
point hole;

bool isCrash(point p, point o)
{
	return p.x == o.x && p.y == o.y;
}

bool rollOrder(point red, point blue, int dir)
{
	switch (dir) {
	case 0:
		return red.x > blue.x;
	case 1:
		return red.y > blue.y;
	case 2:
		return red.x < blue.x;
	case 3:
		return red.y < blue.y;
	}
}

point roll(point p, point o, int dir)
{
	while (!isCrash(p, hole) && !isCrash(p, o) && map[p.y][p.x] != '#')
	{
		if (isCrash(p, hole))return p;
		p.x += dx[dir];
		p.y += dy[dir];
	}
	if (!isCrash(p, hole)) {
		p.x -= dx[dir];
		p.y -= dy[dir];
	}
	return p;
}

pair<point, point> move(point red, point blue, int dir)
{
	if (rollOrder(red, blue, dir))
	{
		red = roll(red, blue, dir);
		blue = roll(blue, red, dir);
	}
	else
	{
		blue = roll(blue, red, dir);
		red = roll(red, blue, dir);
	}
	return make_pair(red, blue);
}

void simulation(int dep, int pre, point red, point blue)
{
	if (dep > 10)return;

	for (int i = 0; i < 4; i++)
	{
		if (i == pre || (i + 2) % 4 == pre)continue;
		order[dep] = i;

		pair<point, point> next = move(red, blue, i);
		if (!isCrash(next.second, hole)) {
			if (isCrash(next.first, hole))ans = dep < ans ? dep : ans;

			simulation(dep + 1, i, next.first, next.second);
		}
	}
}

int main()
{
	point red, blue;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'O')hole = { j,i };
			else if (map[i][j] == 'R')red = { j,i };
			else if (map[i][j] == 'B')blue = { j,i };
		}
	}
	simulation(1, -1, red, blue);
	cout << (ans > 10 ? -1 : ans);
	return 0;
}



//#include <cstdio>
//int n, map[101][101];
//long long dp[101][101];
//bool safe(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }
//int main() {
//	scanf("%d", &n); dp[0][0] = 1;
//	for(int i=0;i<n;i++)
//		for (int j = 0; j < n; j++) {
//			scanf("%d", &map[i][j]);
//			int k = map[i][j];
//			if (!k)continue;
//			if (safe(j + k, i))
//				dp[i][j + k] += dp[i][j];
//			if (safe(j, i + k))
//				dp[i + k][j] += dp[i][j];			
//		}
//	printf("%lld", dp[n - 1][n - 1]);
//	return 0;
//}
//#include <cstdio>
//typedef struct { int x, y; }point;
//int ans = 11, n, m,dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//char s[13][13];
//point red, blue;
//bool cmp(int dir) {
//	switch (dir) {
//	case 0:
//		return red.x > blue.x;
//		break;
//	case 1:
//		return red.y > blue.y;
//		break;
//	case 2:
//		return red.x < blue.x;
//		break;
//	case 3:
//		return red.y < blue.y;
//		break;
//	}
//}
//point move(bool color, int dir) {
//	point cur; int nx, ny;
//	if (color)cur = red; else cur = blue;
//
//	while (1) {
//		nx = cur.x + dx[dir], ny = cur.y + dy[dir];
//		if (nx < 0 || nx >= m || ny<0 || ny>n)break;
//		if (s[ny][nx] == '#')break;
//		else if ((color && nx == blue.x && ny == blue.y)
//			|| (!color && nx == red.x && ny == red.y))break;
//		if (s[ny][nx] == 'O')return{ 0,0 };
//		cur = { nx,ny };
//	}
//	return cur;
//}
//void func(int dep) {
//	if (dep > 10 || dep >= ans)return;
//	point pr = red, pb = blue;
//	for (int i = 0; i < 4; i++) {
//		bool w = cmp(i);
//
//		if (w) {
//			red = move(1, i);
//			blue = move(0, i);
//		}
//		else {
//			blue = move(0, i);
//			red = move(1, i);
//		}
//
//		if (s[blue.y][blue.x] != '#' && s[red.y][red.x] == '#') {
//			if (dep < ans)ans = dep;
//		}
//		else if (s[blue.y][blue.x] == '#');
//		else if (red.x == pr.x && red.y == pr.y && blue.x == pb.x && blue.y == pb.y);
//		else {
//			func(dep + 1);
//		}
//
//		red = pr; blue = pb;
//	}
//}//구슬이 구멍에 들어갔을 때 빼내는 처리 안 함, if문에서 파란구슬 빠졌을 때 빼먹음4
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d ", &n, &m);
//	for (int i = 0; i < n; i++)
//		scanf("%s", &s[i]);
//	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
//		switch (s[i][j]) {
//		case 'R':
//			red = { j,i }; break;
//		case 'B':
//			blue = { j,i }; break;
//		default: break;
//		}
//	}
//	func(1);
//	printf("%d", ans == 11 ? -1 : ans);
//	return 0;
//}

//#include <cstdio>
//#include <queue>
//#define pii pair<int,int>
//#define x first
//#define y second
//using namespace std;
//int n, m, ans = 987654321, dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//char s[12][12];
//typedef struct {
//	int rx, ry;
//	int bx, by;
//}point;
//typedef struct {
//	point p;
//	int dep, dir;
//}ball;
//queue<ball> q;
//point move(point a, int d) {
//	pii red = { a.rx,a.ry }, blue = { a.bx,a.by };
//	bool check = false;
//	if ((d == 0 && (red.x > blue.x))
//		|| (d == 1 && (red.y > blue.y))
//		|| (d == 2 && (red.x < blue.x))
//		|| (d == 3 && (red.y < blue.y))
//		)check = 1;
//
//	while (s[red.y + dy[d]][red.x + dx[d]] == '.' && check) {	//빨강먼저
//		red.x += dx[d];
//		red.y += dy[d];
//	}
//	while (s[blue.y + dy[d]][blue.x + dx[d]] == '.'
//		&& !(blue.y+dy[d]==red.y && blue.x+dx[d]==red.x)) {
//		blue.x += dx[d];
//		blue.y += dy[d];
//	}
//	while (s[red.y + dy[d]][red.x + dx[d]] == '.' && !check
//		&& !(red.y + dy[d] == blue.y && red.x + dx[d] == blue.x)) {	//파랑먼저
//		red.x += dx[d];
//		red.y += dy[d];
//	}
//
//	if (s[blue.y + dy[d]][blue.x + dx[d]] == 'O')return a;
//	else if (s[red.y + dy[d]][red.x + dx[d]] == 'O') {
//		if (blue.y + dy[d] == red.y && blue.x + dx[d] == red.x)	//둘다 구슬에 빠지면
//			return a;
//		return { 0,0,0,0 };
//	}
//	else
//		return a = { red.x,red.y,blue.x,blue.y };
//}
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	point fst = { 0,0,0,0 };
//	scanf("%d%d ", &n, &m);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			scanf("%c", &s[i][j]);
//			if (s[i][j] == 'R') { fst.rx = j; fst.ry = i; s[i][j] = '.'; }
//			if (s[i][j] == 'B') { fst.bx = j; fst.by = i; s[i][j] = '.'; }
//		}
//		scanf(" ");
//	}
//	//point k = move( fst,2 );
//	//k = move(k, 1);
//	//k = move(k, 2);
//	//k = move(k, 1);
//	//k = move(k, 0);
//	//k = move(k, 1);
//	//k = move(k, 0);
//	//k = move(k, 3);
//
//	q.push({ fst,0,0 });
//	while (!q.empty()) {
//		point cur = q.front().p, next;
//		int dep = q.front().dep+1, dir=q.front().dir;
//		q.pop();
//		if (dep > ans||dep>10)continue;
//		for (int i = 0; i < 4; i++) {
//			if (dep>1&&(dir == i || (dir + 2) % 4 == i))continue;
//			next = move(cur, i);
//			if (!next.rx && !next.ry && !next.bx && !next.by)
//				ans = dep < ans ? dep : ans;
//			else if ((next.rx == cur.rx)
//				&& (next.ry == cur.ry)
//				&& (next.bx == cur.bx)
//				&& (next.by == cur.by))continue;
//			else {
//				q.push({ next,dep,i });
//			}
//		}
//	}
//
//	printf("%d", ans== 987654321?-1:ans);
//	return 0;
//}

//while (1) {
//	char& red = s[r.y + dy[d]*dr][r.x + dx[d]*dr],
//		blue= s[b.y + dy[d]*db][b.x + dx[d]*db];
//	if (red == '#' && blue == '#')	
//		//둘다 벽이면
//		break;

//	dr++;
//	if (red == '#')
//		dr--;
//	else if (red == 'O') {
//		for (; blue != '.'; db++);
//		if (blue == '#') {	//성공

//		}
//		else {	//실패(Blue가 같이 빠진 경우)
//			break;
//		}
//	}
//	if (s[b.y + dy[db + 1]][b.x + dx[db + 1]] != '#')
//		db++;
//}