#include <cstdio>
#include <math.h>
#include <cstring>
#include <queue>
using namespace std;
int n,map[21][21],ans=1;
int move() {
	queue<int> q; int m = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (map[i][j]) {
				q.push(map[i][j]); map[i][j] = 0;
			}
		if (q.empty())continue;
		map[i][0] = q.front(); q.pop();
		if (map[i][0] > m)m = map[i][0];
		bool b = 0; int cur = 1;
		while (!q.empty()) {
			int num = q.front(); q.pop();
			if (num == map[i][cur - 1] && !b) {
				map[i][cur - 1] *= 2; b = 1;
				if (map[i][cur - 1] > m)m = map[i][cur - 1];
			}
			else {
				map[i][cur++] = num; b = 0;
				if (num > m)m = num;
			}
		}
	}return m;
}
void rotate() {
	int temp[21][21];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)temp[j][n - 1 - i] = map[i][j];
	memcpy(map, temp, sizeof(temp));
}
bool same(int a[][21], int b[][21]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != b[i][j])return 0;
	return 1;
}
void func(int dep,int s) {
	if (dep == 10) {
		/*for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)
			if (map[i][j] > ans)
				ans = map[i][j];*/
		if (s > ans)
			ans = s;
		return;
	}
	int temp[21][21];	
	for (int k = 0; k < 4; k++) {
		memcpy(temp, map, sizeof(map));
		int t = move(); t = log2(t); //if (t > ans)ans = t;
		if (!same(temp, map)&&(ans<t+9-dep)) {
			func(dep + 1,t);

		}
		memcpy(map, temp, sizeof(temp));
		rotate();
	}

}
void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}

}
int main() {
	int k = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
		scanf("%d", &map[i][j]);
		if (log2(map[i][j]) > ans)ans = log2(map[i][j]);
	}
	func(0,ans); printf("%d", (int)pow(2,ans));
	return 0;
}
//#include <cstdio>
//#include <cstring>
//#include <stack>
//using namespace std;
//int n, ans, board[22][22], m[22][22], dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
//int seq[5], kk[] = { 0,3,0,1,3 };
//stack<int> s[22];
//void move(int arr[][22]) {
//	for (int i = 0; i < n; i++)
//		for (int j = 0, check = 0; j < n; j++) {
//			if (!arr[j][i])continue;
//			if (!s[i].empty() && !check && s[i].top() == arr[j][i]) {
//				s[i].pop();
//				s[i].push(arr[j][i] * 2);
//				check = 1;
//			}
//			else {
//				s[i].push(arr[j][i]);
//				check = 0;
//			}
//
//			arr[j][i] = 0;
//		}
//	for (int i = 0; i < n; i++)
//		while (!s[i].empty()) {
//			arr[s[i].size() - 1][i] = s[i].top();
//			s[i].pop();
//		}
//}
//void rotate(int arr[][22]) {
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			m[j][n - 1 - i] = arr[i][j];
//	memcpy(arr, m, sizeof(m));
//}
//void func(int dep) {
//	if (dep == 5) {
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				if (board[i][j] > ans)ans = board[i][j];
//		return;
//	}
//
//	int temp[22][22];
//	for (int i = 0; i < 4; i++) {
//		memcpy(temp, board, sizeof(board));
//		move(board);
//		seq[dep] = i;
//		func(dep + 1);
//		memcpy(board, temp, sizeof(board));
//		rotate(board);
//	}
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			scanf("%d", &board[i][j]);
//	func(0);
//	printf("%d", ans);
//	return 0;
//}