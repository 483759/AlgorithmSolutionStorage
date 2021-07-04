#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int** l, ** pre;
vector<int> ans, x(1), y(1);
int main() {
	freopen("pro2_sample_5.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1, k; i <= n; i++) {
		scanf("%d", &k); x.push_back(k);
	}
	scanf("%d", &m);
	for (int i = 1, k; i <= m; i++) {
		scanf("%d", &k); y.push_back(k);
	}

	n++; m++;
	l = new int* [n];	pre = new int* [n];
	for (int i = 0; i < n; i++) {
		l[i] = new int[m];
		pre[i] = new int[m];
	}
	n--; m--;

	//for (int i = 1; i <= n; i++) { l[i][i] = 1; pre[i][i] = 3; }
	for (int i = 0; i <= n; i++) {
		l[0][i] = l[i][0] = 0;
		pre[0][i] = pre[i][0] = 3;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (x[i] == y[j]) {
				l[i][j] = l[i - 1][j - 1] + 1;
				pre[i][j] = 0;
			}
			else if (l[i - 1][j] > l[i][j - 1]) {
				l[i][j] = l[i - 1][j];
				pre[i][j] = 1;
			}
			else {
				l[i][j] = l[i][j - 1];
				pre[i][j] = 2;
			}
	ans.resize(l[n][m]);
	int i = n, j = m, idx = l[n][m] - 1, b = 1;
	while (i > 0 && j > 0 && b) {
		switch (pre[i][j]) {
		case 0:
			ans[idx--] = x[i];
			i--; j--;
			break;
		case 1:
			i--;
			break;
		case 2:
			j--;
			break;
		default:
			b = 0; ans[idx] = x[i];
			break;
		}

	}
	FILE* fp = fopen("pro2_sample_5.out", "w");
	fprintf(fp, "%d\n", l[n][m]);
	for (auto k : ans)fprintf(fp, "%d ", k);
	/*printf("%d\n", l[n][m]);
	for (auto k : ans)printf("%d ", k);*/


	for (int i = 0; i < n; i++) {
		delete(l[i]); delete(pre[i]);
	}delete(l); delete(pre);
	return 0;
}
