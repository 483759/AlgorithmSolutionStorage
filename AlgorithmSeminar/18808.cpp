#include <stdio.h>
int n;
char c;
int main() {
	scanf("%d",&n);
	if (n == 1) {
		scanf("%d", &n);
		printf("%c", n);
	}
	else {
		scanf(" %c", &c);
		printf("%d", c);
	}
	return 0;
}
//#include <cstdio>
//#include <cstring>
//typedef struct { int w, h, mon[11][11]; }sticker;
//int n, m,k,map[41][41];
//sticker s[101];
//void rotate(int num) {
//	int temp[11][11] = { 0 };
//	int w = s[num].w, h = s[num].h;
//	if (w > h) {
//		for (int i = 0; i < w; i++)
//			for (int j = 0; j < w; j++)
//				temp[j][w-1-i] = s[num].mon[i][j];
//		for (int i = 0; i < w; i++)
//			for (int j = 0; j < w; j++)
//				s[num].mon[i][j] = temp[i][j + (w - h)];
//	}
//	else {
//		for (int i = 0; i < h; i++)
//			for (int j = 0; j < h; j++)
//				temp[j][h-1-i] = s[num].mon[i][j];
//		for (int i = 0; i < h; i++)
//			for (int j = 0; j < h; j++)
//				s[num].mon[i][j] = temp[i][j];
//	}
//	s[num].w = h; s[num].h = w;
//}
//int main() {
//	scanf("%d%d%d", &n, &m, &k);
//	for (int l = 0; l < k; l++) {
//		memset(s[l].mon, 0, sizeof(s[l].mon));
//		scanf("%d%d", &s[l].h, &s[l].w);
//		for (int i = 0; i < s[l].h; i++)
//			for (int j = 0; j < s[l].w; j++)
//				scanf("%d", &s[l].mon[i][j]);
//		int R = 4;
//		bool com = 0;
//		while (R--) {
//			for(int i=0;i<=n-s[l].h;i++)
//				for (int j = 0; j <= m - s[l].w; j++) {
//					if (com)break;
//					//½ÃÀÛÁÂÇ¥ = (i,j)
//					bool check = 1;
//					for (int a = 0; a < s[l].h; a++)
//						for (int b = 0; b < s[l].w; b++)
//							if (map[i + a][j + b] && s[l].mon[a][b])
//								check = 0;
//					if (check) {
//						for (int a = 0; a < s[l].h; a++)
//							for (int b = 0; b < s[l].w; b++)
//								map[i + a][j + b] |= s[l].mon[a][b];
//						com = 1;
//					}
//
//				}
//			if (com)break;
//			rotate(l);
//		}
//	}
//	int ans = 0;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)if (map[i][j])ans++;
//	printf("%d", ans);
//	return 0;
//}