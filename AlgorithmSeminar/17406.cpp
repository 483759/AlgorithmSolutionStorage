#include <cstdio>
int arr[51][51], n, m, k, ans = 987654321,r[7][3];
bool visit[7];
void rotate(int r, int c, int s) {
	for (int j = 1; j <= s; j++) {
		int cur = arr[r - j][c - j], next;
		for (int i = c - j; i < c + j; i++) {
			next = arr[r - j][i];
			arr[r - j][i] = cur;
			cur = next;
		}
		for (int i = r - j; i < r + j; i++) {
			next = arr[i][c + j];
			arr[i][c + j] = cur;
			cur = next;
		}
		for (int i = c + j; i > c - j; i--) {
			next = arr[r + j][i];
			arr[r + j][i] = cur;
			cur = next;
		}
		for (int i = r + j; i > r - j; i--) {
			next = arr[i][c - j];
			arr[i][c - j] = cur;
			cur = next;
		}
		arr[r - j][c - j] = cur;
	}
}
void dfs(int dep) {
	if (dep == k) {
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < m; j++)
				sum += arr[i][j];
			if (sum < ans)ans = sum;
		}
		return;
	}


	int temp[51][51];
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)
		temp[i][j] = arr[i][j];

	for (int i = 0; i < k; i++) {
		if (visit[i])continue;
		rotate(r[i][0]-1, r[i][1]-1, r[i][2]);
		visit[i] = 1;
		dfs(dep + 1);
		for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)
			arr[i][j] = temp[i][j];
		visit[i] = 0;
	}

}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 0; i < k; i++)
		scanf("%d%d%d", &r[i][0], &r[i][1], &r[i][2]);
	dfs(0);

	printf("%d", ans);
	return 0;
}
//#include <cstdio>
//int arr[51][51], n, m, k,ans=987654321;
//void rotate(int r, int c, int s) {
//	for (int j = 1; j <= s; j++) {
//		int cur = arr[r - j][c - j], next;
//		for (int i = c - j; i < c + j; i++) {
//			next = arr[r - j][i];
//			arr[r - j][i] = cur;
//			cur = next;
//		}
//		for (int i = r - j; i < r + j; i++) {
//			next = arr[i][c + j];
//			arr[i][c + j] = cur;
//			cur = next;
//		}
//		for (int i = c + j; i > c - j; i--) {
//			next = arr[r + j][i];
//			arr[r + j][i] = cur;
//			cur = next;
//		}
//		for (int i = r + j; i > r - j; i--) {
//			next = arr[i][c - j];
//			arr[i][c - j] = cur;
//			cur = next;
//		}
//		arr[r - j][c - j] = cur;
//		//for (int i = r - j; i <= r + j; i++) {
//		//	for (int j = c - j; j <= c + j; j++)
//		//		printf("%d ", arr[i][j]);
//		//	printf("\n");
//		//}
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d%d", &n, &m, &k);
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			scanf("%d", &arr[i][j]);
//	for (int i = 0,r,c,s; i < k; i++) {
//		scanf("%d%d%d", &r, &c, &s);
//		rotate(r - 1, c - 1, s);
//		//for (int i = 0; i < n; i++) {
//		//	for (int j = 0; j < m; j++)
//		//		printf("%d ", arr[i][j]);
//		//	printf("\n");
//		//}printf("\n");
//	}
//
//	for (int i = 0; i < n; i++) {
//		int sum = 0;
//		for (int j = 0; j < m; j++)
//			sum += arr[i][j];
//		if (sum < ans)ans = sum;
//	}
//	printf("%d", ans);
//			return 0;
//}