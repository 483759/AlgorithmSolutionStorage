#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef struct { int n, r, c,d; }shark;
typedef struct { int n, t; }smell;
int n,ans, m, k, map[21][21],temp[21][21], dir[405][5][5], dr[] = { 0,-1,1,0,0 }, dc[] = {0,0,0,-1,1};
smell s[21][21];
vector<shark> v;
vector<shark>::iterator it;
bool safe(int r, int c) { return r >= 0 && r < n && c >= 0 && c < n; }
bool cmp(shark a, shark b) { return a.n < b.n; }
void decrease() {
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)
		if (s[i][j].n) {
			s[i][j].t--;
			if (!s[i][j].t)s[i][j].n = 0;
		}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
		scanf("%d", &map[i][j]);
		if (map[i][j]) {
			s[i][j] = { map[i][j],k };
			v.push_back({ map[i][j],i,j });
		}
	}sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) { scanf("%d", &v[i].d); }
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= 4; j++)for (int l = 1; l <= 4; l++)
			scanf("%d", &dir[i][j][l]);
	}
	while ((ans<=1000)&&(v.size()!=1)) {
		for (it = v.begin(); it != v.end(); ) {
			bool b = 0,dead=0;
			for (int i = 1; i <= 4; i++) {//인접한 곳에서 빈칸?
				int nd=dir[it->n][it->d][i];
				int nr = it->r + dr[nd], nc = it->c + dc[nd];
				if (!safe(nr, nc)||s[nr][nc].n)continue;	//냄새가 있다면 패스
				if (temp[nr][nc]) { dead = 1; break; }
				*it = { it->n,nr,nc,nd }; temp[nr][nc] = it->n;
				b = 1; break;
			}
			if(!b)
				for (int i = 1; i <= 4; i++) {//인접한 곳에서 빈칸?
					int nd = dir[it->n][it->d][i];
					int nr = it->r + dr[nd], nc = it->c + dc[nd];
					if (!safe(nr, nc)||s[nr][nc].n!=it->n)continue;
					if (temp[nr][nc]) { dead = 1; break; }//해당 칸에 이미 있다면
						*it = { it->n,nr,nc,nd }; temp[nr][nc] = it->n;
						b = 1; break;
				}
			if (dead) it = v.erase(it);
			else it++;
		}
		decrease();
		for (auto x : v) {
			s[x.r][x.c] = { x.n,k };
		}
		memcpy(map, temp, sizeof(temp));
		memset(temp, 0, sizeof(temp)); ans++;
	}printf("%d", ans>1000?-1:ans);
	return 0;
}
//#include <cstdio>
//#include <algorithm>
//#include <vector>
//using namespace std;
//typedef struct { int n, d, x, y; }shark;
//typedef struct { int num, sm; }space;
//vector<shark> v;
//space map[21][21];
//int n, m, k,ans, dx[] = { 0,0,0,-1,1 }, dy[] = {0,-1,1,0,0};
//int dir[405][5][4],cnt[21][21];
//bool cmp(shark a, shark b) { return a.n < b.n; }
//bool safe(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d", &n, &m, &k);
//	for (int i = 0; i < n; i++)
//		for (int j = 0, x; j < n; j++) {
//			scanf("%d", &x);
//			if (x)
//				v.push_back({ x,0,j,i });
//		}
//	sort(v.begin(), v.end(),cmp);
//	for (int i = 0, d; i < m; i++)
//		scanf("%d", &v[i].d);
//	for (int i = 1; i <= m; i++)
//		for (int j = 1; j <= 4; j++)
//			for (int l = 0; l < 4; l++)
//				scanf("%d", &dir[i][j][l]);
//	for (auto cur : v)map[cur.y][cur.x] = { cur.n,k };
//	while (v.size() != 1) {
//		vector<shark>::iterator it; ans++;
//		if (ans > 1000) { printf("-1"); return 0; }
//		fill(&cnt[0][0], &cnt[20][21], 0);
//		for (it = v.begin(); it != v.end();) {
//			bool b = 0;
//			for (int i = 0; i < 4; i++) {
//				int nd = dir[it->n][it->d][i];
//				//현재 보고있는 방향에서 우선순위의 방향
//				int nx = it->x + dx[nd], ny = it->y + dy[nd];
//
//				if (safe(nx, ny) && !map[ny][nx].sm) {
//					*it = { it->n,nd,nx,ny };
//					b = 1; break;
//				}
//			}
//			if (!b)for (int i = 0; i < 4; i++) {
//				int nd = dir[it->n][it->d][i];
//				int nx = it->x + dx[nd], ny = it->y + dy[nd];
//
//				if (safe(nx,ny)&&map[ny][nx].num == it->n) {
//					*it = { it->n,nd,nx,ny };
//					break;
//				}
//			}
//			if (cnt[it->y][it->x])
//				it = v.erase(it);
//			else {
//				cnt[it->y][it->x] = 1;
//				it++;
//			}
//		}
//		for(int i=0;i<n;i++)
//			for (int j = 0; j < n; j++)
//				if (map[i][j].sm) {
//					map[i][j].sm--;
//					if (!map[i][j].sm)map[i][j] = { 0,0 };
//				}
//		for (auto cur : v)map[cur.y][cur.x] = { cur.n,k };
//	}printf("%d", ans);
//	return 0;
//}