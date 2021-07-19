#include <cstdio>
#include <vector>
using namespace std;
struct disjointSet {
	vector<int> parent, rank;

	disjointSet(int n) {
		rank.resize(n + 1);
		for (int i = 0; i <= n; i++)
			parent.push_back(i);
	}

	int find(int x) {
		if (parent[x] == x)return x;
		return parent[x] = find(parent[x]);
	}

	void unionSet(int u, int v) {
		u = find(u); v = find(v);
		int temp;

		if (u == v)return;
		if (rank[u] > rank[v]) { temp = u; u = v; v = temp; }
		parent[u] = v;
		if (rank[u] == rank[v])++rank[v];
	}
};
int n,m,p;
int main() {
	scanf("%d%d", &n,&m);
	disjointSet d(n);

	for(int i=1;i<=n;i++)
		for (int j = 1,k; j <= n; j++) {
			scanf("%d", &k);
			if (!k)continue;
			if (d.find(i) != d.find(j))
				d.unionSet(i, j);
		}
	scanf("%d", &p); p = d.find(p);
	for (int i = 0,k; i < m-1; i++) {
		scanf("%d", &k);
		if (d.find(k) != p) { printf("NO"); return 0; }
	}
	printf("YES");
	return 0;
}