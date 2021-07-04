#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> map = {
	{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0},
	{0,2,4,6,8,10,13,16,19,25,30,35,40,0},
	{0,2,4,6,8,10,12,14,16,18,20,22,24,25,30,35,40,0},
	{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,28,27,26,25,30,35,40,0}
};

typedef struct {
	int c, i;
}horse;

int dice[10];
vector<int> order;
vector<horse> v;

void roll(int dice, int cur) {
	v[cur].i += dice;
	if (v[cur].c == 0 && (v[cur].i % 5 == 0) && v[cur].i <= 15)
		v[cur].c = (v[cur].i) / 5;
	if (v[cur].i >= map[v[cur].c].size() - 1)
		v[cur].i = map[v[cur].c].size() - 1;
}

bool duplicate() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			if (i == j)continue;
			int ni = map[v[i].c][v[i].i], nj = map[v[j].c][v[j].i];
			if (v[i].i == 0 || v[j].i == 0 || ni == 0 || nj == 0)continue;

			if ((v[i].c == v[j].c) && (v[i].i == v[j].i))return true;
			if (ni == 25 && nj == 25)return true;
			if (ni == 30 && nj == 30
				&& (v[i].i != 15 && v[j].i != 15))return true;
			if (ni == 35 && nj == 35)return true;
			if (ni == 40 && nj == 40)return true;
		}
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 10; i++)
		scanf("%d", &dice[i]);
	int ans = 0;
	for (int a = 0; a < 4; a++)
		for (int b = 0; b < 4; b++)
			for (int c = 0; c < 4; c++)
				for (int d = 0; d < 4; d++)
					for (int e = 0; e < 4; e++)
						for (int f = 0; f < 4; f++)
							for (int g = 0; g < 4; g++)
								for (int h = 0; h < 4; h++)
									for (int i = 0; i < 4; i++)
										for (int j = 0; j < 4; j++) {
											order = { a,b,c,d,e,f,g,h,i,j };
											horse zero = { 0,0 };
											v = { zero, zero, zero, zero };

											int score = 0;
											int check = true;
											for (int k = 0; k < 10; k++) {
												int cur = order[k];
												if (v[cur].i != 0 && map[v[cur].c][v[cur].i] == 0)break;
												roll(dice[k], cur);
												if (duplicate()) {
													check = false; break;
												}
												score += map[v[cur].c][v[cur].i];
											}
											if (check)ans = (score > ans) ? score : ans;
										}
	printf("%d", ans);

	return 0;
}

//#include <cstdio>
//typedef struct { int r, c; }location;
//int dice[10],ans, len[5] = { 21,5,4,5,4 };
//location loc[4];
//int map[6][21] = {
//	{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40},
//{10,13,16,19,25},{20,22,24,25},{30,28,27,26,25},{25,30,35,40}
//};
//location move(int r,int c, int k) {
//	c += k;
//	if (!r) {
//		if (c >= 21)return { 5,0 };
//		switch (map[0][c])
//		{
//		case 10:
//			r = 1; c = 0; break;
//		case 20:
//			r = 2; c = 0; break;
//		case 30:
//			r = 3; c = 0; break;
//		case 25:
//			r = 4; c = 0; break;
//		default:
//			break;
//		}
//		return { r,c };
//	}
//	else if (r < 4) {
//		if (c >= len[r]-1)return move(4, 0, c - len[r]+1);
//		
//		return { r,c };
//	}
//	else if(r==4){
//		if (c >= len[r])return { 5,0 };
//		return { 4,c };
//	}
//}
//void func(int dep, int score) {
//	if (dep == 10) {
//		if (score > ans)
//			ans = score;
//		return;
//	}
//	for (int i = 0; i < 4; i++) {
//		location pre = loc[i];
//		int r = loc[i].r, c = loc[i].c;
//		if (r == 5)continue;
//		
//		location next = move(r, c, dice[dep]);
//
//		bool b = 0;
//		for (int j = 0; j < 4; j++) {
//			if (i == j)continue;
//			if (next.r == 5)break;
//			if (loc[j].r == next.r && loc[j].c == next.c)b=1;
//			if ((map[next.r][next.c] == 40) && (map[loc[j].r][loc[j].c] == 40))b = 1;
//		}
//		if (b)continue;
//		loc[i] = next;
//		func(dep + 1, score + map[next.r][next.c]);
//
//		loc[i] = pre;
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	for (int i = 0; i < 10; i++)scanf("%d", &dice[i]);
//	//location c = move(3, 3, 4);
//	func(0, 0);
//	printf("%d", ans);
//	return 0;
//}
//#include <cstdio>
//#include <cstring>
//#include <vector>
//using namespace std;
//vector<vector<int>> e;
//vector<int> ans;
//int n=6;
//bool ev[105],graph[105][105],visit[105];
//
//int dfs(int cur) {
//	int k = 1;
//	visit[cur] = true;
//	for (int next = 0; next < n; next++)
//		if (!visit[next] && graph[cur][next]) {
//			k+=dfs(next);
//		}
//	return k;
//}
//void perm(int dep,int k){
//	if (dep == 2) {
//		int num[3] = {0}, t = 0;
//		for (int i = 0; i < n - 1; i++)
//			if (ev[i])
//				num[t++] = i;
//
//		pair<int, int> a, b;
//		int con = 0;
//		memset(visit, 0, sizeof(visit));
//		a = make_pair(e[num[0]][0], e[num[0]][1]);
//		b = make_pair(e[num[1]][0], e[num[1]][1]);
//
//		graph[a.first][a.second] = graph[a.second][a.first] = 0;
//		graph[b.first][b.second] = graph[b.second][b.first] = 0;
//
//		for(int i=0;i<n;i++)
//			if (!visit[i]) {
//				if (dfs(i) != n/3)break;
//				con++;
//			}
//
//		graph[a.first][a.second] = graph[a.second][a.first] = 1;
//		graph[b.first][b.second] = graph[b.second][b.first] = 1;
//
//		if (con== n/3) {
//			printf("%d %d\n", num[0], num[1]);
//		}
//		return;
//	}
//	for (int i = k; i < n - 1; i++) {
//		if (ev[i])continue;
//		ev[i] = 1;
//		perm(dep + 1, i + 1);
//		ev[i] = 0;
//	}
//}
//int main() {
//	e = { {0,1},{1,2},{2,3},{3,4},{4,5} };
// perm(0, 0);
//	//printf("%d",ans);
//	return 0;
//}
//#include <cstdio>
//int map[][24] = {
//	{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40},
//	{0,2,4,6,8,10,13,16,19,25,30,35,40},	//12
//	{0,2,4,6,8,10,12,14,16,18,20,22,24,25,30,35,40},
//	{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,28,27,26,25,30,35,40}
//};
//int loc[4], road[4], dice[10], ans, end[4] = { 21,13,17,23 };
//bool canMove(int cur) {
//	int n = map[road[cur]][loc[cur]];
//	if (!n)return 1;
//	for (int i = 0; i < 4; i++) {
//		if (i == cur)continue;
//		if (map[road[i]][loc[i]] != n)continue;
//		if (n == 16 || n == 22 || n == 24 || n == 26 || n == 28) {
//			if ((loc[i] == loc[cur])
//				&& (road[i] == road[cur]))return 0;
//		}
//		else if (n == 30) {
//			if (road[cur] == 0 && loc[cur] == 15) {
//				if (loc[i] == 15)return 0;
//			}
//			else if (road[cur] == 3 && loc[cur] == 15) {
//				if (road[i] == 3 && loc[i] == 15)return 0;
//			}
//			else {
//				if (road[i] == 3 && loc[i] == 15)continue;
//				return 0;
//			}
//
//		}
//		else return 0;
//	}
//	return 1;
//}
//void func(int dep, int score) {
//	if (dep >= 10) {
//		if (score > ans)ans = score;
//		return;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		if ((loc[i] > 0) && !map[road[i]][loc[i]])continue;
//		if (i > dep)continue;
//		int pl = loc[i], pr = road[i];
//		loc[i] += dice[dep];
//
//		if (loc[i] > end[road[i]])loc[i] = end[road[i]];
//
//		int next = map[road[i]][loc[i]];
//
//		if (canMove(i)) {
//			if (next == 10 || next == 20 ||
//				(road[i] == 0 && next == 30))road[i] = next / 10;
//			func(dep + 1, score + next);
//		}
//
//		loc[i] = pl; road[i] = pr;
//	}
//}
//int main() {
//	for (int i = 0; i < 10; i++)scanf("%d", &dice[i]);
//	func(0, 0);
//	printf("%d", ans);
//	return 0;
//}