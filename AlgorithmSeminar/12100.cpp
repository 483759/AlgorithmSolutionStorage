#include <cstdio>
#include <deque>
#define safe(x,y) x>=1&&x<=n&&y>=1&&y<=n
using namespace std;
int n, dir, map[21][21], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
deque<int> q;
void move(int dir) {
	switch (dir) {
	case 1:
		for (int i = 1; i <= n; i++) {	//³²
			for (int j = n; j >= 1; j--) {
				if (!q.empty() && q.back() == map[i][j]) {
					q.pop_back();
					q.push_back(map[i][j] * 2);
				}
				else
					q.push_back(map[i][j]);
			}
			for (int j = n; !q.empty(); j--) {
				map[j][i] = q.front();
				q.pop_front();
			}
		}
		break;
	case 2:
		for (int i = 1; i <= n; i++) {	//¼­
			for (int j = 1; j <= n; j++)
				if (map[i][j]) {
					q.push(map[i][j]);
					map[i][j] = 0;
				}
			for (int j = 1; !q.empty(); j++) {
				map[i][j] = q.front();
				q.pop();
			}
		}
		break;
	case 3:
		for (int i = 1; i <= n; i++) {	//ºÏ
			for (int j = 1; j <= n; j++)
				if (map[j][i]) {
					q.push(map[j][i]);
					map[j][i] = 0;
				}
			for (int j = 1; !q.empty(); j++) {
				map[j][i] = q.front();
				q.pop();
			}
		}
		break;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)scanf("%d", &map[i][j]);
	move(3);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)printf("%d ", map[i][j]);
		printf("\n");
	}printf("\n");
	move(0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)printf("%d ", map[i][j]);
		printf("\n");
	}printf("\n");
	move(3);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)printf("%d ", map[i][j]);
		printf("\n");
	}

	//scanf("%d", &dir);

	return 0;
}
//case 0:
//case 2:
//	for (int i = 1; i <= n; i++) {	//µ¿
//		for (int j = !dir ? n : 1; safe(j, i); j += dx[(dir + 2) % 4])
//			if (map[i][j]) {
//				if (!q.empty() && q.back() == map[i][j]) {
//					q.pop_back();
//					q.push_back(map[i][j] * 2);
//				}
//				else
//					q.push_back(map[i][j]);
//				map[i][j] = 0;
//			}
//		for (int j = !dir ? n : 1; !q.empty(); j += dx[(dir + 2) % 4]) {
//			map[i][j] = q.front();
//			q.pop_front();
//		}
//	}
//	break;
//case 1:
//case 3:
//	for (int i = 1; i <= n; i++) {	//µ¿
//		for (int j = !dir ? n : 1; safe(j, i); j += dy[(dir + 2) % 4])
//			if (map[j][i]) {
//				if (!q.empty() && q.back() == map[j][i]) {
//					q.pop_back();
//					q.push_back(map[j][i] * 2);
//				}
//				else
//					q.push_back(map[j][i]);
//				map[j][i] = 0;
//			}
//		for (int j = !dir ? n : 1; !q.empty(); j += dy[(dir + 2) % 4]) {
//			map[j][i] = q.front();
//			q.pop_front();
//		}
//	}
//	break;
