#include <cstdio>
#include <queue>
using namespace std;
int n, m,map[105],visit[105];
int bfs() {
	queue<int> q;
	
	visit[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		
		if (map[cur]) { visit[map[cur]] = visit[cur]; cur = map[cur]; }
		if (cur == 100)return visit[cur]-1;
		for (int i = 1; i <= 6; i++) {
			int next = cur + i;
			if ((next > 100)||visit[next])continue;
			visit[next] = visit[cur] + 1;
			q.push(next);
		}
	}
	return -1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0,x,y; i < n+m; i++) {
		scanf("%d%d", &x, &y);
		map[x] = y;
	}
	printf("%d",bfs());
	return 0;
}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#define INF 987654321
//using namespace std;
//vector<int> v;
//int duck[21][2];
//int n, p, e;
//int main() {
//	cin >> n >> p >> e;
//	for (int i = 0; i < n; i++) {
//		cin >> duck[i][0] >> duck[i][1];
//	}
//
//	vector<bool> check(n,false);
//	for (int i = 0; i <= n; i++) {
//		if(i)check[n - i] = 1;
//		do {
//			int minSum=0, maxSum=0,cnt=0;
//			for (int j = 0; j < n; j++) {
//				if (!check[j])continue;
//				minSum += duck[j][0];
//				maxSum += duck[j][1];
//				cnt++;
//			}
//			if ((!(minSum < e && e < maxSum))||cnt!=p)continue;
//			int E = e - minSum;
//			v.clear();
//			for (int j = 0; j < n; j++) {
//				if (!check[j])v.push_back(0);
//				else {
//					v.push_back(duck[j][0]);
//					while (E > 0 && v[j] < duck[j][1]) {
//						v[j]++;
//						E--;
//					}
//				}				
//			}
//		} while (next_permutation(check.begin(),check.end()));
//	}
//	if (v.empty())
//		printf("-1");
//	else {
//		for (int i = 0; i < v.size(); i++)
//			printf("%d ", v[i]);
//	}
//}

//#include <cstdio>
//#include <vector>
//#include <algorithm>
//#include <queue>
//using namespace std;
//typedef struct {
//	int x, y;
//}point;
//int n, map[30][30], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//bool visit[30][30];
//bool safe(int x, int y) {
//	return x >= 0 && x < n && y >= 0 && y < n;
//}
//int bfs(point p) {
//	queue<point> q;
//
//	int cnt = 1;
//	visit[p.y][p.x] = 1;
//	q.push(p);
//	while (!q.empty()) {
//		point cur = q.front(); q.pop();
//		for (int i = 0; i < 4; i++) {
//			int nx = cur.x + dx[i], ny = cur.y + dy[i];
//			if (!safe(nx, ny) || !map[ny][nx] || visit[ny][nx])continue;
//			q.push({ nx,ny });
//			visit[ny][nx] = 1;
//			cnt++;
//		}
//	}
//	return cnt;
//}
//int main() {
//	vector<int> v;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)scanf("%1d", &map[i][j]);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			if (map[i][j] && !visit[i][j]) {
//				v.push_back(bfs({ j,i }));
//			}
//	printf("%d\n", v.size());
//	sort(v.begin(), v.end());
//	for (int k : v)printf("%d\n", k);
//	return 0;
//}

//#include <cstdio>
//#include <queue>
//#include <algorithm>
//using namespace std;
//struct p { int x, y; };
//queue<p> q;
//bool map[26][26], visit[26][26];
//int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 }, num[300];
//int N, cnt, index;
//bool safe(int x, int y) {
//	return x >= 0 && x < N && y >= 0 && y < N;
//}
//int bfs() {
//	int hnum = 1;
//	while (!q.empty()) {
//		p cur = q.front(); q.pop();
//		for (int next = 0, tx, ty; next < 4; next++) {
//			tx = cur.x + dx[next], ty = cur.y + dy[next];
//			if (safe(tx, ty) && map[ty][tx] && !visit[ty][tx]) {
//				visit[ty][tx] = true;
//				q.push({ tx, ty });
//				hnum++;
//			}
//		}
//	}
//	return hnum;
//}
//int main() {
//	scanf("%d", &N);
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++) {
//			scanf("%1d", &map[i][j]);
//		}
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++) {
//			if (map[i][j] && !visit[i][j]) {
//				q.push({ j, i });
//				visit[i][j] = true;
//				num[cnt]=bfs();
//				cnt++;
//			}
//		}
//	sort(num, num + cnt);
//	printf("%d\n", cnt);
//	for (int i = 0; i < cnt; i++)
//		printf("%d\n", num[i]);
//	return 0;
//}