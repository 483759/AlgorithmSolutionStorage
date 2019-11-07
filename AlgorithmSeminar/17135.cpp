#include <cstdio>
struct point { int x, y; };
int n, m, d, dx[] = {1,0,-1};
bool val[16][16];
struct point { int x, y; };
void move(int dep) {

}
void func(int a1, int a2, int a3) {

}
int main() {
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)
		scanf("%d", &val[i][j]);
	for(int i=0;i<n-2;i++)
		for(int j=i+1;j<n-1;j++)
			for (int k = j+1; k < n; j++) {
				func(i, j, k);
			}
	return 0;
}