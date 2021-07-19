#include <cstdio>
#include <cstring>
typedef struct { int x, y, d; }fish;
fish f[17];
int ans,map[4][4], dx[] = { 0,-1,-1,-1,0,1,1,1 }, dy[] = { -1,-1,0,1,1,1,0,-1 };
bool dead[17];
bool safe(int x, int y) { return x >= 0 && x < 4 && y >= 0 && y < 4; }
void move(fish s) {
	for (int i = 1; i <= 16; i++) {
		if (dead[i])continue;
		for (int j = 0; j < 8; j++) {
			int nd = (f[i].d + j) % 8;
			int nx = f[i].x + dx[nd], ny = f[i].y + dy[nd];
			if ((nx == s.x && ny == s.y) || !safe(nx, ny))continue;
			int next = map[ny][nx];
			if (!next) {//다음 칸이 비었으면?
				map[f[i].y][f[i].x] = 0;
				map[ny][nx] = i;
				f[i] = { nx,ny,nd };
			}
			else {
				int num; fish temp;
				map[ny][nx] = i; map[f[i].y][f[i].x] = next;

				f[next].x = f[i].x; f[next].y = f[i].y;
				f[i] = { nx,ny,nd };
			}				
			break;
		}
	}
}
void func(fish cur,int sum) {
	int tmap[4][4]; fish tf[17]; bool b = 0;
	memcpy(tmap, map, sizeof(map)); memcpy(tf, f, sizeof(f));
	move(cur);
	for (int i = 0; i < 4; i++) {
		int nx = cur.x + dx[cur.d] * i, ny = cur.y + dy[cur.d] * i;
		if (!safe(nx, ny)||!map[ny][nx])continue;
		int next = map[ny][nx];
		dead[next] = 1; map[ny][nx] = 0;
		func({ nx,ny,f[next].d }, sum + next);
		dead[next] = 0; map[ny][nx] = next; b = 1;
	}
	if (!b&&(sum > ans))ans = sum;
	memcpy(map, tmap, sizeof(tmap)); memcpy(f, tf, sizeof(tf));
}
int main() {
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 4; i++)for (int j = 0; j < 4; j++) {
		int d;
		scanf("%d", &map[i][j]);
		scanf("%d", &d);
		f[map[i][j]] = { j,i,d-1 };		
	}
	int n = map[0][0];	dead[n] = 1; map[0][0] = 0;
	fish shark = { 0,0,f[n].d };
	//move(shark);
	func(shark, n);
	printf("%d", ans);
	return 0;
}
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//
//int dx[] = { 0,-1,-1,-1,0,1,1,1 }, dy[] = { -1,-1,0,1,1,1,0,-1 };
//int map[4][4], answer=0;
//typedef struct { int x,y, d, a; }fish;
//typedef struct { int x,y; }point;
//fish f[17];
//
//bool safe(int x, int y) {
//	return x >= 0 && x < 4 && y >= 0 && y < 4;
//}
//void fishmove(fish shark) {
//	for (int i = 1; i <= 16; i++) {
//		if (!f[i].a)continue;
//		for (int j = 0; j < 8; j++) {
//			int nx = f[i].x + dx[f[i].d], ny = f[i].y + dy[f[i].d];
//			if (!safe(nx, ny) || (shark.x == nx && shark.y == ny)) { 
//				f[i].d = (f[i].d + 1) % 8;
//				continue; 
//			}
//			int next = map[ny][nx];
//			if (map[ny][nx]) {
//				point temp = { nx,ny };
//				f[next].x = f[i].x; f[next].y = f[i].y;
//				f[i].x = temp.x; f[i].y = temp.y;
//				map[f[i].y][f[i].x] = i;
//				map[f[next].y][f[next].x] = next;
//			}
//			else {
//				map[f[i].y][f[i].x] = 0;
//				map[ny][nx] = i;
//				f[i].x = nx; f[i].y = ny;
//			}
//			break;
//		}
//	}
//}
//void func(fish shark,int score) {
//	fish tf[17];
//	int tmap[4][4];
//	int td = shark.d;
//
//	copy(f, f + 17, tf);
//	copy(&map[0][0], &map[0][0] + 16, &tmap[0][0]);
//
//	bool b = 1;
//	while (safe(shark.x, shark.y)) {
//
//		shark.x += dx[shark.d]; shark.y += dy[shark.d];
//		if (!safe(shark.x, shark.y)) {
//			answer = score > answer ? score:answer;
//			return;
//		}
//
//		int num = map[shark.y][shark.x];
//		if (map[shark.y][shark.x]) {
//			shark.d = f[num].d;
//			f[num].a = 0;
//			map[shark.y][shark.x] = 0;
//		}
//		else continue;
//		fishmove(shark);
//		func(shark, score + num);
//		f[num].a = 1; shark.d = td;
//		copy(tf, tf + 17, f);
//		copy(&tmap[0][0], &tmap[0][0] + 16, &map[0][0]);
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	for (int i = 0; i < 4; i++)
//		for (int j = 0; j < 4; j++) {
//			int d;
//			scanf("%d%d", &map[i][j], &d);
//			f[map[i][j]] = { j,i,d-1,1 };
//		}
//	int num = map[0][0];
//	fish shark = { 0,0,f[num].d,0 };
//	f[num].a = 0; map[0][0] = 0;
//	fishmove(shark);
//	func(shark, num);
//	printf("%d", answer);
//	return 0;
//}