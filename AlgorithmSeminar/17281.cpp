////#include <cstdio>
////int main() {
////	int t[4] = { 0,1,1,0 }, s = 2, sum = 0;
////	t[0] = 1;
////	for (int i = 3; i >= 0; i--) {
////		if (i + s >= 4) { if (t[i])sum++; }
////		else
////			t[i + s] = t[i];
////		t[i] = 0;
////	}
////	return 0;
////}
//#include <cstdio>
//#include <queue>
//#include <algorithm>
//using namespace std;
//int n,ans,order[9], num[8] = { 2,3,4,5,6,7,8,9 }, score[51][10], a[10];
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &n);
//	order[4] = 1;
//	for (int i = 0; i < n; i++)
//		for (int j = 1; j <= 9; j++)scanf("%d", &score[i][j]);
//	do {
//		for (int i = 0; i < 9; i++) {
//			order[i] = (i < 3) ? num[i] : num[i - 1];
//			order[3] = 1;
//			//printf("%d ",order[i]);
//		}//printf("\n"); 
//
//		int sum = 0,cur=0;
//		for (int i = 0; i < n; i++) {
//			int out = 0, k = 9, t[4] = { 0 };
//			while(out<3){
//				int c = order[cur],s=score[i][c];
//				cur = (cur + 1) % 9;
//
//				if (!score[i][c]) {
//					out++;
//					if (out >= 3)break;
//				}
//				else {
//					t[0] = 1;
//					for (int i = 3; i >= 0; i--) {
//						if (i + s >= 4) { if (t[i])sum++; }
//						else
//							t[i + s] = t[i];
//						t[i] = 0;
//					}
//				}
//			}
//		}
//		if (sum > ans)ans = sum;
//	} while (next_permutation(&num[0], &num[8]));
//	printf("%d", ans);
//	return 0;
//}