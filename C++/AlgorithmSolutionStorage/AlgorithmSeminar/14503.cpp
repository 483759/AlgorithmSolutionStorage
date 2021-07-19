//로봇청소기
#include <cstdio>
int n, m, dx[] = { 0, 1,0,-1 }, dy[] = { -1,0,1,0 }, r, c, d, ans;
int visit[51][51];
int main() {
	freopen("input.txt", "r", stdin);


	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &r, &c, &d);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &visit[i][j]);
	while (1) {	//계속 반복
		int k = 0;
		if(!visit[r][c])ans++;	
		//만약 청소를 안햇다면 ans 증가(청소할게 없어서 후진햇을때 예외처리)
		visit[r][c] = 2;	//청소햇다고해줍니다
		
		for (int i = (d + 3) % 4; k < 4; i = (i + 3) % 4, k++) {
			if (!visit[r + dy[i]][c + dx[i]]) {	//청소할 수 있을까?
				r += dy[i]; c += dx[i];	//이동한다
				d = i;
				break;
			}
		}
		if (k == 4) {	//네 방향 전부 체크했다면(청소할 곳이 없다면)
			if (visit[r + dy[(d + 2) % 4]][c + dx[(d + 2) % 4]] != 1) {
				//벽이 아니라면 후진
				r += dy[(d + 2) % 4]; c += dx[(d + 2) % 4];
			}
			else {	//네방향 청소 다햇는데 뒤가 벽이면 끝
				printf("%d", ans);
				return 0;
			}
		}
	}
	return 0;
}