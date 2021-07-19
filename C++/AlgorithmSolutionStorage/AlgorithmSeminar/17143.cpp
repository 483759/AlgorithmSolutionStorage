#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct { int r, c; }point;
typedef struct { point p; int s, d, z, b; }shark;
vector<shark> v;
vector<shark>::iterator it;
int ans,r, c, m, dr[] = { 0,-1,1,0,0 }, dc[] = { 0,0,0,1,-1 }, map[105][105],temp[105][105];
bool safe(int x, int y) {
	return x >= 0 && x < c && y >= 0 && y < r;
}
shark nextpoint(shark s) {
	int sp;
	if (s.d < 3) {
		int cur = s.p.r;
		sp = s.s % ((r - 1) * 2);

		cur += sp*dr[s.d];
		while (cur<0||cur>=r) {
			if (cur < 0) { s.d = 2; cur = cur * -1; }
			else if (cur >= r) { s.d = 1; cur = r - (cur - r) - 2; }
		}
		s.p.r = cur;
	}
	else {
		int cur = s.p.c;
		sp = s.s % ((c - 1) * 2);

		cur += sp*dc[s.d];
		while (cur < 0 || cur >= c) {
			if (cur < 0) { s.d = 3; cur = cur * -1; }
			else if (cur >= c) { s.d = 4; cur = c - (cur - c) - 2; }
		}
		s.p.c = cur;
	}
	return s;

}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &r, &c, &m); v.push_back({ 0 });
	for (int i = 1; i <= m; i++) {
		shark s;
		scanf("%d%d%d%d%d", &s.p.r, &s.p.c, &s.s, &s.d, &s.z);
		s.p.r--; s.p.c--; s.b = 1;
		map[s.p.r][s.p.c] = i;
		v.push_back(s);
	}
	for (int j = 0; j < c; j++) {
		int cur = 0;
		while ((cur < r) && !map[cur][j])cur++;
		if (cur < r) {
			int num = map[cur][j];
			ans += v[num].z;
			v[num].b = 0;
			map[cur][j] = 0;
		}
		for (int i = 1; i < v.size(); i++) {
			if (!v[i].b)continue;
			shark next = nextpoint(v[i]);
			int num = temp[next.p.r][next.p.c];
			if (!num) {
				v[i] = next;
				temp[v[i].p.r][v[i].p.c] = i;
			}
			else if (num == i)
				v[i] = next;
			else {
				if (v[i].z >= v[num].z) {
					v[i] = next;
					v[num].b = 0;
					temp[v[i].p.r][v[i].p.c] = i;
				}
				else
					v[i].b = 0;
			}
		}
		memcpy(map, temp, sizeof(temp));
		memset(temp, 0, sizeof(temp));
	}printf("%d", ans);
	return 0;
}
//#include <cstdio>
//#include <queue>
//#include <memory.h>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int row, col, king, ans, m, dx[] = { 0,0,0,1,-1 }, dy[] = { 0,-1,1,0,0 };
//queue<int> map[101][101];
//struct shark { int r, c, s, d, z; };
//shark v[10001];
//vector<pair<int, shark>> eat;
//bool b[10001];
//bool safe(int r, int c) {
//	return r > 0 && r <= row && c > 0 && c <= col;
//}
//bool cmp(pair<int,shark> a, pair<int, shark> b) {
//	return a.second.z > b.second.z;
//}
//int main() {
//	//freopen("input.txt", "r", stdin);
//	scanf("%d%d%d", &row, &col, &m);
//	memset(b, true, sizeof(b));
//	for (int i = 1; i <= m; i++) {
//		scanf("%d%d%d%d%d", &v[i].r, &v[i].c, &v[i].s, &v[i].d, &v[i].z);
//		map[v[i].r][v[i].c].push(i);
//	}
//	while (king++ != col) {
//		for (int i = 1; i <= row; i++)
//			if (!map[i][king].empty()) {
//				b[map[i][king].front()] = false;
//				ans += v[map[i][king].front()].z;
//				//printf("%d\n", v[map[i][king].front()].z);
//				map[i][king].pop();
//				break;
//			}
//		//상어 잡음
//
//		for (int i = 1,nr,nc,size; i <= m; i++) {
//			if (!b[i])continue;
//			int cr = v[i].r, cc = v[i].c;
//			if (v[i].d <= 2)
//				size = (v[i].s) % ((row - 1) * 2);
//			else
//				size= (v[i].s) % ((col - 1) * 2);
//			for (int j = 0; j < size; j++) {	//속도만큼이동
//				nr = cr + dy[v[i].d], nc = cc + dx[v[i].d];
//				if (!safe(nr, nc)) {
//					v[i].d = v[i].d % 2 ? v[i].d + 1 : v[i].d - 1;
//					nr = cr + dy[v[i].d], nc = cc + dx[v[i].d];
//				}
//				cr = nr; cc = nc;
//			}
//			map[v[i].r][v[i].c].pop();
//			v[i].r = cr, v[i].c = cc;
//			map[cr][cc].push(i);
//		}
//
//		for(int i=1;i<=row;i++)
//			for(int j=1;j<=col;j++)
//				if (map[i][j].size() > 1) {
//					int size = map[i][j].size();
//					for (int k = 0; k < size; k++) {
//						eat.push_back({map[i][j].front(),v[map[i][j].front()]});
//						map[i][j].pop();
//					}
//					sort(eat.begin(), eat.end(), cmp);
//					map[i][j].push(eat[0].first);
//					for (int k = 1; k < size; k++)
//						b[eat[k].first] = false;
//					eat.clear();					
//				}
//		//for (int i = 1; i <= row; i++) {
//		//	for (int j = 1; j <= col; j++)
//		//		printf("%c", map[i][j].empty()?'0':map[i][j].front()+'A'-1);
//		//	printf("\n");
//		//}printf("\n");
//	}
//	printf("%d", ans);
//	return 0;
//}