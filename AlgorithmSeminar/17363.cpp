#include <iostream>
using namespace std;
int n, m;
char map[101][101], c[120], chr;
int main() {
	c[46] = 46; c[79] = 79; c[45] = 124; c[124] = 45;
	c[47] = 92; c[92] = 47; c[62] = 94; c[94] = 60;
	c[60] = 118; c[118] = 62;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> chr;
			map[j][i] = c[chr];
		}
	}
	for (int i = m-1; i>=0; i--) {
		for (int j = 0; j < n; j++)
			cout << map[i][j];
		cout << '\n';
	}
	return 0;
}