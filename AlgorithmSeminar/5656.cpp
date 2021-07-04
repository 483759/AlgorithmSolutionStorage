#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n, h, w, tc, ans = 5000, map[16][13], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool visit[13];

typedef struct {
	int x, y;
}point;

bool safe(int x, int y) { return x >= 0 && x < w && y >= 0 && y < h; }

void gravity() {	
	queue<int> q;		//중력 작용하기 위해 블럭을 담을 큐
	for (int j = 0; j < w; j++) {		//모든 열에 대해
		if (!visit[j])continue;			//** popBlock에서 체크되지 않은 열은 변화가 없기 때문에 pass **
		for (int i = h - 1; i >= 0; i--) {		//아래에서부터 담는다
			if (map[i][j] != 0) {		//블럭이 있는 곳이라면 큐에 담고 해당 칸을 비워줌
				q.push(map[i][j]);
				map[i][j] = 0;
			}
		}

		for (int i = h - 1; i >= 0; i--) {	//다시 아래에서부터 쌓기
			if (q.empty())break;
			map[i][j] = q.front(); q.pop();
		}
	}
}

int popBlock(point p) {
	int k = map[p.y][p.x], b = 1;	//k: 현재 블록에 써진 숫자 저장, b: 현재 블록에서 연쇄해서 깨지는 벽돌의 개수
	visit[p.x] = 1;					//현재 열에서는 블록의 변화가 일어났다
	map[p.y][p.x] = 0;				//벽돌 깨짐
	for (int i = 0; i < 4; i++) {       //4 방향에 대해 검사
		for (int j = 1; j < k; j++) {       //블록에 써진 숫자의 범위만큼 다른 벽돌도 깨뜨림
			point next = { p.x + dx[i] * j, p.y + dy[i] * j };  //다음 좌표
			if (!safe(next.x,next.y))break;      //범위를 넘어가면 break
			if (map[next.y][next.x] == 0)continue;     //비어있는 곳은 재귀 호출하면 안됨
			b += popBlock(next);         //재귀 호출 하면서 연쇄 작용으로 깨지는 벽돌 수를 더함
		}
	}
	return b;       //깨진 벽돌 수 반환
}

void dfs(int dep, int b) {
	if (dep == n || !b) { //n개의 벽돌을 전부 떨어뜨리거나 더이상 깰 벽돌이 없을 때
		if (b < ans)		//최소값 갱신
			ans = b;
		return;
	}

	int temp[16][13];	//맵 정보를 백업하기 위한 임시 배열
	memcpy(temp, map, sizeof(map));
	for (int i = 0; i < w; i++) {
		point p = { i,0 };
		while (safe(p.x, p.y) && !map[p.y][p.x])p.y++;	//제일 위에 있는 벽돌을 만날 때 까지 내려감

		if (!safe(p.x, p.y))continue;	//만약 맵을 넘었다면? -> 해당 열에는 벽돌이 없음
                                        //굳이 깰 필요가 없으니까 pass 

		int a = popBlock(p);			//현재 열의 top을 깨고 깨진 벽돌의 수 반환 & 변화가 일어난 열 체크
		gravity();						//중력으로 모든 벽돌 내림
		dfs(dep + 1, b - a);

		memcpy(map, temp, sizeof(temp));	//백업해놓은 배열 복원
		memset(visit, false, sizeof(visit));
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		scanf("%d%d%d", &n, &w, &h);

		memset(map, 0, sizeof(map));
		int b = 0;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] != 0)b++;
			}

		dfs(0,b);
		printf("#%d %d\n", t, ans);
		ans = 5000;
	}
	return 0;
}

//boom({ 2,1 });
//gravity();
//for (int i = 0; i < h; i++) {
//	for (int j = 0; j < w; j++)
//		printf("%d ", map[i][j]);
//	printf("\n");
//}
//printf("\n");
//boom({ 2,2 });
//gravity();
//for (int i = 0; i < h; i++) {
//	for (int j = 0; j < w; j++)
//		printf("%d ", map[i][j]);
//	printf("\n");
//}
//boom({ 6,8 });
//gravity();
//printf("\n");
//for (int i = 0; i < h; i++) {
//	for (int j = 0; j < w; j++)
//		printf("%d ", map[i][j]);
//	printf("\n");
//}
//#include <cstdio>
//int n, w, h, count;
//int save[13], map[13][16], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
//bool safe(int r, int c) {
//	return r >= 0 && r < h && c >= 0 && c < w;
//}
//void breakBrick(int r, int c) {
//	int range = map[r][c], count = map[r][c] ? 1 : 0;
//	map[r][c] = 0;
//	for (int i = 0; i < 4; i++) {
//		for (int j = 1; j < range; j++)
//			if (safe(r + dy[i], c + dx[i]))
//				breakBrick(r + dy[i] * j, c + dx[i] * j);
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d", &n, &w, &h);
//	for (int i = 0; i < h; i++)
//		for (int j = 0; j < w; j++)scanf("%d", &map[i][j]);
//	for (int k = 0, temp; k < n; k++) {
//		scanf("%d", &temp);
//		for(int j=0;j<h;j++)
//			if (map[j][temp - 1]) {
//				breakBrick(j, temp - 1);
//				break;
//			}
//		for (int i = 0; i < w; i++) {
//			int idx = 0;
//			for (int j = h - 1; j >= 0; j--) {
//				if (map[j][i]) {
//					save[idx++] = map[j][i];
//					map[j][i] = 0;
//				}
//			}
//			for (int j = h - 1, t = 0; t < idx; j--, t++)
//				map[j][i] = save[t];
//		}
//	}
//	for (int i = 0; i < h; i++)
//		for (int j = 0; j < w; j++)
//			if (map[i][j]) count++;
//	printf("%d\n", count);
//		return 0;
//}

//#include <cstdio>
//int n, w, h, count;
//int save[13], map[13][16], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
//bool safe(int r, int c) {
//	return r >= 0 && r < h && c >= 0 && c < w;
//}
//void breakBrick(int r, int c) {
//	int range = map[r][c], count = map[r][c] ? 1 : 0;
//	map[r][c] = 0;
//	for (int i = 0; i < 4; i++) {
//		for (int j = 1; j < range; j++)
//			if (safe(r + dy[i], c + dx[i]))
//				breakBrick(r + dy[i] * j, c + dx[i] * j);
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d", &n, &w, &h);
//	for (int i = 0; i < h; i++)
//		for (int j = 0; j < w; j++)scanf("%d", &map[i][j]);
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++)
//			printf("%d ", map[i][j]);
//		printf("\n");
//	}
//	printf("\n");
//	for (int k = 0, temp; k < n; k++) {
//		scanf("%d", &temp);
//		for (int j = 0; j<h; j++)
//			if (map[j][temp - 1]) {
//				breakBrick(j, temp - 1);
//				break;
//			}
//		for (int i = 0; i < w; i++) {
//			int idx = 0;
//			for (int j = h - 1; j >= 0; j--) {
//				if (map[j][i]) {
//					save[idx++] = map[j][i];
//					map[j][i] = 0;
//				}
//			}
//			for (int j = h - 1, t = 0; t < idx; j--, t++)
//				map[j][i] = save[t];
//		}
//		for (int i = 0; i < h; i++) {
//			for (int j = 0; j < w; j++) {
//				if (map[i][j]) count++;
//				printf("%d ", map[i][j]);
//			}
//			printf("\n");
//		}printf("\n");
//	}
//
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++) {
//			if (map[i][j]) count++;
//			printf("%d ", map[i][j]);
//		}
//		printf("\n");
//	}
//	printf("%d\n", count);
//
//	return 0;
//}