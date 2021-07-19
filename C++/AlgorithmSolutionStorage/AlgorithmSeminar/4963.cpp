#include <cstdio>
#include <memory.h>
int w, h,ans,dx[] = { 1,0,-1,0,1,1,-1,-1 }, dy[] = {0,1,0,-1,1,-1,1,-1};
bool map[51][51], v[51][51];
struct point { int x, y; };
bool safe(int x, int y) {
	return x>=0&&x<w&&y>=0&&y<h;
}
void dfs(point p) {
	v[p.y][p.x] = true;
	for (int i=0,nx,ny; i< 8; i++) {
		nx = p.x + dx[i]; ny = p.y + dy[i];
		if (safe(nx,ny)&&!v[ny][nx] && map[ny][nx])
			dfs({ nx,ny });
	}
}
int main() {
	while (scanf("%d%d", &w, &h)) {
		if (!w && !h)return 0;
		for (int i = 0; i < h; i++)for (int j = 0; j < w; j++)
			scanf("%d", &map[i][j]);
		for (int i = 0; i < h; i++)for (int j = 0; j < w; j++){
			if (!v[i][j] && map[i][j]) {
				dfs({ j,i });
				ans++;
			}
		}
		printf("%d\n", ans);
		ans = 0; 
		memset(v,false,sizeof(v));
	}
	return 0;
}