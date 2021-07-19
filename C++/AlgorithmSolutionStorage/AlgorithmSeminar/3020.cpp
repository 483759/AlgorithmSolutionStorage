#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, h, height[2][500005], arr[2][500005];
vector<int> v[2];


int main() {
	freopen("input.txt", "r", stdin);

	scanf("%d%d", &n, &h);
	for (int i = 0, k; i < n; i++) {
		scanf("%d", &k);
		if (i % 2) {
			arr[1][h - k+1]++;
		}
		else {
			arr[0][k]++;
		}
	}
	for (int i = h; i > 0; i--) 
		arr[0][i - 1] += arr[0][i];
	
	for (int i = 1; i <= h ; i++)
		arr[1][i] += arr[1][i - 1];

	int min=n, ans=0;
	for (int i = 1; i <= h; i++) {
		if (arr[0][i] + arr[1][i] < min) {
			min = arr[0][i] + arr[1][i];
			ans = 1;
		}
		else if (arr[0][i] + arr[1][i] == min)
			ans++;
	}
	
	printf("%d %d", min, ans);
	return 0;
}