#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

bool cmp(pii a, pii b) {
	if (a.first == b.first)return a.second < b.second;
	return a.first < b.first;
}

int main() {
	int n;
	pair<int, int> p[100000];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &p[i].first, &p[i].second);

	sort(p, p + n, cmp);

	for (int i = 0; i < n; i++)
		printf("%d %d\n", p[i].first, p[i].second);
}