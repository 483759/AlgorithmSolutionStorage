#include <cstdio>
#include <queue>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;
int row, col, king, ans, m, dx[] = { 0,0,0,1,-1 }, dy[] = { 0,-1,1,0,0 };
queue<int> map[101][101];
struct shark { int r, c, s, d, z; };
shark v[10001];
vector<pair<int, shark>> eat;
bool b[10001];
bool safe(int r, int c) {
	return r > 0 && r <= row && c > 0 && c <= col;
}
bool cmp(pair<int,shark> a, pair<int, shark> b) {
	return a.second.z > b.second.z;
}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &row, &col, &m);
	memset(b, true, sizeof(b));
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d%d", &v[i].r, &v[i].c, &v[i].s, &v[i].d, &v[i].z);
		map[v[i].r][v[i].c].push(i);
	}
	while (king++ != col) {
		for (int i = 1; i <= row; i++)
			if (!map[i][king].empty()) {
				b[map[i][king].front()] = false;
				ans += v[map[i][king].front()].z;
				//printf("%d\n", v[map[i][king].front()].z);
				map[i][king].pop();
				break;
			}
		//상어 잡음

		for (int i = 1,nr,nc,size; i <= m; i++) {
			if (!b[i])continue;
			int cr = v[i].r, cc = v[i].c;
			if (v[i].d <= 2)
				size = (v[i].s) % ((row - 1) * 2);
			else
				size= (v[i].s) % ((col - 1) * 2);
			for (int j = 0; j < size; j++) {	//속도만큼이동
				nr = cr + dy[v[i].d], nc = cc + dx[v[i].d];
				if (!safe(nr, nc)) {
					v[i].d = v[i].d % 2 ? v[i].d + 1 : v[i].d - 1;
					nr = cr + dy[v[i].d], nc = cc + dx[v[i].d];
				}
				cr = nr; cc = nc;
			}
			map[v[i].r][v[i].c].pop();
			v[i].r = cr, v[i].c = cc;
			map[cr][cc].push(i);
		}

		for(int i=1;i<=row;i++)
			for(int j=1;j<=col;j++)
				if (map[i][j].size() > 1) {
					int size = map[i][j].size();
					for (int k = 0; k < size; k++) {
						eat.push_back({map[i][j].front(),v[map[i][j].front()]});
						map[i][j].pop();
					}
					sort(eat.begin(), eat.end(), cmp);
					map[i][j].push(eat[0].first);
					for (int k = 1; k < size; k++)
						b[eat[k].first] = false;
					eat.clear();					
				}
		//for (int i = 1; i <= row; i++) {
		//	for (int j = 1; j <= col; j++)
		//		printf("%c", map[i][j].empty()?'0':map[i][j].front()+'A'-1);
		//	printf("\n");
		//}printf("\n");
	}
	printf("%d", ans);
	return 0;
}