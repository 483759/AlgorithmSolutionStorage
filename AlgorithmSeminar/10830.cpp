#include <cstdio>
#include <vector>
#define ull unsigned long long
#define MOD 1000
using namespace std;

int n;
ull B;

vector<vector<int>> matrixMultiply(vector<vector<int>> a, vector<vector<int>> b) {
	vector<vector<int>> c;
	for (int i = 0; i < n; i++) {
		c.push_back(vector<int>(n,0));
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				c[i][j] = (c[i][j]+((a[i][k] * b[k][j])%MOD))%MOD;
		}
	}
	return c;
}

vector<vector<int>> matrixSquared(vector<vector<int>> a, ull k) {
	if (k == 1)return a;
	vector<vector<int>> half = matrixSquared(a, k / 2);
	vector<vector<int>> b = matrixMultiply(half,half);
	if (k % 2 == 0)return b;
	return matrixMultiply(b, a);
}

void print(vector<vector<int>> a) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)printf("%d ", a[i][j]%MOD);
		printf("\n");
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	vector<vector<int>> A;

	scanf("%d%lld", &n, &B);
	for (int i = 0; i < n; i++) {
		A.push_back(vector<int>(n));
		for (int j = 0, k; j < n; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	//vector<vector<int>> t = A;
	//while (B--) {
	//	print(t);
	//	t = matrixMultiply(t, A);
	//}
	print(matrixSquared(A, B));

	return 0;
}

//#include <cstdio>
//#include <vector>
//#define mod 1000
//#define ull unsigned long long
//using namespace std;
//int n;
//ull k;
//
//vector<vector<int>> matrixMultiply(vector<vector<int>> a, vector<vector<int>>b) {
//	vector<vector<int>> c;
//	for (int i = 0; i < n; i++) {
//		vector<int> v(n,0);
//		for(int h=0;h<n;h++)
//		for (int j = 0; j < n; j++) {
//			int mul = ((a[i][h] % mod) * (b[h][j] % mod)) % mod;
//			v[j]=((v[j]%mod)+mul)%mod;
//		}
//		c.push_back(v);
//	}
//	return c;
//}
//
//vector<vector<int>> matrixSquare(vector<vector<int>> mat,ull k) {
//	if (k == 1) {
//		return mat;
//	}
//	vector<vector<int>> v = matrixSquare(mat, k / 2);
//	v = matrixMultiply(v, v);
//	if (k % 2) return matrixMultiply(v, mat);
//	else return v;
//}
//int main() {
//	freopen("input.txt", "r", stdin);
//	vector<vector<int>> mat;
//	scanf("%d%lld", &n, &k);
//	for (int i = 0; i < n; i++) {
//		vector<int> v(n,0);
//		for (int j = 0, num; j < n; j++) {
//			scanf("%d", &v[j]);
//		}
//		mat.push_back(v);
//	}
//	mat = matrixSquare(mat, k);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++)
//			printf("%d ", mat[i][j]%mod);
//		printf("\n");
//	}
//	return 0;
//}