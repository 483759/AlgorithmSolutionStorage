#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef struct {
	int a, b, c;
}process;
typedef struct {
	bool operator()(process a, process b) {
		if (a.c == b.c)return a.a > b.a;
		return a.c < b.c;
	}
}cmp;

int T, n;
priority_queue<process, vector<process>, cmp> pq;
vector<process> v;

int main() {
	scanf("%d%d", &T, &n);

	for (int tc = 1, a, b, c; tc <= n; tc++) {
		scanf("%d%d%d", &a, &b, &c);
		pq.push({ a,b,c });
	}

	for (int t = 0; t < T; t++) {
		process s = pq.top(); pq.pop();

		if (s.b != 1)
			pq.push({ s.a,s.b - 1,s.c-1 });
		printf("%d\n", s.a);
	}
	return 0;
}