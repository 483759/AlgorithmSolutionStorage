#include <cstdio>
int n, m, arr[501][501],ans;
struct point { int r,c; };
point t[19][3] = {
	{{1,0},{2,0},{3,0}},
	{{0,1},{0,2},{0,3}},
	{{1,0},{0,1},{1,1}},
	{{1,0},{2,0},{2,1}},
	{{0,1},{1,1},{2,1}},
	{{0,1},{-1,1},{-2,1}},
	{{0,1},{1,0},{2,0}},
	{{1,0},{0,1},{-1,1}},
	{{0,1},{1,1},{1,2}},
	{{1,0},{1,1},{2,1}},
	{{0,1},{-1,1},{-1,2}},
	{{0,1},{1,1},{0,2}},
	{{-1,1},{0,1},{1,1}},
	{{0,1},{-1,1},{0,2}},
	{{1,0},{1,1},{2,0}},
	{{0,1},{0,2},{1,2}},
	{{-1,2},{0,1},{0,2}},
	{{1,0},{1,1},{1,2}},
	{{1,0},{0,1},{0,2}}
};
bool safe(int r, int c) {
	return r >= 0 && r < n && c >= 0 && c < m;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)scanf("%d", &arr[i][j]);
	for (int b = 0; b < 19; b++) {	//블럭 종류

		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++) {
				point p[3]; bool bk=false;
				int sum = arr[i][j];
				for (int k = 0; k < 3; k++) {
					p[k] = {i + t[b][k].r, j + t[b][k].c };
					if (!safe(p[k].r, p[k].c))bk = true;
				}
				if (bk)continue;
				for (int k = 0; k < 3; k++)
					sum += arr[p[k].r][p[k].c];
				if (sum > ans)ans = sum;
			}

	}
	printf("%d", ans);
	return 0;
}