#include <cstdio>
#include <vector>
using namespace std;

typedef struct disjointSet {
	vector<int> parent, rank;

	disjointSet(int n) {
		rank = vector<int>(n + 1);
		for (int i = 0; i <= n; i++)
			parent.push_back(i);
	}

	int find(int x) {
		if (parent[x] == x)return x;
		else return parent[x] = find(parent[x]);
	}

	void unionSet(int x, int y) {
		x = find(x);
		y = find(y);
		int temp;

		if (x == y)return;

		if (rank[x] > rank[y]) {
			temp = x;
			x = y;
			y = temp;
		}
		parent[x] = y;
		if (rank[x] == rank[y])++rank[y];
	}
}disjointSet;

int n, m, k, ans;
vector<int> v;
vector<vector<int>> party;

int main() {
	scanf("%d%d", &n, &m);
	scanf("%d", &k);
	for (int i = 0,num; i < k; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}

	disjointSet ds(n);
	for (int t = 0,a,b; t < m; t++) {
		scanf("%d", &a);
		party.push_back(vector<int>(a));

		for (int i = 0; i < a; i++)
			scanf("%d", &party.back()[i]);

		for (int i = 0; i < party.back().size(); i++)
			for (int j = i + 1; j < party.back().size(); j++)
				ds.unionSet(party.back()[i], party.back()[j]);
	}

	for (auto p : party) {
		bool b = true;
		for (auto y : p)
			for (auto x : v)
				if (ds.find(x) == ds.find(y))b = false;
		if (b)ans++;
	}
	printf("%d", ans);
	return 0;
}