#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int R, C, K,nor=3,noc=3,a[105][105],ans;
typedef struct{	int n, f; }cnt;
cnt v[101];
bool cmp(cnt a, cnt b) {
	//if (!a.f)return 1;
	//if (!b.f)return 0;
	if (a.f == b.f)return a.n < b.n;
	return a.f < b.f;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &R, &C, &K);
	for (int i = 1; i < 4; i++)
		for (int j = 1; j < 4; j++)
			scanf("%d", &a[i][j]);

	while (++ans) {
		if (nor >= noc) {
			for (int i = 1; i <= nor; i++) {
				for (int j = 1; j <= noc; j++) {
					v[a[i][j]].n = a[i][j];
					v[a[i][j]].f++;
				}
				sort(v, v + nor, cmp);
				printf("");
			}
		}
		else {

		}
	}
	return 0;
}