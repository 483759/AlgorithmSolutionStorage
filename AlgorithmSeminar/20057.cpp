#include <cstdio>
#include <vector>
using namespace std;

typedef struct { int x, y; }point;
typedef struct { int x, y, d; }storm;
int ratio[4][5][5] = {
	{0,0,2,0,0,0,10,7,1,0,5,-1,0,0,0,0,10,7,1,0,0,0,2,0,0},
	{0,0,0,0,0,0,1,0,1,0,2,7,0,7,2,0,10,-1,10,0,0,0,5,0,0},
	{0,0,2,0,0,0,1,7,10,0,0,0,0,-1,5,0,1,7,10,0,0,0,2,0,0},
	{0,0,5,0,0,0,10,-1,10,0,2,7,0,7,2,0,1,0,1,0}
};
point delta[4] = { {-3,-2},{-2,-1},{-1,-2},{-2,-3} };
int sand[505][505], n, map[505][505], ans;
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };
vector<storm> v;

bool safe(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }

void setStormOrder() {
	storm cur = { 0,0,2 };
	int k = 1;
	while (!(cur.x == n / 2 && cur.y == n / 2)) {
		map[cur.y][cur.x] = k++;
		v.push_back({ cur.x,cur.y,(cur.d + 2) % 4 });
		if (!safe(cur.x + dx[cur.d], cur.y + dy[cur.d]) || map[cur.y + dy[cur.d]][cur.x + dx[cur.d]])
			cur.d = (cur.d + 3) % 4;
		cur.x += dx[cur.d]; cur.y += dy[cur.d];
	}
	v.push_back({ cur.x,cur.y,(cur.d + 2) % 4 });
}

void moveStorm(storm s) {

	point y = { s.x + dx[s.d],s.y + dy[s.d] };
	point p = { s.x + delta[s.d].x,s.y + delta[s.d].y };
	int origin = sand[y.y][y.x], sum = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			if (ratio[s.d][i][j] <= 0)continue;

			point cur = { p.x + j,p.y + i };
			int minus = ((double)ratio[s.d][i][j] / 100) * sand[y.y][y.x];
			if (!safe(cur.x, cur.y)) {
				ans += minus;
			}
			else {
				sand[cur.y][cur.x] += minus;
			}
			sum += minus;
		}

	sand[y.y][y.x] = 0;
	point alpha = { s.x + dx[s.d] * 2,s.y + dy[s.d] * 2 };
	if (safe(alpha.x, alpha.y))
		sand[alpha.y][alpha.x] += origin - sum;
	else ans += origin - sum;
}

int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)scanf("%d", &sand[i][j]);

	setStormOrder();

	while (!v.empty()) {
		storm s = v.back(); v.pop_back();
		moveStorm(s);
	}

	printf("%d", ans);
	return 0;
}