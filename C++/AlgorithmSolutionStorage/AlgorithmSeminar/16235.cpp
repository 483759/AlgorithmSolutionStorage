#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct {
	int x, y, z;
}tree;

int n, m, k, A[11][11], map[11][11];
int dx[] = { 1,1,1,0,-1,-1,-1,0 }, dy[] = { -1,0,1,1,1,0,-1,-1 };
vector<int> v[11][11];
queue<tree> death;

bool safe(int x, int y) { return x > 0 && x <= n && y > 0 && y <= n; }

void init() {
	fill(&map[1][1], &map[n + 1][0], 5);

	for (int i = 0, x, y, z; i < m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		v[x][y].push_back(z);
	}
}

void spring() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (v[i][j].empty())continue;

			if (v[i][j].size() > 1)sort(v[i][j].begin(), v[i][j].end());
			int k = 0, size = v[i][j].size();
			for (; k < v[i][j].size(); k++) {
				if (map[i][j] >= v[i][j][k]) {
					map[i][j] -= v[i][j][k];
					v[i][j][k]++;
				}
				else break;
			}

			while (v[i][j].size() != k) {
				death.push({ j,i,v[i][j].back() });
				v[i][j].pop_back();
			}
		}
}

void summer() {
	while (!death.empty()) {
		tree cur = death.front(); death.pop();

		map[cur.y][cur.x] += cur.z / 2;
	}
}

void fall() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (v[i][j].empty())continue;

			for (int k = 0; k < v[i][j].size(); k++) {
				if (v[i][j][k] % 5 == 0) {
					for (int d = 0; d < 8; d++) {
						int nx = j + dx[d], ny = i + dy[d];
						if (safe(nx, ny))
							v[ny][nx].push_back(1);
					}
				}
			}
		}
}

void winter() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			map[i][j] += A[i][j];
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)scanf("%d", &A[i][j]);

	init();
	while (k--) {
		spring();
		summer();
		fall();
		winter();
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans += v[i][j].size();

	printf("%d", ans);

	return 0;
}

//#include <cstdio>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int ans, n, m, K, a[11][11], ground[11][11];
//int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }, 
//    dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
//bool safe(int r, int c) {
//	return c > 0 && c <= n && r > 0 && r <= n;
//}
//vector<int> t[11][11];
//int main() {	
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d", &n, &m, &K);
//
//	fill(&ground[0][0], &ground[10][11], 5);
//
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			scanf("%d", &a[i][j]);
//	for (int i = 0, x, y, z; i < m; i++) {
//		scanf("%d%d%d", &y, &x, &z);
//		t[y][x].push_back(z);
//	}
//
//	while (K--) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1, k=0; j <= n; j++) {
//				if (t[i][j].empty())continue;
//
//				sort(t[i][j].begin(), t[i][j].end());
//
//				for (k = 0; k < (int)t[i][j].size(); k++) {
//					if (ground[i][j] < t[i][j][k])break;
//					ground[i][j] -= t[i][j][k];
//					t[i][j][k] ++;
//				}
//
//				while (k < (int)t[i][j].size()) {
//					ground[i][j] += t[i][j].back()/2;
//					t[i][j].pop_back();
//				}
//			}
//		}
//
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= n; j++) {
//				if (t[i][j].empty())continue;
//
//				for (int k = 0; k < (int)t[i][j].size(); k++) {
//					if (t[i][j][k] % 5)continue;
//
//					for (int d = 0; d < 8; d++)
//						if (safe(i + dr[d], j + dc[d]))
//							t[i + dr[d]][j + dc[d]].push_back(1);
//				}
//			}
//		}
//
//		//겨울
//		for (int i = 1; i <= n; i++)
//			for (int j = 1; j <= n; j++)
//				ground[i][j] += a[i][j];
//
//	}
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			ans += t[i][j].size();
//	printf("%d", ans);
//	return 0;
//}

//#include <cstdio>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int n, m, k, a[11][11], ground[11][11];
//int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
//typedef struct {
//	int age;
//	bool d;
//}tree;
//bool cmp(tree a, tree b) {
//	return a.age > b.age;
//}
//bool safe(int r, int c) {
//	return c >= 0 && c < n && r >= 0 && r < n;
//}
//vector<tree> t[11][11];
//int main() {
//	scanf("%d%d%d", &n, &m, &k);
//
//	fill(&ground[0][0], &ground[9][10], 5);
//
//	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)scanf("%d", &a[i][j]);
//	for (int i = 0, x, y, z; i < m; i++) {
//		scanf("%d%d%d", &y, &x, &z);
//		t[y - 1][x - 1].push_back({ z,false });
//	}
//
//	while (k--) {
//		for(int i=0;i<n;i++)for(int j=0;j<n;j++)
//			sort(t[i][j].begin(), t[i][j].end(), cmp);
//
//		//봄
//		for (int i = 0; i < (int)t.size(); i++) {
//			t[i].year++;
//			int& ref = ground[t[i].r][t[i].c];
//			if (t[i].age > ref) { t[i].d = true; continue; }
//			ref -= t[i].age; t[i].age++;
//		}
//		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
//			if (t[i][j].empty())continue;
//			for (auto a : t[i][j]) {
//				if (a.age > ground[i][j])a.d = true;
//				ground[i][j] -= a.age;
//			}
//		}
//
//		for (vector<tree>::iterator it = t.begin(); it != t.end();) {
//			if ((*it).d) {
//				ground[(*it).r][(*it).c] += (*it).age / 2;
//				it = t.erase(it);
//			}
//			else it++;
//		}
//
//		for (int i = (int)t.size() - 1; i >= 0; i--) {
//			if (t[i].age % 5)continue;
//			for (int j = 0; j < 8; j++) {
//				if (safe(t[i].c + dc[j], t[i].r + dr[j]))
//					t.push_back({ t[i].c + dc[j],t[i].r + dr[j],1 });
//			}
//		}
//
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				ground[i][j] += a[i][j];
//
//	}
//	printf("%d", (int)t.size());
//	return 0;
//}

//#include <cstdio>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int n, m, k, a[11][11], ground[11][11];
//int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
//typedef struct {
//	int r, c, age, year;
//	bool d;
//}tree;
//bool cmp(tree a, tree b) {
//		if (a.year == b.year && a.c == b.c && a.r == b.r)return a.age > b.age;
//		else if (a.year == b.year && a.r == b.r)return a.c > b.c;
//		else if (a.year == b.year)return a.r > b.r;
//		return a.year > b.year;
//};
//bool safe(int r, int c) {
//	return c >= 0 && c < n && r >= 0 && r < n;
//}
//vector<tree> t;
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d", &n, &m, &k);
//
//	fill(&ground[0][0], &ground[9][10], 5);
//
//	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)scanf("%d", &a[i][j]);
//	for (int i = 0, x, y, z; i < m; i++) {
//		scanf("%d%d%d", &y, &x, &z);
//		//t.push({ y - 1, x - 1, z,0 });
//		t.push_back({ y - 1, x - 1, z,0 });
//	}
//
//	while (k--) {//반복
//		sort(t.begin(), t.end(), cmp);
//
//		//봄
//		/*for (int i = t.size(); i > 0; i--) {
//			tree cur = t.top(); t.pop();
//			cur.year++;
//			int& ref = ground[cur.r][cur.c];
//			if (cur.age > ref) {
//				t.push(cur);
//				continue;
//			}
//			ref -= cur.age; cur.age++;
//			t.push(cur);
//		}*/
//		for (int i = 0; i < t.size(); i++) {
//			t[i].year++;
//			int& ref = ground[t[i].r][t[i].c];
//			if (t[i].age > ref) { t[i].d = true; continue; }
//			ref -= t[i].age; t[i].age++;
//		}
//		//if (!t.empty())break;
//
//		//여름
//		/*while (!death.empty()) {
//			ground[death.top().r][death.top().c] += death.top().age / 2;
//			death.pop();
//		}*/
//		for (vector<tree>::iterator it = t.begin(); it != t.end();) {
//			if ((*it).d) { 
//				ground[(*it).r][(*it).c] += (*it).age / 2;
//				it = t.erase(it); 
//			}
//			else it++;
//		}
//		
//
//		//가을
//		/*for (int i = t.size(); i > 0; i--) {
//			tree cur = t.top(); t.pop();
//			cur.year++;
//			if (cur.age % 5) {
//				continue;
//			}
//			grow.push(cur);
//		}
//		while (!grow.empty()) {
//			tree cur = grow.top(); grow.pop();
//			for (int j = 0; j < 8; j++) {
//				if (safe(cur.c + dc[j], cur.r + dr[j]))
//					t.push({ cur.c + dc[j],cur.r + dr[j],1 });
//			}
//			t.push(cur);
//		}*/
//		for (int i = t.size()-1; i >= 0; i--) {
//			if (t[i].age % 5)continue;
//			for (int j = 0; j < 8; j++) {
//				if (safe(t[i].c + dc[j], t[i].r + dr[j]))
//					t.push_back({ t[i].c + dc[j],t[i].r + dr[j],1 });
//			}
//		}
//
//
//		//겨울
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				ground[i][j] += a[i][j];
//
//	}
//	printf("%d",t.size());
//	return 0;
//}