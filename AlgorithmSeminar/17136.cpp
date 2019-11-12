#include <cstdio>
#include <memory.h>
int map[25][25], cnt, paper[6], ans = 50;
bool cvr[11][11], check;
bool iscover(int s, int row, int col) {
	if (row + s > 10 || col + s > 10)return false;
	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++)
			if (!map[row + i][col + j] || cvr[row + i][col + j])return false;
	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++)
			cvr[row + i][col + j] = true;
	return true;
}
void recover(int s, int row, int col) {
	for (int i = 0; i < s; i++)
		for (int j = 0; j < s; j++)
			cvr[row + i][col + j] = false;
}
void func(int r, int c, int s) {
	for (int i = 1; i <= 5; i++)
		if (paper[i] > 5)return;

	if (c >= 10) { 
		func(r + 1, 0, s); return; 
	}	//열을 초과할 때
	if (r >= 10||s==cnt) { 
		int sum = 0;
		for (int i = 1; i <= 5; i++)sum += paper[i];
		if (sum < ans)ans = sum;
		return; 
	}	//탐색을 끝났을 때

	if (!map[r][c] || cvr[r][c]) {
		func(r, c + 1, s);	//색종이가 없을 때
		return;
	}

	for (int i = 5; i > 0; i--) {
		check = iscover(i, r, c);
		if (check) {
			paper[i]++;

			func(r, c + i, s+i*i);

			paper[i]--;
			recover(i, r, c);
		}
	}
	return;
}
int main() {
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			scanf("%d", &map[i][j]);
			check |= map[i][j];
			cnt += map[i][j];
		}
	if (!check) {
		printf("0"); return 0;
	}
	func(0,0,0);
	printf("%d", ans == 50 ? -1 : ans);
	return 0;
}

/*
for (int a = 1; a <= 5; a++) {
	int sum = 0; bool possible = true;
	for (int b = a; b >= 1; b--) {

		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				if (map[i][j] && !c[i][j]) {
					check = iscover(b, i, j);
					if (check)paper[b]++;
				}

		if (paper[b] > 5) { possible = false; break; }
		sum += paper[b];
	}

	if (possible && sum && sum < ans)ans = sum;
	memset(c, false, sizeof(c));
	memset(paper, 0, sizeof(paper));
}*/
//void func(int dep) {
//	if (!dep) {
//		int sum = 0;
//		for (int i = 1; i <= 5; i++)
//			sum += paper[i];
//		if (sum < ans)ans = sum;
//	}
//	for (int i = 0; i < 5; i++)
//		if (paper[i] > 5)return;
//
//	for (int i = 0; i < 10; i++)
//		for (int j = 0; j < 10; j++)
//			if (map[i][j] && !c[i][j]) {
//				check = iscover(dep, i, j);
//				if (check)paper[dep]++;
//
//				for (int k = dep-1; k >= 0; k--)
//					func(k);
//
//				if (check) {
//					paper[dep]--;
//					recover(dep, i, j);
//				}
//
//			}
//}