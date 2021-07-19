#include <cstdio>
int magnet[4][8], index[4],k,tc,ans;
bool connect[4][4] = {
	{0,1,0,0},{1,0,1,0},{0,1,0,1},{0,0,1,0}
},visit[4];
void dfs(int cur,int d) {

	for (int next = 0; next < 4; next++) {
		if ((!connect[cur][next])||visit[next])continue;
		visit[next] = 1;

		if (cur < next) {	//오른쪽 자석
			if (magnet[cur][(index[cur] + 2) % 8] != magnet[next][(index[next] - 2+8) % 8]) {
				//서로 다르면
				dfs(next, d * -1);
			}
		}
		else {
			if (magnet[cur][(index[cur] - 2 +8) % 8] != magnet[next][(index[next] + 2) % 8])
				dfs(next, d * -1);
		}
	}

	index[cur] = (index[cur] + (d * -1) + 8) % 8;	//현재 자석 회전

}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int T = 1; T <= tc; T++) {
		ans = 0;
		scanf("%d", &k);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++)
				scanf("%d", &magnet[i][j]);
			index[i] = 0;
		}

		int num, dir;

		for (int i = 0; i < k; i++) {
			scanf("%d%d", &num, &dir);
			for (int j = 0; j < 4; j++)visit[j] = 0;

			visit[num - 1] = 1;
			dfs(num-1, dir);
		}

		for (int i = 0,j=1; i < 4; i++,j*=2)
			ans += magnet[i][index[i]]*j;

		printf("#%d %d\n", T,ans);
		
	}
	return 0;
}