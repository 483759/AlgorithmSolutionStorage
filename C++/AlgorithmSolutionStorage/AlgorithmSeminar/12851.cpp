#include <cstdio>
#include <queue>
using namespace std;
int n, k, ans, a, map[200001], t;
struct time { int p, t; };
queue<time> q;
void bfs() {
	while (!q.empty()) {
		time c = q.front(); q.pop();
		if (c.p == k) {
			a = c.t;
			ans++;
			continue;
		}
		if (c.p + 1 <= 100000 && !map[c.p + 1]) {
			map[c.p + 1] = c.t + 1;
			q.push({ c.p + 1,c.t + 1 });
		}
		if (c.p -1 >= 0 && !map[c.p - 1]) {
			map[c.p - 1] = c.t + 1;
			q.push({ c.p - 1,c.t + 1 });
		}
		if (c.p * 2 <= 100000 && !map[c.p * 2]) {
			map[c.p * 2] = c.t + 1;
			q.push({ c.p * 2,c.t + 1 });
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	map[n] = -1;
	q.push({ n, 0 });
	bfs();
	printf("%d\n%d", a, ans);
	return 0;
}