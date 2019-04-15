#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

queue<pii> q;

bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int num, n, m;
	freopen("input.txt", "r", stdin);
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		int t, arr[100] = { 0 }, index = 0;
		pii pi, tmp;
		scanf("%d %d", &n, &m);

		for (int j = 0; j < n; j++) {	//Å¥¿¡ »ðÀÔ
			scanf("%d", &t);
			q.push(pii(t, j));
		}

		for (int j = 0; j < n; j++) {
			if (q.front().second == m)
				pi = q.front();
			arr[j] = q.front().first;
			q.push(q.front());
			q.pop();
		}

		sort(arr, arr + n, cmp);

		while (!q.empty()) {
			while (q.front().first != arr[index]) {
				q.push(q.front());
				q.pop();
			}
			tmp = q.front();
			q.pop();
			index++;
			if (tmp == pi)
				break;
		}

		printf("%d\n", index);

		while (!q.empty())
			q.pop();
	}
	return 0;
}