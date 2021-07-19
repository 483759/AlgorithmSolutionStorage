#include <cstdio>
#include <cstring>
typedef struct {
	int x, y;
}point;
int tc,ans,n,map[105][105];
int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//우,하,좌,상
int block[6][4] = {
	{0,0,0,0},
	{2,0,3,1},
{2,3,1,0},
{1,3,0,2},
{3,2,0,1},
{2,3,0,1}
};
void move(point s, int dir) {
	point cur = s;
	int sum = 0;

	 do{
		cur.x += dx[dir], cur.y += dy[dir];	//이동
		int k = map[cur.y][cur.x];

		if (!k)continue;	//비엇다면
		else if (k == -1)
			break;
		else if (k <= 5) {
			sum++;
			dir = block[k][dir];
		}
		else if (k <= 10) {
			bool check=0;
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++)	//다른 웜홀 탐색
					if (map[i][j] == k && (cur.x != j || cur.y != i)) {
						cur.x = j, cur.y = i;
						check = 1;
						break;
					}
				if (check)break;
			}
		}
	 } while ((cur.x != s.x || cur.y != s.y)	//시작 위치랑 블랙홀이 아닐 때 까지
		 && map[cur.y][cur.x] != -1);
	if (sum > ans)ans = sum;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int T = 1; T <= tc; T++) {
		ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &map[i][j]);
		for (int i = 1; i <= n; i++) {
			map[0][i] = map[n + 1][i] = map[i][0] = map[i][n + 1] = 5;
		}	//벽을 5번 블록으로 처리


		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++){
				if (map[i][j])continue;
				for (int k = 0; k < 4; k++)
					move({ j,i }, k);
			}

		printf("#%d %d\n",T, ans);
		memset(map, 0, sizeof(map));
	}
	return 0;
}