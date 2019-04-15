#include <cstdio>
int N, k, r[9][9], g[3][20];
bool iswin;
bool rpc(int arr2[], int h1, int h2, bool* check, int dep) {
	//승수 저장 배열, 지원자 12, 뭐냈는지 체크 배열
	bool arr[9];
	int win[3];
	for (int i = 0; i < 3; i++)
		if (arr2[i] >= k) {	//어떤 사람이 k이상의 승수를 달성하면
			if (!i)return 1;	//그게 지우면 return 1
			return 0;
		}
	for (int i = 0; i < N; i++)arr[i] = check[i];
	for (int i = 0; i < 3; i++)win[i] = arr2[i];	//배열 복사
	int act1 = g[h1][win[h1]] - 1, act2 = g[h2][win[h2]] - 1;	//각자의 손동작을 가져옴
	if (h1&&h2) {	//경희랑 민수가 하면
		if (r[act1][act2] == 2) {	//이기면
			//printf("dep : %d, %d 우승\n", dep, h1);
			win[h1]++;	//승수를 올리고
			if(rpc(win, 0, h1, check, dep + 1))return 1;
			//win[h1]--;
		}
		else {
			//printf("dep : %d, %d 우승\n", dep, h2);
			win[h2]++;
			if (rpc(win, 0, h2, check, dep + 1))return 1;
		}
	}
	for (int i = 0; i < N; i++) {	//지우가 낼 모든 경우 체크
		if (!check[i]) {	//안 낸 손동작인경우
			check[i] = true;
			if (r[i][act2] == 2) {	//지우가 이기면
				//printf("dep : %d, %d vs %d 지우 우승\n", dep, i + 1, act2 + 1);
				win[0]++;
				if (rpc(win, 0, !(h2 - 1) + 1, check, dep + 1))return 1;
				win[0]--;
			}
			else {	//지우가 지면
				//printf("dep : %d, %d vs %d %d 우승\n", dep, i + 1, act2 + 1, h2);
				win[h2]++;
				if (rpc(win, 1, 2, check, dep + 1))return 1;
				win[h2]--;
			}
			check[i] = false;
		}
	}
}
void rpc2(int arr2[], int h1, int h2, bool* check, int dep) {
	bool arr[9];
	int win[3];
	for (int i = 0; i < 3; i++)
		if (arr2[i] >= k) {
			if (!i)iswin = 1;
			return;
		}
	for (int i = 0; i < N; i++)arr[i] = check[i];
	for (int i = 0; i < 3; i++)win[i] = arr2[i];
	int act1 = g[h1][win[h1]] - 1, act2 = g[h2][win[h2]] - 1;
	if (h1&&h2) {
		if (r[act1][act2] == 2) {
			printf("dep : %d, %d 우승\n", dep, h1);
			win[h1]++;
			rpc(win, 0, h1, check, dep+1);
		}
		else {
			printf("dep : %d, %d 우승\n",dep, h2);
			win[h2]++;
			rpc(win, 0, h2, check, dep+1);
		}
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			check[i] = true;
			if (r[i][act2] == 2) {
				printf("dep : %d, %d vs %d 지우 우승\n", dep, i+1, act2+1);
				win[0]++;
				rpc(win, 0, !(h2 - 1) + 1, check, dep+1);
				win[0]--;
			}
			else {
				printf("dep : %d, %d vs %d %d 우승\n", dep, i+1, act2+1, h2);
				win[h2]++;
				rpc(win, 1, 2, check, dep+1);
				win[h2]--;
			}
			check[i] = false;
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	bool check[9];
	int win[3] = { 0 };
	scanf("%d%d", &N, &k);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)scanf("%d", &r[i][j]);
		check[i] = false;
	}
	for (int i = 1; i < 3; i++)
		for (int j = 0; j < 20; j++)scanf("%d", &g[i][j]);

	printf("%d",rpc(win, 0, 1, check, 0));
	return 0;
}

//#include <cstdio>
//int n, k, win;
//int r[9][9], g[2][20];
//bool iswin;
//void game(int win, bool who, int idx, bool* check) {
//	if (win == k) {
//		iswin = 1; return;
//	}
//	int num = g[who][idx];
//	bool arr[9];
//	for (int i = 0; i < n; i++)arr[i] = check[i];
//
//	for (int i = 0; i < n; i++)
//		if (!r[num - 1][i] && !arr[i]) {
//			arr[i] = true;
//			game(win + 1, !who, who + idx, arr);
//			arr[i] = false;
//		}
//}
//int main() {
//	bool check[9];
//	scanf("%d%d", &n, &k);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++)scanf("%d", &r[i][j]);
//		check[i] = false;
//	}
//	for (int i = 0; i < 2; i++)
//		for (int j = 0; j < 20; j++)scanf("%d", &g[i][j]);
//
//	game(0, 0, 0, check);
//	printf("%d", iswin ? 1 : 0);
//	return 0;
//}