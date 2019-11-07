#include <cstdio>
#include <cstring>
using namespace std;
int n, m, t, x, d, k, p[51][51], idx[51], ans;
bool chk[51][51];
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)scanf("%d", &p[i][j%m]);
	while (t--) {
		bool b = false;
		int sum = 0, cnt = 0;
		double avg;
		scanf("%d%d%d", &x, &d, &k);
		for (int i = x; i <= n; i += x) idx[i] = d ? (idx[i] + k) % m : (idx[i] - k + m) % m;

		for (int i = 1; i <= n; i++)
			for (int j = idx[i]; j < idx[i] + m; j++) 
			if(p[i][j%m]){
				if (p[i][j%m] == p[i][(j + 1) % m]) {
					chk[i][j%m] = chk[i][(j + 1) % m] = 1;
					b = true;
				}
				if (i != n && p[i][j%m] == p[i + 1][(j - idx[i] + idx[i+1])%m]) {
					chk[i][j%m] = chk[i + 1][(j - idx[i] + idx[i+1])%m] = 1;
					b = true;
				}
			}
		if (b) {
			for (int i = 1; i <= n; i++)
				for (int j = 0; j < m; j++)
					if (chk[i][j%m])p[i][j%m] = 0;
		}
		else {
			for (int i = 1; i <= n; i++)
				for (int j = 0; j < m; j++)
					if (p[i][j%m]) {
						sum += p[i][j%m];
						cnt++;
					}

			avg = (double)sum / cnt;
			for (int i = 1; i <= n; i++)
				for (int j = 0; j < m; j++) {
					if (p[i][j%m] > avg) p[i][j%m]--;
					else if (p[i][j%m] && p[i][j%m] < avg) p[i][j%m]++;
				}
		}
		memset(chk, false, sizeof(chk));
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < m; j++)ans += p[i][j%m];
	printf("%d", ans);
	return 0;
}


//for (int i = 1; i <= n; i++) {
//	for (int j = 0; j < m; j++)printf("%d", chk[i][j%m]);//ans+=p[i][j%m];
//	printf("\n");
//}
//printf("\n");