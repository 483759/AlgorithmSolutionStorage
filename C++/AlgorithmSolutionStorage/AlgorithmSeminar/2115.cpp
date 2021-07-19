#include <bits/stdc++.h>
using namespace std;

int n, m,c,tc;

int main() {
	cin >> n >> m;
	return 0;
}


//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int n, m, c,tc,map[11][11],ans,money[2];
//vector<int> v[2];
//bool desc(int a, int b) { return a > b; }
//int maxmoney(int num,int sum,int p,int dep) {
//	if (sum > c)return -1;
//	if (dep == v[num].size()) { 
//		if (p > money[num])money[num] = p;
//		return sum; 
//	}
//	int a = maxmoney(num, sum,p, dep + 1);
//	int b = maxmoney(num, sum + v[num][dep], p + v[num][dep]*v[num][dep], dep + 1);
//	return a > b ? a : b;
//}
//void honey(int s,int d,int num) {
//	for (int i = d; i < n; i++) {
//		//if(num==1)
//		for (int j = 0; j < n; j++) {
//			if (num == 1 && i == d&&!j)j = s;
//			if (j + m - 1 >= n)break;	//범위 넘어가면 다음 줄
//			int sum = 0;
//			for (int k = j; k < j + m; k++) {
//				v[num].push_back(map[i][k]);
//				sum += map[i][k];
//			}
//			maxmoney(num, 0, 0, 0);
//
//			if (num) {	//2번째까지 다 왔담연
//				int a = money[0]+money[1];
//				//for (int k = 0; k < 2; k++)
//				//	for (auto x : v[k])
//				//		a += x * x;
//				if (a > ans)
//					ans = a;
//			}
//			else {
//				honey(j + m, i, 1);
//			}
//			v[num].clear();
//			money[num] = 0;
//		}
//	}
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	scanf("%d", &tc);
//	for (int T = 1; T <= tc; T++) {
//		ans = 0;
//		scanf("%d%d%d", &n, &m, &c);
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				scanf("%d", &map[i][j]);
//
//		for (int i = 0; i < n; i++)
//			for (int j = m; j < n; j++);
//
//		honey(0, 0,0);
//		printf("#%d %d\n", T,ans);
//		money[0]=money[1] = 0;
//	}
//	return 0;
//}