#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
long long d[100002][3], A[3][100002];

int tc, n;
int main() {
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> n;
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= n; j++) {
				cin >> A[i][j];
			}

		d[1][0] = 0;
		d[1][1] = A[1][1];
		d[1][2] = A[2][1];
		for (int j = 2; j <= n; j++)
		{
			d[j][0] = max(d[j - 1][1],d[j - 1][2]);
			d[j][1] = max(d[j - 1][0], d[j - 1][2]) + A[1][j];
			d[j][2] = max(d[j - 1][0], d[j - 1][1]) + A[2][j];
		}
		cout << max(d[n][0], max(d[n][1], d[n][2]));

		//ÃÊ±âÈ­
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= n; j++) {
				A[i][j] = 0;
			}
		for (int j = 0; j <= n; j++)
			for (int i = 0; i < 3; i++)d[j][i] = 0;

	}
	return 0;
}