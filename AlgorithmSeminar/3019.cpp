#include <cstdio>
int map[19][19], dx[] = { 1,0,1,1 }, dy[] = { 0,1,1,-1 };
int n;
bool safe(int x, int y) { return x >= 0 && x < 19 && y >= 0 && y < 19; }
bool func(int x, int y, int d, int c) {
	int sum = 0, max = 0;
	while (safe(x, y)) {
		if (map[y][x] == c)sum++;
		else {
			if (sum == 5)
				return 1;
			sum = 0;
		}
		x += dx[d], y += dy[d];
	}
	if (sum == 5)
		return 1;
	return 0;
}
bool count(int c) {
	for (int i = 0; i < 19; i++) {
		if (func(0, i, 0, c))return 1;
		if (func(i, 0, 1, c))return 1;
		if (func(0, i, 2, c))return 1;
		if (func(i, 0, 2, c))return 1;
		if (func(0, i, 3, c))return 1;
		if (func(i, 18, 3, c))return 1;
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	int i, r, c;
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &r, &c);
		map[r - 1][c - 1] = i % 2 ? 1 : 2;
		if (count(1))break;
		if (count(2))break;
	}
	if (i > n)printf("-1");
	else printf("%d", i);

	return 0;
}

//#include <cstdio>
//int map[19][19], dx[] = { 1,0,1,1 }, dy[] = { 0,1,1,-1 };
//int n;
//bool safe(int x, int y) { return x >= 0 && x < 19 && y >= 0 && y < 19; }
//bool func(int x, int y, int d,int c) {
//	int sum = 0,max=0;
//	while (safe(x, y)) {
//		if (map[y][x] == c)sum++;
//		else {
//			if (sum == 5)
//				return 1;
//			sum = 0;
//		}
//		x += dx[d], y += dy[d];
//	}
//	if (sum == 5)
//		return 1;
//	return 0;
//}
//bool count(int c) {
//	for (int i = 0; i < 19; i++) {
//		if (func(0, i, 0, c))return 1;
//		if (func(i, 0, 1, c))return 1;
//	}
//
//	for (int i = 0; i < 19; i++) {
//		if (func(0, i, 2, c))return 1;
//		if (func(i, 0, 2, c))return 1;
//	}
//
//	for (int i = 0; i < 19; i++) {
//		if (func(0, i, 3, c))return 1;
//		if (func(i, 18, 3, c))return 1;
//	}
//	return 0;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &n);
//	int i,r,c;
//	for (i = 1; i <= n; i++) {
//		scanf("%d%d", &r, &c);
//		map[r - 1][c - 1] = i % 2 ? 1 : 2;
//		if (count(1))break;
//		if (count(2))break;
//	}
//	if (i > n)printf("-1");
//	else printf("%d", i);
//
//	return 0;
//}

//#include <cstdio>
//int truck[1005], n, w, l, sum[1005], time[1005];
//int front, rear, ans;
//
//void print() {
//	printf("Hello");
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d", &n, &w, &l);
//	for (int i = 1; i <= n; i++) {
//		scanf("%d", &truck[i]);
//		sum[i] = sum[i - 1] + truck[i];
//		time[i] = w;
//	}
//
//	print();
//
//	while (front < n) {
//		if ((sum[rear + 1] - sum[front] < l) && (rear <= n)) {
//			rear++;
//		}
//		int f = 0;
//		for (int i = front + 1; i <= rear; i++) {
//			time[i]--;
//			if (!time[i])
//				f++;
//		}
//		front += f;
//		ans++;
//	}
//	printf("%d", ans + 1);
//	return 0;
//}