#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> arr[100001];
int main() {
	int n, min, max, cnt = 1;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);

	sort(arr, arr + n);

	min = arr[0].first; max = arr[0].second;
	for (int i = 1; i < n; i++) {
		if (arr[i].first < max) {
			if (arr[i].second < max) {
				min = arr[i].first;
				max = arr[i].second;
			}
		}
		else {
			cnt++;
			min = arr[i].first;
			max = arr[i].second;
		}
	}
	printf("%d", cnt);
}