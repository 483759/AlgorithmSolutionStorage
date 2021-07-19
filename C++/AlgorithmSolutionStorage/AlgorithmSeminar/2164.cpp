#include <cstdio>
#include <queue>
using namespace std;
int n, t;
queue<int> q;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)q.push(i);
	while (1) {
		if (q.size() == 1)break;
		q.pop();
		t = q.front(); q.pop();
		q.push(t);
	}
	printf("%d", q.front());
	return 0;
}