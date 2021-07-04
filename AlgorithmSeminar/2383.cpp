#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int T, n,map[11][11],ans;
typedef struct { int d,x, y; }stair;
typedef struct { int d,s; }people;
bool cmp(people a, people b) { return a.d < b.d; }
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d", &n); ans = 987654321;
		vector<stair> s; int num=0;
		for(int i=0;i<n;i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1)num++;
				if (map[i][j] > 1)s.push_back({ map[i][j],j,i });
			}

		for (int i = 0; i <= num; i++) {
			vector<int> comb;
			for (int j = 0; j < i; j++)
				comb.push_back(0);
			for (int j = 0; j < num-i; j++)
				comb.push_back(1);

			do {
				int t = 0;
				vector<people> v;
				queue<int> st[2];
				queue<people> pq;

				for(int y=0,id=0;y<n;y++)
					for (int x = 0; x < n; x++) {
						if (map[y][x]==1) {
							int dist = abs(s[comb[id]].x - x) + abs(s[comb[id]].y - y);
							v.push_back({ dist, comb[id] });
							id++;
						}
					}
				sort(v.begin(), v.end(), cmp);
				for (auto x : v)pq.push(x);

				while (!pq.empty()||!st[0].empty()||!st[1].empty()) {
					for (int j = 0; j < 2; j++) {
						for (int k = st[j].size(); k > 0; k--) {
							if (st[j].empty())break;
							int cur = st[j].front()-1; st[j].pop();
							if (!cur)continue;
							st[j].push(cur);
						}
					}

					for (int k = pq.size(); k > 0; k--) {
						if (pq.empty())break;
						people cur = pq.front(); pq.pop();
						cur.d--;
						if (cur.d <= 0 && st[cur.s].size() < 3) {
							if(!cur.d)
							st[cur.s].push(s[cur.s].d+1);
							else
								st[cur.s].push(s[cur.s].d);
						}
						else pq.push(cur);
					}
					t++;
				}
				if (t < ans)ans = t;
				//for (auto x : comb)printf("%d ", x);
				//printf("\n");
			} while (next_permutation(comb.begin(), comb.end()));
		}
		printf("%d\n", ans);
	}
	return 0;
}