#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int r, c, k,n=3,m=3, a[101][101],cnt[101],ans;
set<int> s; set<int>::iterator it;
vector<pair<int, int>> v;
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &r, &c, &k);
	for (int i = 0; i < 3; i++)for (int j = 0; j < 3; j++)scanf("%d", &a[i][j]);
	while (ans <= 100&&a[r-1][c-1]!=k) {
		if (n >= m) {
			int maxcol = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (!a[i][j])continue;
					it = s.find(a[i][j]);
					if (it == s.end())
						s.insert(a[i][j]);
					cnt[a[i][j]]++;
				}
				for (it = s.begin(); it != s.end(); it++)
					v.push_back({ cnt[*it],*it });
				sort(v.begin(), v.end());
				for (int j = 0; j < v.size(); j++) {
					a[i][2 * j] = v[j].second;
					a[i][2 * j + 1] = v[j].first;
				}
				for (int j = 2 * v.size(); j <= 100; j++)a[i][j] = 0;
				if (v.size() * 2 > maxcol)maxcol = v.size() * 2;
				v.clear(); s.clear(); fill(cnt, cnt + 101, 0);
			}m = maxcol;
		}
		else {
			int maxrow = 0;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j<n; j++) {
					if (!a[j][i])continue;
					it = s.find(a[j][i]);
					if (it == s.end())
						s.insert(a[j][i]);
					cnt[a[j][i]]++;
				}
				for (it = s.begin(); it != s.end(); it++)
					v.push_back({ cnt[*it],*it });
				sort(v.begin(), v.end());
				for (int j = 0; j < v.size(); j++) {
					a[2 * j][i] = v[j].second;
					a[2 * j + 1][i] = v[j].first;
				}
				for (int j = 2*v.size(); j <= 100; j++)a[j][i] = 0;
				if (v.size() * 2 > maxrow)maxrow = v.size() * 2;
				v.clear(); s.clear(); fill(cnt, cnt + 101, 0);
			}n = maxrow;
		}ans++;
	}
	printf("%d", ans > 100 ? -1 : ans);
	return 0;
}