#include <cstdio>
#include <cstring>
using namespace std;
int tc, T,n,graph[100001];
int visit[100001];
bool dfs(int cur,int k) {
	if (visit[cur] == k)return 1;

	dfs(graph[cur], k);
}
int main() {
	scanf("%d", &tc);
	for (int T = 1; T <= tc; T++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &graph[i]);
	}
}