#include <cstdio>
#include <queue>
#define max 4000
using namespace std;
typedef struct {
	int x, y;
}point;
typedef struct {
	point p;
	int d, e;
}atom;
vector<atom> v;
queue<point> c;
int tc, ans, n, dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
int map[max][max];
bool safe(int x, int y){return x >= 0 && x < max && y >= 0 && y < max;}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int T = 1; T <= tc; T++) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 0,x,y,d,e; i < n; i++) {
			scanf("%d%d%d%d", &x, &y, &d, &e);
			x = (x + 1000) * 2;
			y = (y + 1000) * 2;
			v.push_back({ {x,y},d,e });
		}
		vector<atom>::iterator it;

		for (int t = 0; t <= max; t++) {

			for (it = v.begin(); it != v.end();) {
				it->p.x += dx[it->d];
				it->p.y += dy[it->d];
				
				if (!safe(it->p.x, it->p.y)) {
					it=v.erase(it);
					continue;
				}
				map[it->p.y][it->p.x]++;
				it++;
			}
			for (it = v.begin(); it != v.end();) {
				if (map[it->p.y][it->p.x]>1) {
					ans += it->e;
					c.push(it->p);
					it=v.erase(it);
					continue;
				}
				map[it->p.y][it->p.x]=0;
				it++;
			}
			while (!c.empty()) {
				map[c.front().y][c.front().x] = 0;
				c.pop();
			}
		}

		printf("#%d %d\n", T, ans);
		v.clear();
	}
	return 0;
}