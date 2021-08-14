#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct {
	int p, t;
}customer;
typedef struct {
	int p, t, c;
}waiting;
typedef struct {
	bool operator()(waiting a, waiting b) {
		return a.c > b.c;
	}
}cmp;

int N, T, W, M;
queue<customer> c;
priority_queue<waiting, vector<waiting>, cmp> w;


int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &N, &T, &W);
	for (int i = 0, p, t; i < N; i++) {
		scanf("%d%d", &p, &t);
		c.push({ p,t });
	}
	scanf("%d", &M);
	for (int i = 0, p, t, c; i < M; i++) {
		scanf("%d%d%d", &p, &t, &c);
		w.push({ p,t,c });
	}

	int time = 0;
	while (time < W) {
		auto cur = c.front(); c.pop();

		for (int t = 0; t < min(cur.t, T); t++) {
			if (time >= W)break;
			printf("%d\n", cur.p);
			time++;
		}
		if (time >= W)break;

		if (!w.empty() && w.top().c <= time) {
			c.push({ w.top().p,w.top().t });
			w.pop();
		}
		if (cur.t > T) {
			c.push({ cur.p,cur.t - T });
		}
	}
	return 0;
}