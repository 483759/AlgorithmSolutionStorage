#include <cstdio>
#include <set>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

pii p[3];
bool visit[3][201];
set<int> s;

void dfs() {
	for (int cur = 0; cur < 3; cur++) {
		if (visit[cur][p[cur].first] || p[cur].first == 0)continue;
		visit[cur][p[cur].first] = true;
		if (p[0].first == 0) 
			s.insert(p[2].first);
		for (int i = 0; i < 3; i++) {
			if (i == cur || p[i].first == p[i].second)continue;
			int d = 0;

			if (p[cur].first >= p[i].second - p[i].first) {
				d = p[i].second - p[i].first;
			}
			else {
				d = p[cur].first;
			}
			p[i].first += d;
			p[cur].first -= d;

			dfs();

			p[i].first -= d;
			p[cur].first += d;
		}
		visit[cur][p[cur].first] = false;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &p[0].second, &p[1].second, &p[2].second);
	p[2].first = p[2].second; dfs();
	for (auto x : s) printf("%d ", x);
	return 0;
}