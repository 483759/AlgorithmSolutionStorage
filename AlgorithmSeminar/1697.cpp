#include <cstdio>
#include <queue>
using namespace std;
int n, k, map[200001], t;
struct time { int p, t; };
queue<time> q;
int bfs() {
	while (!q.empty()) {
		time c = q.front(); q.pop();
		if (c.p == k)return c.t;
		if (c.p < 100000 && !map[c.p + 1]) {
			map[c.p + 1] = c.t + 1;
			q.push({ c.p + 1,c.t + 1 });
		}
		if (c.p - 1 >= 0 && !map[c.p - 1]) {
			map[c.p - 1] = c.t + 1;
			q.push({ c.p - 1,c.t + 1 });
		}
		if (c.p * 2 < 100000 && !map[c.p * 2]) {
			map[c.p * 2] = c.t + 1;
			q.push({ c.p * 2,c.t + 1 });
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	map[n] = -1;
	q.push({ n, 0 });
	printf("%d", bfs());
	return 0;
}
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//int n, k;
//int map[100001];
//int val[100001];
//int func(int c, int t) {
//	int& ref = val[c];
//	if (t > ref)return;
//	ref = min(func(c - 1, t + 1), func(c + 1, t + 1));
//	ref = min(ref, func(2 * c, t + 1));
//	return t;
//}
//int main() {
//	scanf("%d%d", &n, &k);
//	fill(val, val + 100000, 100000);
//	
//	return 0;
//}