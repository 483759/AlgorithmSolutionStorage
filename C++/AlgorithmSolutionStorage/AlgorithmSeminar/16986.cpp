//#include <cstdio>
//int n, k, arr[10][10], h[3][21], score[2][3], ans, check[10];
//int A[20];
//bool num[10];
//void rpc(int p1, int p2, int dep) {
//	if (ans)return;
//	if (score[0][0] == k) {
//		ans = 1; return;
//	}
//	else if (score[0][1] == k || score[0][2] == k)return;
//
//	int result = arr[h[p1][score[0][p1] + score[1][p1] + 1]][h[p2][score[0][p2] + score[1][p2] + 1]];
//	int np1 = p1, np2 = p2;
//	//p1�� �̱�� 2,����1,����0
//	if (result <= 1) {//p2�� �̱�
//		score[0][p2]++; score[1][p1]++;
//		np1 = p1 ? 0 : 1;
//		rpc(np1, 2, dep + 1);
//		score[0][p2]--; score[1][p1]--;
//	}
//	else {
//		score[0][p1]++; score[1][p2]++;
//		np2 = p2 == 1 ? 2 : 1;
//		rpc(0, np2, dep + 1);
//		score[0][p1]--; score[1][p2]--;
//	}
//}
//void dfs(int dep) {
//	if (ans)return;
//	if (dep > n) {
//		rpc(0, 1, 0);
//		return;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		if (num[i])continue;
//		h[0][dep] = i; num[i] = 1;
//		dfs(dep + 1);
//		num[i] = 0;
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d%d", &n, &k);
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			scanf("%d", &arr[i][j]);
//	for (int i = 1; i <= 2; i++)
//		for (int j = 1; j <= 20; j++)
//			scanf("%d", &h[i][j]);
//	dfs(1);
//	printf("%d", ans);
//
//	return 0;
//}
////#include <cstdio>
////int N, k, r[9][9], g[3][20];
////bool iswin;
////bool rpc(int arr2[], int h1, int h2, bool* check, int dep) {
////	//�¼� ���� �迭, ������ 12, ���´��� üũ �迭
////	bool arr[9];
////	int win[3];
////	for (int i = 0; i < 3; i++)
////		if (arr2[i] >= k) {	//� ����� k�̻��� �¼��� �޼��ϸ�
////			if (!i)return 1;	//�װ� ����� return 1
////			return 0;
////		}
////	for (int i = 0; i < N; i++)arr[i] = check[i];
////	for (int i = 0; i < 3; i++)win[i] = arr2[i];	//�迭 ����
////	int act1 = g[h1][win[h1]] - 1, act2 = g[h2][win[h2]] - 1;	//������ �յ����� ������
////	if (h1&&h2) {	//����� �μ��� �ϸ�
////		if (r[act1][act2] == 2) {	//�̱��
////			//printf("dep : %d, %d ���\n", dep, h1);
////			win[h1]++;	//�¼��� �ø���
////			if(rpc(win, 0, h1, check, dep + 1))return 1;
////			//win[h1]--;
////		}
////		else {
////			//printf("dep : %d, %d ���\n", dep, h2);
////			win[h2]++;
////			if (rpc(win, 0, h2, check, dep + 1))return 1;
////		}
////	}
////	for (int i = 0; i < N; i++) {	//���찡 �� ��� ��� üũ
////		if (!check[i]) {	//�� �� �յ����ΰ��
////			check[i] = true;
////			if (r[i][act2] == 2) {	//���찡 �̱��
////				//printf("dep : %d, %d vs %d ���� ���\n", dep, i + 1, act2 + 1);
////				win[0]++;
////				if (rpc(win, 0, !(h2 - 1) + 1, check, dep + 1))return 1;
////				win[0]--;
////			}
////			else {	//���찡 ����
////				//printf("dep : %d, %d vs %d %d ���\n", dep, i + 1, act2 + 1, h2);
////				win[h2]++;
////				if (rpc(win, 1, 2, check, dep + 1))return 1;
////				win[h2]--;
////			}
////			check[i] = false;
////		}
////	}
////}
////void rpc2(int arr2[], int h1, int h2, bool* check, int dep) {
////	bool arr[9];
////	int win[3];
////	for (int i = 0; i < 3; i++)
////		if (arr2[i] >= k) {
////			if (!i)iswin = 1;
////			return;
////		}
////	for (int i = 0; i < N; i++)arr[i] = check[i];
////	for (int i = 0; i < 3; i++)win[i] = arr2[i];
////	int act1 = g[h1][win[h1]] - 1, act2 = g[h2][win[h2]] - 1;
////	if (h1&&h2) {
////		if (r[act1][act2] == 2) {
////			printf("dep : %d, %d ���\n", dep, h1);
////			win[h1]++;
////			rpc(win, 0, h1, check, dep+1);
////		}
////		else {
////			printf("dep : %d, %d ���\n",dep, h2);
////			win[h2]++;
////			rpc(win, 0, h2, check, dep+1);
////		}
////		return;
////	}
////	for (int i = 0; i < N; i++) {
////		if (!check[i]) {
////			check[i] = true;
////			if (r[i][act2] == 2) {
////				printf("dep : %d, %d vs %d ���� ���\n", dep, i+1, act2+1);
////				win[0]++;
////				rpc(win, 0, !(h2 - 1) + 1, check, dep+1);
////				win[0]--;
////			}
////			else {
////				printf("dep : %d, %d vs %d %d ���\n", dep, i+1, act2+1, h2);
////				win[h2]++;
////				rpc(win, 1, 2, check, dep+1);
////				win[h2]--;
////			}
////			check[i] = false;
////		}
////	}
////}
////int main() {
////	freopen("input.txt", "r", stdin);
////	bool check[9];
////	int win[3] = { 0 };
////	scanf("%d%d", &N, &k);
////	for (int i = 0; i < N; i++) {
////		for (int j = 0; j < N; j++)scanf("%d", &r[i][j]);
////		check[i] = false;
////	}
////	for (int i = 1; i < 3; i++)
////		for (int j = 0; j < 20; j++)scanf("%d", &g[i][j]);
////
////	printf("%d",rpc(win, 0, 1, check, 0));
////	return 0;
////}
////#include <cstdio>
////int n, k, win;
////int r[9][9], g[2][20];
////bool iswin;
////void game(int win, bool who, int idx, bool* check) {
////	if (win == k) {
////		iswin = 1; return;
////	}
////	int num = g[who][idx];
////	bool arr[9];
////	for (int i = 0; i < n; i++)arr[i] = check[i];
////
////	for (int i = 0; i < n; i++)
////		if (!r[num - 1][i] && !arr[i]) {
////			arr[i] = true;
////			game(win + 1, !who, who + idx, arr);
////			arr[i] = false;
////		}
////}
////int main() {
////	bool check[9];
////	scanf("%d%d", &n, &k);
////	for (int i = 0; i < n; i++) {
////		for (int j = 0; j < n; j++)scanf("%d", &r[i][j]);
////		check[i] = false;
////	}
////	for (int i = 0; i < 2; i++)
////		for (int j = 0; j < 20; j++)scanf("%d", &g[i][j]);
////
////	game(0, 0, 0, check);
////	printf("%d", iswin ? 1 : 0);
////	return 0;
////}