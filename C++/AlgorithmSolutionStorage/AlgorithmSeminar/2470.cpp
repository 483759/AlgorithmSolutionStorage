#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n,left,right;

int main() {
	scanf("%d", &n);
	v = vector<int>(n, 0);

	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());

	left = 0; right = 1;
	while (1) {
		int sum = v[left] + v[right];
	}
	return 0;
}

// -99 -2 -1 4 98