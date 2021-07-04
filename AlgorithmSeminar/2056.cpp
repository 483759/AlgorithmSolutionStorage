#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct { int x, y; }point;
int n, m, ans,map[9][9],tmp[9][9], dx[] = { 1,0,-1,0,1,1,-1,-1 }, dy[] = { 0,1,0,-1,1,-1,1,-1 };
vector<point> cdd;

bool safe(int x, int y) { return x >= 0 && x < m && y >= 0 && y < n; }

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)cdd.push_back({ j,i });;
		}
	
	vector<bool> ps(cdd.size(), false);
	ps[ps.size() - 1] = ps[ps.size() - 2] = ps[ps.size() - 3] = true;

	do {
		memcpy(tmp, map, sizeof(map));

		vector<point> wall;
		for (int i = 0; i < ps.size(); i++)
			if (ps[i]) {
				wall.push_back(cdd[i]);
				tmp[cdd[i].y][cdd[i].x] = 1;
			}

		bool no = false;
		for (point w : wall) {
					bool b = true;
					for (int d = 0; d < 8; d++) {
						int nx = w.x + dx[d], ny = w.y + dy[d];
						if (safe(nx, ny) && tmp[ny][nx]!=0)b = false;
					}
					if (b)no = true;
		}
		if (no)continue;

		bool visit[9][9] = { 0 };
		queue<point> q;

		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++) 
				if(tmp[i][j]==2&&!visit[i][j]){
					q.push({ j,i });
					visit[i][j] = 1;
			}

		while (!q.empty()) {
			point cur = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i], ny = cur.y + dy[i];
				if (!safe(nx, ny) || visit[ny][nx] || tmp[ny][nx] !=0)continue;
				q.push({ nx,ny });
				visit[ny][nx] = 1;
				tmp[ny][nx] = 2;
			}
		}

		int sum = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (tmp[i][j] == 0)sum++;

		if (sum > ans)
			ans = sum;

	} while (next_permutation(ps.begin(),ps.end()));

	printf("%d", ans);
	return 0;
}
//#include <cstdio>
//#include <vector>
//#include <queue>
//using namespace std;
//
//int n, k, indeg[10005], time[10005], ans[10005];
//bool visit[10005];
//vector<int> graph[10005];
//queue<int> q;
//
//int main() {
//	//freopen("input.txt", "r", stdin);
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++) {
//		int m;
//		scanf("%d%d", &time[i], &m);
//		ans[i] = time[i];
//		for (int j = 0, u; j < m; j++) {
//			scanf("%d", &u);
//			graph[u].push_back(i);
//			indeg[i]++;
//		}
//	}
//
//	for (int i = 1; i <= n; i++)
//		if (!indeg[i])q.push(i);
//
//
//	while (!q.empty()) {
//		int cur = q.front(); q.pop();
//		visit[cur] = 1;
//
//		int max = 0, next = 0;
//		for (int u : graph[cur]) {
//			if (ans[u] < ans[cur] + time[u])
//				ans[u] = ans[cur] + time[u];
//
//			indeg[u]--;
//			if (!indeg[u]) {
//				q.push(u);
//			}
//		}
//	}
//
//	for (int i = 1; i <= n; i++)
//		if (ans[i] > k)k = ans[i];
//		
//
//	printf("%d", k);
//
//	return 0;
//}