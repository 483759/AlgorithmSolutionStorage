#include <cstdio>
#include <algorithm>
#define safe(x,y) x>=0&&x<n&&y>=0&&y<n
using namespace std;
int ans, n,num=1, map[126][126],sum[126][126], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool visit[126][126];
int main() {
	freopen("input.txt", "r", stdin);
	while (scanf("%d", &n)) {
		if (!n)return 0; ans = 1000000;
		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
			for (int k = 0,nx,ny; k < 4; k++) {
				nx = j + dx[k]; ny = i + dy[k];
				if(safe(nx,ny)&&)
			}
		}
		printf("Problem %d: %d\n", num++,ans);
	}
	return 0;
}