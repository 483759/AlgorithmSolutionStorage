#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
vector<int> graph[1001];

bool visit[1001];
int N, M, cnt;
void dfs(int node) {
	stack<int> s;
	s.push(node);
	while (!s.empty()) {
		int cur = s.top(); s.pop();
		visit[cur] = true;
		for (int a : graph[cur]) {
			if (visit[a])continue;
			s.push(a);
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);

	for (int i = 0, from, to; i < M; i++) {
		scanf("%d%d", &from, &to);
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d", cnt);
}

//#include <cstdio>
//#include <queue>
//#include <vector>
//using namespace std;
//
//vector<int> graph[1001];
//bool visit[1001];
//int N, M;
//
//void bfs(int n) {
//	queue<int> q;
//	visit[n] = true;
//	q.push(n);
//	while (!q.empty()) {
//		int t = q.front(); q.pop();
//		for (int a : graph[t]) {
//			if (visit[a])continue;
//			visit[a] = true;
//			q.push(a);
//		}
//	}
//}
//
//int main() {
//	int cnt = 0;
//	scanf("%d%d", &N, &M);
//
//	for (int i = 0, from, to; i < M; i++) {
//		scanf("%d%d", &from, &to);
//		graph[from].push_back(to);
//		graph[to].push_back(from);
//	}
//	for (int i = 1; i <= N; i++) {
//		if (!visit[i]) {
//			bfs(i);
//			cnt++;
//		}
//	}
//	printf("%d", cnt);
//
//	return 0;
//}