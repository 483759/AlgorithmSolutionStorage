#include <cstdio>
int n, arr[2][16], dp[16], m,ans;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%d%d", &arr[0][i], &arr[1][i]);
	for (int i = 0; i < n; i++) {
		if (arr[0][i] + i > n)continue;
		dp[i] = arr[1][i]; m = 0;
		for (int j = i-1; j >= 0; j--) {
			if (arr[0][j] + j <= i) {
				m = dp[j] > m ? dp[j] : m;
			}
		}
		dp[i] += m;
	}
	for (int i = 0; i < n; i++)ans = dp[i] > ans ? dp[i] : ans;
	printf("%d", ans);
	return 0;
}
//#include <cstdio>
//int n;
//struct c { int t, p; };
//c arr[16], dp[16][2];
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)scanf("%d%d", &arr[i].t, &arr[i].p);
//	dp[0][0] = { 1,0 };
//	if (arr[0].t <= n)
//		dp[0][1] = { arr[0].t,arr[0].p };
//	for (int i = 1; i < n; i++) {
//		c& ref0 = dp[i - 1][0], ref1 = dp[i - 1][1];
//		if (ref0.p > ref1.p) {
//			dp[i][0] = { ref0.t - 1, ref0.p };
//		}
//		else {
//			dp[i][0] = { ref1.t - 1,ref1.p };
//		}
//		if (i + arr[i].t <= n) {
//			dp[i][1] = { arr[i].t,arr[i].p };
//			if (ref0.t <= 1 && ref1.t <= 1) dp[i][1].p += (ref0.p > ref1.p) ? ref0.p : ref1.p;
//			else if (ref0.t <= 1)dp[i][1].p += ref0.p;
//			else if (ref1.t <= 1)dp[i][1].p += ref1.p;
//		}
//	}
//	if (dp[n - 1][0].t > 1 && dp[n - 1][1].t > 1)printf("0");
//	else
//		printf("%d", dp[n - 1][0].p > dp[n - 1][1].p ? dp[n - 1][0].p : dp[n - 1][1].p);
//	return 0;
//}
//#include <cstdio>
//int n;
//struct c { int t, p; };
//c arr[16], dp[16][2];
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)scanf("%d%d", &arr[i].t, &arr[i].p);
//	//dp[0][0] = 0; dp[0][1] = arr[0].p;
//	for (int i = 0; i < n; i++) {
//		c& ref0 = dp[i - 1][0], ref1 = dp[i - 1][1];
//		if (ref0.p > ref1.p) {
//			dp[i][0] = { ref0.t - 1, ref0.p };
//			/*if (ref0.t <= 1&&)
//				dp[i][1] = { arr[i].t,ref0.p + arr[i].p };*/
//		}
//		else {
//			dp[i][0] = { ref1.t - 1,ref1.p };
//			/*if (ref1.t <= 1)
//				dp[i][1] = { arr[i].t,ref1.p + arr[i].p };*/
//		}
//		if (i + arr[i].t <= n) {
//			dp[i][1] = { arr[i].t,arr[i].p };
//			if(ref0.t<=1&&ref1.t<=1) dp[i][1].p += (ref0.p > ref1.p) ? ref0.p : ref1.p;
//			else if (ref0.t <= 1)dp[i][1].p += ref0.p;
//			else if (ref1.t <= 1)dp[i][1].p += ref1.p;
//		}
//		//if ((ref0.t<=1||ref1.t <= 1) && i + arr[i].t <= n) {
//		//	dp[i][1].p += (ref0.p > ref1.p) ? ref0.p : ref1.p;
//		//}
//	}
//	printf("%d", dp[n - 1][0].p > dp[n - 1][1].p ? dp[n - 1][0].p : dp[n - 1][1].p);
//	return 0;
//}
//#include <cstdio>
//#define max(a,b) (a)>(b)?(a):(b)
//int n;
//struct c { int t, p; };
//c arr[16];
//int func(int k) {
//	if (k == n && arr[k].t == 1)return arr[k].p;
//	else if (k > n)return 0;
//	return max(arr[k].p + func(k + arr[k].t), func(k + 1));
//}
//int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)scanf("%d%d", &arr[i].t, &arr[i].p);
//	printf("%d", func(1));
//	return 0;
//}