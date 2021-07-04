#include <cstdio>
#include <math.h>
#include <vector>
using namespace std;
int a, b, t, money[] = { 0,500,300,200,50,30,10 };
vector<int> v[2];
int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d", &t);
	v[0].push_back(0); v[1].push_back(0);
	for (int i = 1; i < 7; i++)
		for (int j = 0; j < i; j++)
			v[0].push_back(i);
	for (int i = 1; i < 6; i++)
		for (int j = 0; j < pow(2, i - 1); j++)
			v[1].push_back(i);
	while (t--) {
		int sum = 0;
		scanf("%d%d", &a, &b);
		if (a && a <= 21)sum += money[v[0][a]];
		if (b && b <= 31)sum += pow(2, 10 - v[1][b]);
		if (!sum)printf("0\n");
		else printf("%d0000\n", sum);
	}

}


//#include <cstdio>
//#include <math.h>
//int t,sa,sb, a[22], b[32], money[6] = { 500, 300, 200, 50, 30, 10 }, money2[] = { 512,256,128,64,32 };
//int main() {
//	for (int i = 1, idx=1; i <= 6; i++)
//		for (int j = 0; j < i; j++, idx++)
//			a[idx] = money[i-1];
//	for (int i = 1, idx = 1; i <= 6; i++)
//		for (int j = 0; j < pow(2,i-1); j++, idx++)
//			b[idx] = money2[i-1];
//	scanf("%d", &t);
//	while (t--) {
//		scanf("%d%d", &sa, &sb);
//		printf("%d\n", (((sa>21)?0:a[sa]) + ((sb>31)?0:b[sb]))!=0?(a[sa]+b[sb])*10000:0);
//	}
//	return 0;
//}