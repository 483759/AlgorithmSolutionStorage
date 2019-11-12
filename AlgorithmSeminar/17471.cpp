#include <cstdio>
#include <memory.h>
int map[11][11], paper[6] = { 0,5,5,5,5,5 }, cnt[6], ans = 50;
bool c[11][11], check;
bool iscover(int s, int row, int col) {
	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++)
			if (!map[row + i][col + j] || c[row + i][col + j])return false;
	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++)
			c[row + i][col + j] = true;
	return true;
}
int main() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			scanf("%d", &map[i][j]);
			check |= map[i][j];
		}
	if (!check) {
		printf("0"); return 0;
	}
	for (int a = 1; a <= 5; a++) {
		int sum = 0; bool possible = true;
		for (int b = a; b >= 1; b--) {

			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
					if (map[i][j] && !c[i][j]) {
						check = iscover(b, i, j);
						if (check)cnt[b]++;
					}

			if (cnt[b] > 5) { possible = false; break; }
			sum += cnt[b];
		}

		if (possible && sum && sum < ans)ans = sum;
		memset(c, false, sizeof(c));
		memset(cnt, 0, sizeof(cnt));
	}
	printf("%d", ans == 50 ? -1 : ans);
	return 0;
}
//#include <cstdio>
//#include <queue>
//using namespace std;
//int n, p[11], ans=10000000;
//bool graph[11][11], gu[11], visit[11];
//queue<int> q;
//int bfs(int num) {
//	int k = 1;
//	visit[num] = true;
//	q.push(num);
//	while (!q.empty()) {
//		int cur = q.front(); q.pop();
//		for (int t = 1; t <= n; t++) {
//			if (graph[cur][t] && !visit[t] && gu[cur] == gu[t]) {
//				visit[t] = true;
//				q.push(t); k++;
//			}
//		}
//	}
//	return k;
//}
//void func(int dep) {
//	if (dep > n) {
//		int red = 0, blue = 0, sub,j;
//		for (int i = 1; i <= n; i++)visit[i] = false;
//
//		red = bfs(1);
//		if (red == n)return;
//		
//		for (j = 2; j <= n; j++)
//			if (!visit[j]) {
//				blue=bfs(j); break;
//			}
//		if (red + blue != n)return;
//		red = blue = 0;
//
//		for (int i = 1; i <= n; i++)
//			if (gu[i])red += p[i];
//			else blue += p[i];
//		sub = red > blue ? red - blue : blue - red;
//		ans = sub < ans ? sub : ans;
//		return;
//	}
//
//	gu[dep] = 0;
//	func(dep + 1);
//	gu[dep] = 1;
//	func(dep + 1);
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)scanf("%d", &p[i]);
//	for (int i = 1,t,j; i <= n; i++) {
//		scanf("%d", &t);
//		while (t--) {
//			scanf("%d", &j);
//			graph[i][j] = true;
//			graph[j][i] = true;
//		}
//	}
//	func(1);
//	printf("%d", ans==10000000?-1:ans);
//	return 0;
//}