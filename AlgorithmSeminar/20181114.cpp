#include <cstdio>
int main() {

	return 0;
}

//#include <cstdio>
//int N, M, cnt;
//bool arr[101][101], visit[101];
//void dfs(int cur) {
//	visit[cur] = true;
//	//printf("%d ", cur);
//	for (int i = 1; i <= N; i++)
//		if (arr[cur][i] && !visit[i])
//			dfs(i);
//}
//int main() {
//	scanf("%d", &N); scanf("%d", &M);
//	for (int i = 0, a, b; i < M; i++) {
//		scanf("%d %d", &a, &b);
//		arr[a][b] = true;
//		arr[b][a] = true;
//	}
//	dfs(1);
//	for (int i = 2; i <= N; i++)
//		if (visit[i])cnt++;
//	printf("%d", cnt);
//	return 0;
//}

//#include <cstdio>
//int num[3], N, cnt[10];
//int main() {
//	for (int i = 0; i < 3; i++) scanf("%d", &num[i]);
//	N = num[0] * num[1] * num[2];
//	while (N) {
//		cnt[N % 10]++;
//		N /= 10;
//	}
//	for (int i = 0; i < 10; i++)
//		printf("%d\n", cnt[i]);
//	return 0;
//}

//#include <cstdio>
//int N, X, Y, cnt;
//bool pnt[101][101];
//int main() {
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++) {
//		scanf("%d%d", &X, &Y);
//		for (int j = 0; j < 10; j++) {
//			for (int k = 0; k < 10; k++)
//				pnt[X + j][Y + k] = true;
//		}
//	}
//	for (int i = 0; i < 100; i++)
//		for (int j = 0; j < 100; j++)
//			cnt += (pnt[i][j]) ? 1 : 0;
//	printf("%d", cnt);
//}

//#include <cstdio>
//int num, cnt[3];
//int main() {
//	for (int i = 0; i < 3; i++) {
//		num = 0;
//		for (int j = 0; j < 4; j++) {
//			scanf("%1d", &num);
//			cnt[i] += num;
//		}
//	}
//	for (int i = 0; i < 3; i++) {
//		switch (cnt[i]) {
//		case 0:
//			printf("E\n");
//			break;
//		case 1:
//			printf("C\n");
//			break;
//		case 2:
//			printf("B\n");
//			break;
//		case 3:
//			printf("A\n");
//			break;
//		case 4:
//			printf("D\n");
//			break;
//		default:
//			break;
//		}
//
//	}
//	return 0;
//}

//#include <cstdio>
//
//char arr[5][16] = { NULL };
//
//int main() {
//	for (int i = 0; i < 5; i++)
//		scanf("%s", arr[i]);
//
//	for (int j = 0; j < 15; j++)
//		for (int i = 0; i < 5; i++)
//			if (arr[i][j] != NULL)
//				printf("%c", arr[i][j]);
//
//	return 0;
//}