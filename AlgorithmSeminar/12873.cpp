#include <cstdio>
#include <queue>
#include <math.h>
using namespace std;

queue<int> q;
int main() {
	int n, cnt = 1;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() != 1) {
		long long t;

		t = (long long)pow(cnt, 3) % (n-cnt+1);
		for (int i = 0; i < t-1; i++) {
			q.push(q.front());
			q.pop();
		}
		if (!t) {
			for (int i = 0; i < n - cnt; i++) {
				q.push(q.front());
				q.pop();
			}
		}
		q.pop();
		cnt++;
	}
	printf("%d", q.front());
}