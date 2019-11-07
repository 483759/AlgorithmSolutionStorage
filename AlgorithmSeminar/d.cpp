#include <iostream>
using namespace std;
int n, m;
bool map[501][51];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)cin >> map[i][j];
	return 0;
}